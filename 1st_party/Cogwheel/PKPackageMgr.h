#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include "LDChunk.h"

inline uint16_t Swap16(uint16_t val) {
    return (val << 8) | (val >> 8);
}

enum GoliathGame {
    MonstersVsAliens = 0,
    TheBeeMovie = 1,
    Chronicles = 2, // same pak structure as SD
    ShatteredDimensions = 3,
    EdgeOfTime = 4,
    TheAmazingSpiderMan1 = 5,
    TheAmazingSpiderMan2 = 6,
    SuperChargersRacing = 7
};

inline const char* GoliathGameToString(GoliathGame game)
{
    switch (game)
    {
    case GoliathGame::MonstersVsAliens: return "Monsters Vs Aliens";
    case GoliathGame::TheBeeMovie: return "The Bee Movie";
    case GoliathGame::ShatteredDimensions: return "Spider-Man: Shattered Dimensions";
    case GoliathGame::Chronicles: return "Spider-Man: Chronicles (Shattered Dimensions Prototype)";
    case GoliathGame::EdgeOfTime: return "Spider-Man: Edge Of Time";
    case GoliathGame::TheAmazingSpiderMan1: return "The Amazing Spider-Man";
    case GoliathGame::TheAmazingSpiderMan2: return "The Amazing Spider-Man 2";
    case GoliathGame::SuperChargersRacing: return "Skylanders: SuperChargers Racing";
    default: return "Unknown";
    }
}

inline bool Check64BitGame(GoliathGame goliathGame)
{
    switch (goliathGame) {
        case MonstersVsAliens:
            return false; // 32-bit
        case TheBeeMovie:
            return false; // 32-bit
        case ShatteredDimensions:
            return false; // 32-bit
        case Chronicles:
            return false; // 32-bit
        case EdgeOfTime:
            return false; // 32-bit
        case TheAmazingSpiderMan1:
            return false; // 32-bit
        case TheAmazingSpiderMan2:
            return true; // 64-bit
        case SuperChargersRacing:
            return true; // 64-bit
    }
}

inline uint32_t Swap32(uint32_t val) {
    return ((val & 0xFF) << 24) |
        ((val & 0xFF00) << 8) |
        ((val & 0xFF0000) >> 8) |
        ((val & 0xFF000000) >> 24);
}

inline uint64_t Swap64(uint64_t val) {
    return ((val & 0xFFULL) << 56) |
        ((val & 0xFF00ULL) << 40) |
        ((val & 0xFF0000ULL) << 24) |
        ((val & 0xFF000000ULL) << 8) |
        ((val & 0xFF00000000ULL) >> 8) |
        ((val & 0xFF0000000000ULL) >> 24) |
        ((val & 0xFF000000000000ULL) >> 40) |
        ((val & 0xFF00000000000000ULL) >> 56);
}

inline uint16_t ReadUInt16(std::ifstream& file, bool isBigEndian) {
    uint16_t val = 0;
    file.read(reinterpret_cast<char*>(&val), sizeof(val));
    if (isBigEndian) val = Swap16(val);
    return val;
}

inline uint32_t ReadUInt32(std::ifstream& file, bool isBigEndian) {
    uint32_t val = 0;
    file.read(reinterpret_cast<char*>(&val), sizeof(val));
    if (isBigEndian) val = Swap32(val);
    return val;
}

inline uint64_t ReadUInt64(std::ifstream& file, bool isBigEndian) {
    uint64_t val = 0;
    file.read(reinterpret_cast<char*>(&val), sizeof(val));
    if (isBigEndian) val = Swap64(val);
    return val;
}

inline CMChunkType MaskChunkType(uint32_t rawType)
{

    uint32_t masked = rawType & 0x00FFFFFF;
    return static_cast<CMChunkType>(masked);
}

class PKPackageMgr
{
public:
    std::vector<LDChunk> chunks;
    bool is64bit = false;
    bool isBigEndian = false;
    GoliathGame lastOpenedGame;
    ConsoleType lastOpenedPlatform;

    int chunkSize = 16;

    bool ReadFile(const std::string& filename)
    {
        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return false;
        }

        file.seekg(0, std::ios::end);
        uint64_t fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        if (fileSize == 0) {
            std::cerr << "File is empty!" << std::endl;
            return false;
        }

        // Read first two bytes to determine endianness
        uint8_t byte1 = 0, byte2 = 0;
        file.read(reinterpret_cast<char*>(&byte1), 1);
        file.read(reinterpret_cast<char*>(&byte2), 1);

        if (is64bit)
        {
            chunkSize = 16;
            if (byte1 == 0x80 && byte2 == 0x00) {
                isBigEndian = true;
            }
            else {
                isBigEndian = false;
            }
        }
        else
        {
            chunkSize = 12;
            if (byte1 == 0x00 && byte2 == 0x00) {
                isBigEndian = true;
            }
            else {
                isBigEndian = false;
            }
        }

        // Reset stream to start to read chunks from offset 0
        file.seekg(0, std::ios::beg);

        ReadChunks(file, 0, fileSize, chunks);

        file.close();
        return true;
    }

private:
    void ReadChunks(std::ifstream& file, uint64_t startOffset, uint64_t maxOffset,
        std::vector<LDChunk>& outChunks, int depth = 0)
    {
        if (depth > 1024) {
            std::cerr << "Max recursion depth reached at offset " << startOffset << std::endl;
            return;
        }

        uint64_t offset = startOffset;

        while (offset + chunkSize <= maxOffset && file)
        {
            file.seekg(offset, std::ios::beg);

            uint32_t rawType = ReadUInt32(file, isBigEndian);
            uint16_t version;
            uint16_t hasChildren;
            version = ReadUInt16(file, isBigEndian);
            hasChildren = ReadUInt16(file, isBigEndian);
            if (is64bit)
            {
                ReadUInt32(file, isBigEndian);
            }
            uint32_t length = ReadUInt32(file, isBigEndian);
            LDChunk chunk(MaskChunkType(rawType), version, hasChildren != 0, length, offset);
            chunk.platform = lastOpenedPlatform;

            std::cerr << std::string(depth * 2, ' ')
                << "Chunk at offset " << offset
                << " type=" << (int)chunk.type
                << " len=" << chunk.length
                << " children=" << chunk.hasChildren
                << std::endl;

            offset += chunkSize;

            if (chunk.hasChildren && chunk.length > 0)
            {
                uint64_t childrenEnd = offset + chunk.length;
                if (childrenEnd > maxOffset) childrenEnd = maxOffset;

                ReadChunks(file, offset, childrenEnd, chunk.children, depth + 1);

                offset = childrenEnd;
            }
            else if (chunk.length > 0)
            {

                chunk.data.resize(static_cast<size_t>(chunk.length));
                file.seekg(offset, std::ios::beg);
                file.read(reinterpret_cast<char*>(chunk.data.data()), chunk.length);

                offset += chunk.length;
            }

            outChunks.push_back(chunk);
        }
    }
};