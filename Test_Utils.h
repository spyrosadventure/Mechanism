#pragma once
#include <glm/glm.hpp>

inline LDChunk* FindChild(LDChunk& root, CMChunkType t)
{
    for (auto& c : root.children)
        if (c.type == t)
            return &c;
    return nullptr;
}

inline std::vector<LDChunk*> FindChildren(LDChunk& root, CMChunkType t)
{
    std::vector<LDChunk*> out;
    for (auto& c : root.children)
        if (c.type == t)
            out.push_back(&c);
    return out;
}

inline LDChunk* FindChunkByOffset(PKPackageMgr& pkg, uint32_t absOffset)
{
    for (auto& c : pkg.chunks)
        if (c.offset == absOffset)
            return &c;
    return nullptr;
}

struct ExtractedMesh {
    uint32_t stride;
    uint32_t vertexCount;
    std::vector<glm::vec3> vertices;
};

struct ExtractedMeshes {
    ExtractedMesh mesh0;
    ExtractedMesh mesh1;
    ExtractedMesh mesh2;
    ExtractedMesh mesh3;
};

void ExportSpidermanOBJ(const ExtractedMeshes& m, const std::string& folderPath)
{
    namespace fs = std::filesystem;
    const std::vector<std::pair<std::string, const ExtractedMesh*>> meshes = {
        {"Mesh0", &m.mesh0},
        {"Mesh1", &m.mesh1},
        {"Mesh2", &m.mesh2},
        {"Mesh3", &m.mesh3}
    };

    for (auto& [name, mesh] : meshes)
    {
        fs::path path = fs::path(folderPath) / (name + ".obj");
        std::ofstream out(path.string());
        if (!out.is_open()) continue;

        out << "o " << name << "\n";
        out << "g " << name << "\n";

        for (auto& v : mesh->vertices)
            out << "v " << v.x << " " << v.y << " " << v.z << "\n";

        out.close();
    }

}

static LDChunk* FindChunkRecursive(LDChunk* node, CMChunkType type)
{
    if (!node) return nullptr;
    if (node->type == type) return node;

    for (auto& c : node->children)
    {
        LDChunk* found = FindChunkRecursive(&c, type);
        if (found) return found;
    }
    return nullptr;

}

static LDChunk* FindChunkRecursiveInPackage(PKPackageMgr& pkg, CMChunkType type)
{
    for (auto& top : pkg.chunks)
    {
        LDChunk* found = FindChunkRecursive(&top, type);
        if (found) return found;
    }
    return nullptr;
}

static void FindChildrenRecursive(LDChunk* node, CMChunkType type, std::vector<LDChunk*>& out)
{
    if (!node) return;
    for (auto& c : node->children)
    {
        if (c.type == type) out.push_back(&c);
        FindChildrenRecursive(&c, type, out);
    }
}

LDChunk* FindChunkByOffsetRecursive(LDChunk* node, uint32_t absOffset)
{
    if (!node) return nullptr;
    if (node->offset == absOffset) return node;

    for (auto& c : node->children)
    {
        LDChunk* found = FindChunkByOffsetRecursive(&c, absOffset);
        if (found) return found;
    }
    return nullptr;

}

ExtractedMeshes ExportSpidermanMeshes(PKPackageMgr& pkg)
{
    ExtractedMeshes out{};
    std::cout << "[Info] Starting ExportSpidermanMeshes\n";

    LDChunk* root = FindChunkRecursiveInPackage(pkg, CMChunkType::Root);
    if (!root) throw std::runtime_error("No Root chunk found.");

    LDChunk* resLib = FindChunkRecursive(root, CMChunkType::Gen_GeometryLibrary);
    if (!resLib) throw std::runtime_error("No Gen_GeometryLibrary found.");

    std::vector<LDChunk*> allResources;
    FindChildrenRecursive(resLib, CMChunkType::GenSub_Resource, allResources);

    LDChunk* spideyRes = nullptr;
    GoliathGame game = GoliathGame::Chronicles;

    for (auto* r : allResources)
    {
        LDChunk* header = FindChild(*r, CMChunkType::GenSub_ResourceHeader);
        if (!header || header->data.empty()) continue;

        std::string resourceName;
        if (game >= 6 && header->data.size() >= 0x1C + 0x40)
        {
            const uint8_t* strStart = header->data.data() + 0x1C;
            size_t len = 0; while (len < 0x40 && strStart[len] != 0) len++;
            resourceName = std::string(reinterpret_cast<const char*>(strStart), len);
        }
        else if (header->data.size() >= 0x18 + 0x40)
        {
            const uint8_t* strStart = header->data.data() + 0x18;
            size_t len = 0; while (len < 0x40 && strStart[len] != 0) len++;
            resourceName = std::string(reinterpret_cast<const char*>(strStart), len);
        }
        else
        {
            resourceName = "Failed To Read Resource Name!";
        }

        if (resourceName == "Spiderman2099")
        {
            spideyRes = r;
            break;
        }
    }

    if (!spideyRes) throw std::runtime_error("Resource 'Spiderman2099' not found.");
    std::cout << "[Info] Found Spiderman2099 resource.\n";

    LDChunk* header = FindChild(*spideyRes, CMChunkType::GenSub_ResourceHeader);
    if (!header || header->data.size() < 0x10)
        throw std::runtime_error("Spiderman2099 has invalid GenSub_ResourceHeader.");

    uint32_t dataOffset = *reinterpret_cast<const uint32_t*>(&header->data[0x10]);
    if (pkg.isBigEndian) dataOffset = Swap32(dataOffset);

    LDChunk* geomLOD = FindChunkRecursive(spideyRes, CMChunkType::Geo_GeomLOD);
    if (!geomLOD) throw std::runtime_error("Spiderman2099 Geo_GeomLOD not found.");

    std::vector<LDChunk*> meshes = FindChildren(*geomLOD, CMChunkType::Geo_GeomMesh);
    if (meshes.size() < 4) FindChildrenRecursive(geomLOD, CMChunkType::Geo_GeomMesh, meshes);
    if (meshes.size() < 4) throw std::runtime_error("Expected 4 Geo_GeomMesh children.");

    auto parseMeshHeader = [&](LDChunk* m, ExtractedMesh& outMesh, const char* label)
        {
            if (!m || m->data.size() < 0x10) throw std::runtime_error("Invalid mesh chunk.");
            uint32_t stride = *reinterpret_cast<const uint32_t*>(&m->data[0x08]);
            uint32_t vcount = *reinterpret_cast<const uint32_t*>(&m->data[0x10]);
            if (pkg.isBigEndian) { stride = Swap32(stride); vcount = Swap32(vcount); }
            outMesh.stride = stride; outMesh.vertexCount = vcount;
            std::cout << "[Mesh Header] " << label << " stride=" << stride << " vertexCount=" << vcount << "\n";
        };

    std::cout << dataOffset << "\n";

    parseMeshHeader(meshes[0], out.mesh0, "Mesh0");
    parseMeshHeader(meshes[1], out.mesh1, "Mesh1");
    parseMeshHeader(meshes[2], out.mesh2, "Mesh2");
    parseMeshHeader(meshes[3], out.mesh3, "Mesh3");

    LDChunk* offsetChunk = FindChunkByOffsetRecursive(root, dataOffset);
    if (!offsetChunk) throw std::runtime_error("Offset chunk not found.");

    LDChunk* lod2 = FindChunkRecursive(offsetChunk, CMChunkType::Geo_GeomLOD);
    if (!lod2) throw std::runtime_error("Second Geo_GeomLOD not found under offset chunk.");

    LDChunk* vertexList = FindChunkRecursive(lod2, CMChunkType::GenSub_VertexList);
    if (!vertexList || vertexList->data.size() < 4)
        throw std::runtime_error("GenSub_VertexList not found or too small.");

    const uint8_t* ptr = vertexList->data.data();
    size_t remaining = vertexList->data.size();

    auto readFloat = [&](const uint8_t*& p, size_t& rem) -> float
        {
            if (rem < 4) throw std::runtime_error("Unexpected end of vertex data.");
            uint32_t raw;
            memcpy(&raw, p, 4);

            // Skip 0xAAAAAAAA sentinel values
            while (raw == 0xAAAAAAAA)
            {
                p += 4;
                rem -= 4;
                if (rem < 4) throw std::runtime_error("Unexpected end of vertex data after skipping AAAAAAAA.");
                memcpy(&raw, p, 4);
            }

            p += 4;
            rem -= 4;

            float f;
            memcpy(&f, &raw, 4);
            if (pkg.isBigEndian)
            {
                uint32_t tmp = Swap32(*reinterpret_cast<uint32_t*>(&f));
                memcpy(&f, &tmp, 4);
            }
            return f;

        };

    auto readMeshData = [&](ExtractedMesh& mesh, const char* label)
        {
            mesh.vertices.clear(); mesh.vertices.reserve(mesh.vertexCount);
            for (uint32_t i = 0; i < mesh.vertexCount; ++i)
            {
                float x = readFloat(ptr, remaining);
                float y = readFloat(ptr, remaining);
                float z = readFloat(ptr, remaining);
                mesh.vertices.emplace_back(x, y, z);
                if (mesh.stride < 12) throw std::runtime_error("Invalid mesh stride.");
                if (remaining < mesh.stride - 12) throw std::runtime_error("Unexpected end of vertex data.");
                ptr += mesh.stride - 12; remaining -= mesh.stride - 12;
            }
        };

    readMeshData(out.mesh0, "Mesh0");
    readMeshData(out.mesh1, "Mesh1");
    readMeshData(out.mesh2, "Mesh2");
    readMeshData(out.mesh3, "Mesh3");

    ExportSpidermanOBJ(out, "Z:\\Mechanism");
    return out;

}