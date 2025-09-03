#pragma once
#include <vector>
#include <cstdint>
#include <string>

enum class CMChunkType : uint32_t {
    Invalid = 0,
    Root = 0x1,
    Gen_OctreeRender = 0x2,
    Gen_OctreeCollision = 0x3,
    Gen_GameObjLibrary = 0x4,
    Gen_HierarchyLibrary = 0x5,
    Gen_HAnimLibrary = 0x6,
    Gen_GeometryLibrary = 0x7,
    Gen_LogicLibrary = 0x8,
    Gen_TextureLibrary = 0x9,
    Gen_AudioLibrary = 0xa,
    Gen_GraphicsConfig = 0xb,
    Gen_FontLibrary = 0xc,
    Gen_ParticleLibrary = 0xd,
    Gen_LogicLibraryName = 0xe,
    Gen_MovieLibrary = 0xf,
    Gen_ReferencedLevels = 0x10,
    Gen_LevelHeader = 0x11,
    Gen_StringTableLibrary = 0x12,
    Gen_HUDLibrary = 0x13,
    Gen_ResIDToNameTable = 0x14,
    Gen_OcclusionModel = 0x15,
    Gen_BinaryDataLibrary = 0x16,
    Gen_ReflectionSourceLibrary_REMOVED = 0x17,
    Gen_FoliageLibrary = 0x18,
    Gen_Languages = 0x19,
    Gen_ExportContext = 0x1a,
    Gen_CutSceneLibrary = 0x1b,
    Gen_AudioSoundLibrary = 0x1c,
    Gen_AudioCueLibrary = 0x1d,
    Gen_AudioSampleLibrary = 0x1e,
    Gen_AudioCategoryLibrary = 0x1f,
    Gen_AudioRPCLibrary = 0x20,
    Gen_AudioSampleBankLibrary = 0x21,
    Gen_MaterialAnimLibrary = 0x22,
    Gen_GameLogicHeader = 0x23,
    Gen_MotionTrailLibrary = 0x24,
    Gen_LODDistances = 0x25,
    Gen_PostLoadData = 0x26,
    Gen_BSplineLibrary_REMOVED = 0x27,
    Gen_ZoneLibrary_REMOVED = 0x28,
    Gen_Constants = 0x29,
    Gen_ResTable = 0x2a,
    Gen_BillboardLibrary = 0x2b,
    Gen_OctreeSoundOcclusion = 0x2c,
    Gen_HAnimProcLibrary = 0x2d,
    Gen_LightGridLibrary_DEPRECATED = 0x2e,
    Gen_PackageSizes = 0x2f,
    Gen_EnvironmentLibrary = 0x30,
    Gen_UnusedLibrary = 0x31,
    Gen_ParamBlockLibrary = 0x32,
    Gen_AudioReverbLibrary = 0x33,
    Gen_AnimCueLibrary = 0x34,
    Gen_AnimTreeLibrary = 0x35,
    Gen_TextStyleLibrary = 0x36,
    Gen_AnimationGraphLibrary_REMOVED = 0x37,
    Gen_PackagesInfo = 0x38,
    Gen_CurveLibrary = 0x39,
    Gen_ResourcesListLibrary = 0x3a,
    Gen_CityLibrary = 0x3b,
    Gen_Streamable = 0x3c,
    Gen_Cachable = 0x3d,
    Gen_CityBlockLibrary = 0x3e,
    Gen_ParamTreeLibrary = 0x3f,
    Gen_ParamGraphLibrary = 0x40,
    Gen_ParamBlockNameTable = 0x41,
    Gen_AudioInterleavedStreamsLibrary = 0x42,
    Gen_Hud3dLibrary = 0x43,
    Gen_WwiseAudioLibrary = 0x44,
    Gen_HeightMapLibrary = 0x45,
    Gen_DecalLibrary = 0x46,
    Gen_DecalInstanceLibrary = 0x47,
    Gen_WwiseAudioCutsceneLibrary = 0x48,
    Gen_WwiseMediaLibrary = 0x49,
    Gen_SequenceLibrary = 0x4a,
    Gen_TextureHiMips = 0x4b,
    Gen_Count = 0x4c,
    GenSub_VertexList = 0x1388,
    GenSub_IndexList = 0x1389,
    GenSub_TriangleIndexList = 0x138a,
    GenSub_TriangleCenterList = 0x138b,
    GenSub_TextureNamesTable = 0x138c,
    GenSub_Resource = 0x138d,
    GenSub_ResourceHeader = 0x138e,
    GenSub_ResourceIncrementalInfo = 0x138f,
    GenSub_SubVertexList = 0x1390,
    GenSub_ParamBlock = 0x1391,
    GenSub_ConstantDefs = 0x1392,
    GenSub_ConstantHeader = 0x1393,
    GenSub_ResList = 0x1394,
    GenSub_CubeMap = 0x1395,
    GenSub_VertexBufferArray = 0x1396,
    GenSub_VertexBufferArrayHeader = 0x1397,
    GenSub_IndexBufferArray = 0x1398,
    GenSub_IndexBufferArrayHeader = 0x1399,
    GenSub_Info = 0x139a,
    GenSub_LibPreloadList = 0x139b,
    GenSub_RefResourceArray = 0x139c,
    GenSub_Buffers = 0x139d,
    GenSub_Buffers_Info = 0x139e,
    GenSub_ParamBlockData_DEPRECATED = 0x139f,
    GenSub_ParamBlockPatchTable_DEPRECATED = 0x13a0,
    GenSub_VarParamBlock = 0x13a1,
    Octree_NodeList = 0x64,
    Octree_InfoHeader = 0x65,
    Octree_Shadow = 0x66,
    Octree_ShadowData = 0x67,
    Octree_ShadowInfo = 0x68,
    Octree_ShadowObject = 0x69,
    Octree_ShadowObjectData = 0x6a,
    Octree_ShadowObjectInfo = 0x6b,
    Octree_ShadowVolumes = 0x6c,
    Octree_Info = 0x6d,
    RenderOctree_PrimList = 0xc8,
    RenderOctree_OcclusionPrims = 0xc9,
    RenderOctree_MaterialList = 0xca,
    RenderOctree_PrimIdx = 0xcb,
    RenderOctree_Prims = 0xcc,
    RenderOctree_TransCenters_REMOVED = 0xcd,
    RenderOctree_Obj = 0xce,
    RenderOctree_InstanceIdx = 0xcf,
    RenderOctree_Instances = 0xd0,
    RenderOctree_MaterialListHeader = 0xd1,
    RenderOctree_InstancesSpecificData = 0xd2,
    RenderOctree_InstancesSpecificDataUV = 0xd3,
    RenderOctree_ReflectionPlaneList = 0xd4,
    RenderOctree_EdgesLinesStrips = 0xd5,
    RenderOctree_EdgesLinesStripsIdx = 0xd6,
    RenderOctree_PrimsBufferIndices = 0xd7,
    RenderOctree_ObjBufferIndices = 0xd8,
    RenderOctree_Header = 0xd9,
    RenderOctree_EnlightenSystemMaterials = 0xda,
    COctree_Info = 0x12c,
    COctree_Data = 0x12d,
    COctree_AIPath = 0x12e,
    Texture_LibraryHeader = 0x190,
    Texture = 0x191,
    Logic_NameList = 0x192,
    Texture_IDList = 0x193,
    Texture_Header = 0x194,
    Texture_Data = 0x195,
    Texture_Format = 0x196,
    Texture_PreLoadData = 0x197,
    Texture_HiMips = 0x198,
    GO_Header = 0x1f4,
    GO_Info = 0x1f5,
    GO_Logic = 0x1f6,
    GO_Physic = 0x1f7,
    GO_Light = 0x1f8,
    GO_Camera = 0x1f9,
    GO_Emitter = 0x1fa,
    GO_3dObject = 0x1fb,
    GO_DebugInfo = 0x1fc,
    GO_ColPrimInfo = 0x1fd,
    GO_MotionTrail = 0x1fe,
    GO_Type = 0x1ff,
    GO_Type_Info = 0x200,
    GO_Emitter_Emission = 0x201,
    GO_Emitter_Field = 0x202,
    GO_Physic_Info = 0x203,
    Logic_CodeLibInfo = 0x258,
    Logic_CodeHeader = 0x259,
    Logic_CodeHeaderInfo = 0x25a,
    Logic_CodeFileHeader = 0x25b,
    Logic_CodeFileInfo = 0x25c,
    Logic_Code = 0x25d,
    Logic_CodeData = 0x25e,
    Logic_CodeReloc = 0x25f,
    Logic_CodeSymbols = 0x260,
    Logic_CodeSymbolsNames = 0x261,
    Logic_CodeDLLInfo = 0x262,
    Logic_CodeStringTable = 0x263,
    Logic_CodeRelModule = 0x264,
    Logic_Resource = 0x265,
    Logic_CodeRsoModule = 0x266,
    Logic_FrequencyParams = 0x267,
    Logic_CodeRsoModuleList = 0x268,
    Logic_CodeRsoModuleListHeader = 0x269,
    Font_Header = 0x2bc,
    Font_Info = 0x2bd,
    Font_Data = 0x2be,
    Font_TextureData = 0x2bf,
    Geo_Model = 0x320,
    Geo_Geometry = 0x321,
    Geo_GeomInfo = 0x322,
    Geo_GeomTextureNames = 0x323,
    Geo_Material = 0x324,
    Geo_GeomLOD = 0x325,
    Geo_GeomLODInfo = 0x326,
    Geo_GeomMesh = 0x327,
    Geo_MorphTarget_UNUSED = 0x328,
    Geo_MorphTargetMesh_UNUSED = 0x329,
    Geo_GeometryLibHeader = 0x32a,
    Geo_MeshSkinData_UNUSED = 0x32b,
    Geo_GeomMeshInfo_UNUSED = 0x32c,
    Geo_ShadowVolumeData_UNUSED = 0x32d,
    Geo_Morph = 0x32e,
    Geo_MorphMap_UNUSED = 0x32f,
    Geo_MaterialHeader = 0x330,
    Geo_MaterialInfo = 0x331,
    Geo_MorphNames_UNUSED = 0x332,
    Geo_MorphMixResMap_UNUSED = 0x333,
    Geo_SubModels = 0x334,
    Geo_MorphCRC = 0x335,
    Geo_SBMeshData = 0x336,
    Geo_LODSkinningRLE = 0x337,
    Geo_MaterialContext = 0x338,
    Geo_MaterialCRC = 0x339,
    Geo_BoneToSkinningBoneTable = 0x33a,
    Geo_TextureCRC = 0x33b,
    Geo_MaterialTechniquesHeader = 0x33c,
    Geo_MaterialTechniques = 0x33d,
    Geo_ProcTex = 0x33e,
    GeoSub_RLESkinningData = 0x1770,
    GeoSub_LODVtxData = 0x1771,
    Hierarchy = 0x384,
    Hierarchy_Bones = 0x385,
    Hierarchy_Anims = 0x386,
    Hierarchy_Collision = 0x387,
    Hierarchy_LibHeader = 0x388,
    Hierarchy_BonesTRS = 0x389,
    Hierarchy_BlendWeights = 0x38a,
    Hierarchy_BoneNames = 0x38b,
    Hierarchy_ColPrimNames = 0x38c,
    Hierarchy_Ragdoll = 0x38d,
    Hierarchy_RagdollNames = 0x38e,
    Hierarchy_BoneConstraints = 0x38f,
    Hierarchy_Info = 0x390,
    Audio_LibraryHeader = 0x3e8,
    Audio_CueLibrary = 0x3e9,
    Audio_Cue = 0x3ea,
    Audio_SoundLibrary = 0x3eb,
    Audio_Sound = 0x3ec,
    Audio_SoundHeader = 0x3ed,
    Audio_Track = 0x3ee,
    Audio_TrackHeader = 0x3ef,
    Audio_EventPlay = 0x3f0,
    Audio_EventStop = 0x3f1,
    Audio_EventVolume = 0x3f2,
    Audio_EventPitch = 0x3f3,
    Audio_EventMarker = 0x3f4,
    Audio_RPCIDs = 0x3f5,
    Audio_SampleLibrary = 0x3f6,
    Audio_Sample = 0x3f7,
    Audio_CategoryLibrary = 0x3f8,
    Audio_Category = 0x3f9,
    Audio_RPCLibrary = 0x3fa,
    Audio_RPC = 0x3fb,
    Audio_RPCHeader = 0x3fc,
    Audio_RPCCurve = 0x3fd,
    Audio_SampleBankLibrary = 0x3fe,
    Audio_SampleBank = 0x3ff,
    Audio_SampleSubtitles = 0x400,
    Audio_SampleData = 0x401,
    Audio_ReverbSettings = 0x402,
    Audio_SampleSeekTable = 0x403,
    Audio_InterleavedStreams = 0x404,
    Particle_Resource = 0x44c,
    Particle_Info = 0x44d,
    Particle_Anim = 0x44e,
    HAnim_Header = 0x4b0,
    HAnim_Resource = 0x4b1,
    HAnim_Info = 0x4b2,
    HAnim_LibHeader = 0x4b3,
    HAnim_BoneTable = 0x4b4,
    HAnim_BlendInfo = 0x4b5,
    HAnim_Events = 0x4b6,
    HAnim_BufferTimeTable = 0x4b7,
    HAnim_EventsHeader = 0x4b8,
    HAnim_MorphCRC = 0x4b9,
    HAnim_Timings = 0x4ba,
    HAnim_Skip = 0x4bb,
    HAnim_BoneCRC = 0x4bc,
    TextureAnim_Header = 0x514,
    TextureAnim_Info = 0x515,
    TextureAnim_Resource = 0x516,
    TextureAnim_LibHeader = 0x517,
    Movie_LibraryHeader = 0x578,
    Movie = 0x579,
    StringTable = 0x5dc,
    StringTable_Header = 0x5dd,
    StringTable_Lib = 0x5de,
    StringTable_LibHeader = 0x5df,
    StringTable_Entry = 0x5e0,
    StringTable_Data = 0x5e1,
    CustomParamStringTable = 0x5e2,
    HUD = 0x640,
    HUD_Window = 0x641,
    HUD_WindowHeader = 0x642,
    HUD_TextWindow = 0x643,
    HUD_2DWindow = 0x644,
    HUD_3DWindow = 0x645,
    GOEmitterField_Base = 0x6a4,
    GOEmitterField_Gravity = 0x6a5,
    GOEmitterField_Fan = 0x6a6,
    GOEmitterField_Drag = 0x6a7,
    GOEmitterField_Radial = 0x6a8,
    GOEmitterField_Vortex = 0x6a9,
    BinaryData_LibraryHeader = 0x708,
    BinaryData_Header = 0x709,
    BinaryData_Info = 0x70a,
    BinaryData_Data = 0x70b,
    PackageInfo = 0x76c,
    PackageInfoHeader = 0x76d,
    Foliage_LibraryHeader = 0x7d0,
    Foliage_WorldLibrary = 0x7d1,
    Foliage_World = 0x7d2,
    Foliage_LocalLibrary = 0x7d3,
    Foliage_Local = 0x7d4,
    Foliage_InstanceLibrary = 0x7d5,
    Foliage_Instance = 0x7d6,
    CutScene_LibraryHeader = 0x834,
    CutScene = 0x835,
    CutScene_Header = 0x836,
    CutScene_Data = 0x837,
    CutScene_PostLoadHeader = 0x838,
    CutScene_Audio = 0x866,
    CutScene_Audio_SampleHeader = 0x867,
    CutScene_Audio_SampleData = 0x868,
    MaterialAnim_LibraryHeader = 0x898,
    MaterialAnim = 0x899,
    MaterialAnim_Header = 0x89a,
    MaterialAnim_Channel = 0x89b,
    MaterialAnim_ChannelInfo = 0x89c,
    MaterialAnim_Data = 0x89d,
    MaterialAnim_Names = 0x89e,
    Logic_HeaderData = 0x89f,
    MotionTrail_LibraryHeader = 0x8fc,
    MotionTrail = 0x8fd,
    OcclusionData = 0x960,
    OcclusionCRC = 0x961,
    BSpline_LibraryHeader = 0x9c4,
    BSpline = 0x9c5,
    BSpline_Info = 0x9c6,
    BSpline_Node = 0x9c7,
    BSpline_NodeInfo = 0x9c8,
    Zone_LibraryHeader_UNUSED = 0xa28,
    Zone_UNUSED = 0xa29,
    Zone_Info_UNUSED = 0xa2a,
    Zone_Logic_UNUSED = 0xa2b,
    Zone_CubeMap = 0xa2c,
    Zone_CubeMapInfo = 0xa2d,
    Billboard_Resource = 0xa8c,
    SoundOctree_Info = 0xaf0,
    SoundOctree_Data = 0xaf1,
    SoundOctree_Graph = 0xaf2,
    HAnimProc_Data = 0xb54,
    LightGrid_Library_DEPRECATED = 0xbb8,
    LightGrid_DEPRECATED = 0xbb9,
    Env_LibraryHeader = 0xbba,
    Env_Render = 0xbbb,
    Env_Collision = 0xbbc,
    Env_Occlusion = 0xbbd,
    Env_SoundOcclusion = 0xbbe,
    Env_NavMesh = 0xbbf,
    Env_NavMesh_Data = 0xbc0,
    Env_NavMesh_FaceDataTable = 0xbc1,
    Env_NavMesh_FaceData = 0xbc2,
    Env_NavMesh_Octree = 0xbc3,
    Env_EnlightenScene = 0xbc4,
    LightGrid_Group = 0xbea,
    LightGrid_GroupHeader = 0xbeb,
    LightGrid = 0xbec,
    Anim_BaseTree_LibraryHeader = 0xc1c,
    Anim_BaseTree = 0xc1d,
    Anim_BaseTree_Header = 0xc1e,
    Anim_BaseTree_Leaves = 0xc1f,
    Anim_BaseTree_Blenders = 0xc20,
    Anim_BaseTree_Children = 0xc21,
    Anim_BaseTree_Names = 0xc22,
    ParamBlock_Header = 0xc80,
    ParamBlock_Data = 0xc81,
    ParamBlock_Transform = 0xc82,
    TextStyle_Header = 0xce4,
    TextStyle_Info = 0xce5,
    Anim_Cue_LibraryHeader = 0xd48,
    Anim_Cue = 0xd49,
    Anim_Cue_Header = 0xd4a,
    Anim_Cue_In = 0xd4b,
    Anim_Cue_Loop = 0xd4c,
    Anim_Cue_Out = 0xd4d,
    UNUSED = 0xdac,
    Curve = 0xe10,
    Curve_Info = 0xe11,
    Curve_Sample = 0xe12,
    Curve_Node = 0xe13,
    Curve_Node_Info = 0xe14,
    ResourcesList = 0xe74,
    ResourcesList_Info_Deprecated = 0xe75,
    City_Info = 0xed8,
    City_Base_Building_Group = 0xed9,
    City_Building = 0xeda,
    City_Building_Info = 0xedb,
    City_Wall_Group = 0xedc,
    City_Wall_DEPRECATED = 0xedd,
    City_Roof_Group = 0xede,
    City_Roof = 0xedf,
    City_Roof_Info = 0xee0,
    City_Node_Group = 0xee1,
    City_Node = 0xee2,
    City_Node_Info = 0xee3,
    City_Blocks = 0xee4,
    City_Props_Obj = 0xee5,
    City_Low_Node = 0xee6,
    City_Low_Building_Group = 0xee7,
    City_Low_Building = 0xee8,
    City_Low_Building_Info = 0xee9,
    City_Low_Wall_Group = 0xeea,
    City_Low_Wall = 0xeeb,
    City_Low_Wall_Info = 0xeec,
    City_Low_Region_Group = 0xeed,
    City_Low_Region = 0xeee,
    City_Low_Border_Group = 0xeef,
    City_Low_DynamicProps = 0xef0,
    City_Low_Roof_Group = 0xef1,
    City_Low_Roof = 0xef2,
    City_High_Node = 0xef3,
    City_High_Building_Group = 0xef4,
    City_High_Building = 0xef5,
    City_High_Wall_Group = 0xef6,
    City_High_Wall = 0xef7,
    City_High_Region_Group = 0xef8,
    City_High_Region = 0xef9,
    City_High_Region_Info = 0xefa,
    City_High_Block = 0xefb,
    City_High_Block_Info = 0xefc,
    City_Material_Group = 0xefd,
    City_Material_Group_Info = 0xefe,
    City_Low_Region_Info = 0xeff,
    City_Low_Region_LOD1_Meshes = 0xf00,
    City_Low_Region_LOD1_Mesh_Info = 0xf01,
    City_Low_Border = 0xf02,
    City_Low_Border_Info = 0xf03,
    City_Med_CollisionMaterialCRCs = 0xf04,
    City_Med_OcclusionFaceCRCs = 0xf05,
    City_Med_Node = 0xf06,
    City_Med_Building_Group = 0xf07,
    City_Med_Building = 0xf08,
    City_Med_Building_Info = 0xf09,
    City_Med_Wall_Group_DEPRECATED = 0xf0a,
    City_Med_Wall_DEPRECATED = 0xf0b,
    City_Med_Region_Group_DEPRECATED = 0xf0c,
    City_Med_Region_DEPRECATED = 0xf0d,
    City_Med_Region_Info_DEPRECATED = 0xf0e,
    City_Med_Region_LOD1_Meshes_DEPRECATED = 0xf0f,
    City_Med_Region_LOD1_Mesh_Info_DEPRECATED = 0xf10,
    City_Med_Border_Group = 0xf11,
    City_Med_Border = 0xf12,
    City_Med_Border_Info = 0xf13,
    City_Med_Props = 0xf14,
    City_Med_DynamicProps = 0xf15,
    City_TextureCRC_Table = 0xf16,
    City_Med_Roof_Group_Deprecated = 0xf17,
    City_Med_Roof = 0xf18,
    City_Low_Node_Group = 0xf19,
    City_Med_Node_Group = 0xf1a,
    City_High_Node_Group = 0xf1b,
    City_High_Border_Group = 0xf1c,
    City_High_Border = 0xf1d,
    City_High_Border_Info = 0xf1e,
    City_Dynamic_Prop_Library_DEPRECATED = 0xf1f,
    City_Dynamic_Prop_Info = 0xf20,
    City_Dynamic_Prop = 0xf21,
    City_Emissive_Color_Palette = 0xf22,
    City_Med_LOD1_Color_Buffer_DEPRECATED = 0xf23,
    City_Low_TextureCRC_Table_DEPRECATED = 0xf24,
    City_Med_TextureCRC_Table_DEPRECATED = 0xf25,
    City_Node_Material_Group = 0xf26,
    City_Node_Material_Group_Info = 0xf27,
    City_CubeMapZones = 0xf28,
    City_RezRefDataOffset = 0xf29,
    City_Base_Node_Header = 0xf2a,
    City_Low_Node_Header = 0xf2b,
    City_Med_Node_Header = 0xf2c,
    City_High_Node_Header = 0xf2d,
    City_Node_References_DEPRECATED = 0xf2e,
    City_Block_Header = 0xf2f,
    City_Collision_Node_Group_DEPRECATED = 0xf30,
    City_Collision_Node_DEPRECATED = 0xf31,
    City_Collision_Node_Header_DEPRECATED = 0xf32,
    City_HeightMapInfo = 0xf33,
    City_LOD3Root = 0xf34,
    City_LOD3Info = 0xf35,
    City_LOD3BuildingEntries = 0xf36,
    City_LOD3Buffer = 0xf37,
    City_RZCityBlock_Container = 0xf38,
    CityBlock_Info = 0xf3c,
    ParamTree = 0xfa0,
    ParamTree_NodesDesc = 0xfa1,
    ParamTree_NodesData = 0xfa2,
    ParamTree_NodesDataInfo = 0xfa3,
    ParamTree_Names = 0xfa4,
    ParamGraph = 0x1004,
    ParamGraph_Nodes = 0x1005,
    ParamGraph_Edges = 0x1006,
    ParamGraph_Params = 0x1007,
    ParamGraph_ParamsInfo = 0x1008,
    ParamGraph_Names = 0x1009,
    Graph3D = 0x1068,
    Graph3D_Nodes = 0x1069,
    Graph3D_Edges = 0x106a,
    Graph3D_Params = 0x106b,
    Graph3D_ParamsInfo = 0x106c,
    Graph3D_Names = 0x106d,
    Hud3D = 0x10cc,
    Hud3D_BaseInfo = 0x10cd,
    Hud3D_ElemInfo = 0x10ce,
    WwiseSoundBank = 0x1130,
    WwiseSoundBankData = 0x1131,
    WwiseSoundBankHeader = 0x1132,
    WwiseMediaHeader = 0x1133,
    WwiseMediaData = 0x1134,
    WwiseAudioRefHeader = 0x1135,
    HeightMap = 0x1194,
    HeightMap_Info = 0x1195,
    HeightMap_Data = 0x1196,
    HeightMap_Container = 0x1197,
    Streams = 0x11f8,
    StreamsHeader = 0x11f9,
    LocalizedStreamsHeader = 0x11fa,
    StreamsPackages = 0x11fb,
    StreamsPackageHeader = 0x11fc,
    WwiseStreams = 0x11fd,
    WwiseStreamsData = 0x11fe,
    WwiseStreamsExtraHeader = 0x11ff,
    WwiseStreamsWaveData = 0x1200,
    ProjDecal = 0x125c,
    ProjDecal_Data = 0x125d,
    ProjDecalInstance = 0x125e,
    WwiseDebugPackageFileList = 0x12c0,
    WwiseDebugLanguage = 0x12c1,
    WwiseDebugPackage = 0x12c2,
    Sequence = 0x1324,
    Sequence_Header = 0x1325,
    Sequence_TrackList = 0x1326,
    Sequence_Track = 0x1327,
    Sequence_TrackHeader = 0x1328,
    Sequence_TrackNodes = 0x1329,
    Sequence_Params = 0x132a,
    Sequence_ParamsInfo_DEPRECATED = 0x132b,
    Sequence_Names = 0x132c,
    EnlightenScene_Header = 0x13ec,
    EnlightenScene_System = 0x13ed,
    EnlightenScene_ProbeSet = 0x13ee,
    ProbeSet_Group = 0x1450,
    ProbeSet_GroupHeader = 0x1451,
    ProbeSet_Data = 0x1452,
    ProceduralMeshes = 0x14b4,
    ProceduralMeshes_Base_Infos = 0x14b5,
    ProceduralMeshes_Deformation = 0x14b6,
    ProceduralMeshes_Deformation_Header = 0x14b7,
    ProceduralMeshes_Deformation_Data = 0x14b8,
    ProceduralMeshes_GerstnerDeformation_Data = 0x14b9,
    ProceduralMeshes_GerstnerZoneDeformation_Data = 0x14ba,
    ProceduralMeshes_Geometry = 0x14bb,
    ProceduralMeshes_GeometryExtraData = 0x14bc,
    ProceduralMeshes_Material = 0x14bd,
    ProceduralMeshes_IndexBuffer = 0x14be,
    ProceduralMeshes_VertexBuffer = 0x14bf,
    Moodbox = 0x1518,
    Moodbox_Info = 0x1519,
    Moodbox_AmbientLight = 0x151a,
    Moodbox_Fog = 0x151b,
    Moodbox_FXAA = 0x151c,
    Moodbox_HDRBloom = 0x151d,
    Moodbox_SSAO = 0x151e,
    Moodbox_Bokeh = 0x151f,
    Moodbox_Clipping = 0x1520,
    Moodbox_Colorization = 0x1521,
    Moodbox_EnvCubemap = 0x1522,
    Moodbox_GlobalSpecColor = 0x1523,
    Moodbox_Irradiance = 0x1524,
    Moodbox_HeatHaze = 0x1525,
    kCMChunkTypes_Count = 0x1526,
};

inline const char* ChunkTypeToString(CMChunkType typeValue) {
    CMChunkType type = static_cast<CMChunkType>(typeValue);
    switch (type) {
    case CMChunkType::Root: return "Root";
    case CMChunkType::Gen_OctreeRender: return "Gen_OctreeRender";
    case CMChunkType::Gen_OctreeCollision: return "Gen_OctreeCollision";
    case CMChunkType::Gen_GameObjLibrary: return "Gen_GameObjLibrary";
    case CMChunkType::Gen_HierarchyLibrary: return "Gen_HierarchyLibrary";
    case CMChunkType::Gen_HAnimLibrary: return "Gen_HAnimLibrary";
    case CMChunkType::Gen_GeometryLibrary: return "Gen_GeometryLibrary";
    case CMChunkType::Gen_LogicLibrary: return "Gen_LogicLibrary";
    case CMChunkType::Gen_TextureLibrary: return "Gen_TextureLibrary";
    case CMChunkType::Gen_AudioLibrary: return "Gen_AudioLibrary";
    case CMChunkType::Gen_GraphicsConfig: return "Gen_GraphicsConfig";
    case CMChunkType::Gen_FontLibrary: return "Gen_FontLibrary";
    case CMChunkType::Gen_ParticleLibrary: return "Gen_ParticleLibrary";
    case CMChunkType::Gen_LogicLibraryName: return "Gen_LogicLibraryName";
    case CMChunkType::Gen_MovieLibrary: return "Gen_MovieLibrary";
    case CMChunkType::Gen_ReferencedLevels: return "Gen_ReferencedLevels";
    case CMChunkType::Gen_LevelHeader: return "Gen_LevelHeader";
    case CMChunkType::Gen_StringTableLibrary: return "Gen_StringTableLibrary";
    case CMChunkType::Gen_HUDLibrary: return "Gen_HUDLibrary";
    case CMChunkType::Gen_ResIDToNameTable: return "Gen_ResIDToNameTable";
    case CMChunkType::Gen_OcclusionModel: return "Gen_OcclusionModel";
    case CMChunkType::Gen_BinaryDataLibrary: return "Gen_BinaryDataLibrary";
    case CMChunkType::Gen_ReflectionSourceLibrary_REMOVED: return "Gen_ReflectionSourceLibrary_REMOVED";
    case CMChunkType::Gen_FoliageLibrary: return "Gen_FoliageLibrary";
    case CMChunkType::Gen_Languages: return "Gen_Languages";
    case CMChunkType::Gen_ExportContext: return "Gen_ExportContext";
    case CMChunkType::Gen_CutSceneLibrary: return "Gen_CutSceneLibrary";
    case CMChunkType::Gen_AudioSoundLibrary: return "Gen_AudioSoundLibrary";
    case CMChunkType::Gen_AudioCueLibrary: return "Gen_AudioCueLibrary";
    case CMChunkType::Gen_AudioSampleLibrary: return "Gen_AudioSampleLibrary";
    case CMChunkType::Gen_AudioCategoryLibrary: return "Gen_AudioCategoryLibrary";
    case CMChunkType::Gen_AudioRPCLibrary: return "Gen_AudioRPCLibrary";
    case CMChunkType::Gen_AudioSampleBankLibrary: return "Gen_AudioSampleBankLibrary";
    case CMChunkType::Gen_MaterialAnimLibrary: return "Gen_MaterialAnimLibrary";
    case CMChunkType::Gen_GameLogicHeader: return "Gen_GameLogicHeader";
    case CMChunkType::Gen_MotionTrailLibrary: return "Gen_MotionTrailLibrary";
    case CMChunkType::Gen_LODDistances: return "Gen_LODDistances";
    case CMChunkType::Gen_PostLoadData: return "Gen_PostLoadData";
    case CMChunkType::Gen_BSplineLibrary_REMOVED: return "Gen_BSplineLibrary_REMOVED";
    case CMChunkType::Gen_ZoneLibrary_REMOVED: return "Gen_ZoneLibrary_REMOVED";
    case CMChunkType::Gen_Constants: return "Gen_Constants";
    case CMChunkType::Gen_ResTable: return "Gen_ResTable";
    case CMChunkType::Gen_BillboardLibrary: return "Gen_BillboardLibrary";
    case CMChunkType::Gen_OctreeSoundOcclusion: return "Gen_OctreeSoundOcclusion";
    case CMChunkType::Gen_HAnimProcLibrary: return "Gen_HAnimProcLibrary";
    case CMChunkType::Gen_LightGridLibrary_DEPRECATED: return "Gen_LightGridLibrary_DEPRECATED";
    case CMChunkType::Gen_PackageSizes: return "Gen_PackageSizes";
    case CMChunkType::Gen_EnvironmentLibrary: return "Gen_EnvironmentLibrary";
    case CMChunkType::Gen_UnusedLibrary: return "Gen_UnusedLibrary";
    case CMChunkType::Gen_ParamBlockLibrary: return "Gen_ParamBlockLibrary";
    case CMChunkType::Gen_AudioReverbLibrary: return "Gen_AudioReverbLibrary";
    case CMChunkType::Gen_AnimCueLibrary: return "Gen_AnimCueLibrary";
    case CMChunkType::Gen_AnimTreeLibrary: return "Gen_AnimTreeLibrary";
    case CMChunkType::Gen_TextStyleLibrary: return "Gen_TextStyleLibrary";
    case CMChunkType::Gen_AnimationGraphLibrary_REMOVED: return "Gen_AnimationGraphLibrary_REMOVED";
    case CMChunkType::Gen_PackagesInfo: return "Gen_PackagesInfo";
    case CMChunkType::Gen_CurveLibrary: return "Gen_CurveLibrary";
    case CMChunkType::Gen_ResourcesListLibrary: return "Gen_ResourcesListLibrary";
    case CMChunkType::Gen_CityLibrary: return "Gen_CityLibrary";
    case CMChunkType::Gen_Streamable: return "Gen_Streamable";
    case CMChunkType::Gen_Cachable: return "Gen_Cachable";
    case CMChunkType::Gen_CityBlockLibrary: return "Gen_CityBlockLibrary";
    case CMChunkType::Gen_ParamTreeLibrary: return "Gen_ParamTreeLibrary";
    case CMChunkType::Gen_ParamGraphLibrary: return "Gen_ParamGraphLibrary";
    case CMChunkType::Gen_ParamBlockNameTable: return "Gen_ParamBlockNameTable";
    case CMChunkType::Gen_AudioInterleavedStreamsLibrary: return "Gen_AudioInterleavedStreamsLibrary";
    case CMChunkType::Gen_Hud3dLibrary: return "Gen_Hud3dLibrary";
    case CMChunkType::Gen_WwiseAudioLibrary: return "Gen_WwiseAudioLibrary";
    case CMChunkType::Gen_HeightMapLibrary: return "Gen_HeightMapLibrary";
    case CMChunkType::Gen_DecalLibrary: return "Gen_DecalLibrary";
    case CMChunkType::Gen_DecalInstanceLibrary: return "Gen_DecalInstanceLibrary";
    case CMChunkType::Gen_WwiseAudioCutsceneLibrary: return "Gen_WwiseAudioCutsceneLibrary";
    case CMChunkType::Gen_WwiseMediaLibrary: return "Gen_WwiseMediaLibrary";
    case CMChunkType::Gen_SequenceLibrary: return "Gen_SequenceLibrary";
    case CMChunkType::Gen_TextureHiMips: return "Gen_TextureHiMips";
    case CMChunkType::Gen_Count: return "Gen_Count";
    case CMChunkType::GenSub_VertexList: return "GenSub_VertexList";
    case CMChunkType::GenSub_IndexList: return "GenSub_IndexList";
    case CMChunkType::GenSub_TriangleIndexList: return "GenSub_TriangleIndexList";
    case CMChunkType::GenSub_TriangleCenterList: return "GenSub_TriangleCenterList";
    case CMChunkType::GenSub_TextureNamesTable: return "GenSub_TextureNamesTable";
    case CMChunkType::GenSub_Resource: return "GenSub_Resource";
    case CMChunkType::GenSub_ResourceHeader: return "GenSub_ResourceHeader";
    case CMChunkType::GenSub_ResourceIncrementalInfo: return "GenSub_ResourceIncrementalInfo";
    case CMChunkType::GenSub_SubVertexList: return "GenSub_SubVertexList";
    case CMChunkType::GenSub_ParamBlock: return "GenSub_ParamBlock";
    case CMChunkType::GenSub_ConstantDefs: return "GenSub_ConstantDefs";
    case CMChunkType::GenSub_ConstantHeader: return "GenSub_ConstantHeader";
    case CMChunkType::GenSub_ResList: return "GenSub_ResList";
    case CMChunkType::GenSub_CubeMap: return "GenSub_CubeMap";
    case CMChunkType::GenSub_VertexBufferArray: return "GenSub_VertexBufferArray";
    case CMChunkType::GenSub_VertexBufferArrayHeader: return "GenSub_VertexBufferArrayHeader";
    case CMChunkType::GenSub_IndexBufferArray: return "GenSub_IndexBufferArray";
    case CMChunkType::GenSub_IndexBufferArrayHeader: return "GenSub_IndexBufferArrayHeader";
    case CMChunkType::GenSub_Info: return "GenSub_Info";
    case CMChunkType::GenSub_LibPreloadList: return "GenSub_LibPreloadList";
    case CMChunkType::GenSub_RefResourceArray: return "GenSub_RefResourceArray";
    case CMChunkType::GenSub_Buffers: return "GenSub_Buffers";
    case CMChunkType::GenSub_Buffers_Info: return "GenSub_Buffers_Info";
    case CMChunkType::GenSub_ParamBlockData_DEPRECATED: return "GenSub_ParamBlockData_DEPRECATED";
    case CMChunkType::GenSub_ParamBlockPatchTable_DEPRECATED: return "GenSub_ParamBlockPatchTable_DEPRECATED";
    case CMChunkType::GenSub_VarParamBlock: return "GenSub_VarParamBlock";
    case CMChunkType::Octree_NodeList: return "Octree_NodeList";
    case CMChunkType::Octree_InfoHeader: return "Octree_InfoHeader";
    case CMChunkType::Octree_Shadow: return "Octree_Shadow";
    case CMChunkType::Octree_ShadowData: return "Octree_ShadowData";
    case CMChunkType::Octree_ShadowInfo: return "Octree_ShadowInfo";
    case CMChunkType::Octree_ShadowObject: return "Octree_ShadowObject";
    case CMChunkType::Octree_ShadowObjectData: return "Octree_ShadowObjectData";
    case CMChunkType::Octree_ShadowObjectInfo: return "Octree_ShadowObjectInfo";
    case CMChunkType::Octree_ShadowVolumes: return "Octree_ShadowVolumes";
    case CMChunkType::Octree_Info: return "Octree_Info";
    case CMChunkType::RenderOctree_PrimList: return "RenderOctree_PrimList";
    case CMChunkType::RenderOctree_OcclusionPrims: return "RenderOctree_OcclusionPrims";
    case CMChunkType::RenderOctree_MaterialList: return "RenderOctree_MaterialList";
    case CMChunkType::RenderOctree_PrimIdx: return "RenderOctree_PrimIdx";
    case CMChunkType::RenderOctree_Prims: return "RenderOctree_Prims";
    case CMChunkType::RenderOctree_TransCenters_REMOVED: return "RenderOctree_TransCenters_REMOVED";
    case CMChunkType::RenderOctree_Obj: return "RenderOctree_Obj";
    case CMChunkType::RenderOctree_InstanceIdx: return "RenderOctree_InstanceIdx";
    case CMChunkType::RenderOctree_Instances: return "RenderOctree_Instances";
    case CMChunkType::RenderOctree_MaterialListHeader: return "RenderOctree_MaterialListHeader";
    case CMChunkType::RenderOctree_InstancesSpecificData: return "RenderOctree_InstancesSpecificData";
    case CMChunkType::RenderOctree_InstancesSpecificDataUV: return "RenderOctree_InstancesSpecificDataUV";
    case CMChunkType::RenderOctree_ReflectionPlaneList: return "RenderOctree_ReflectionPlaneList";
    case CMChunkType::RenderOctree_EdgesLinesStrips: return "RenderOctree_EdgesLinesStrips";
    case CMChunkType::RenderOctree_EdgesLinesStripsIdx: return "RenderOctree_EdgesLinesStripsIdx";
    case CMChunkType::RenderOctree_PrimsBufferIndices: return "RenderOctree_PrimsBufferIndices";
    case CMChunkType::RenderOctree_ObjBufferIndices: return "RenderOctree_ObjBufferIndices";
    case CMChunkType::RenderOctree_Header: return "RenderOctree_Header";
    case CMChunkType::RenderOctree_EnlightenSystemMaterials: return "RenderOctree_EnlightenSystemMaterials";
    case CMChunkType::COctree_Info: return "COctree_Info";
    case CMChunkType::COctree_Data: return "COctree_Data";
    case CMChunkType::COctree_AIPath: return "COctree_AIPath";
    case CMChunkType::Texture_LibraryHeader: return "Texture_LibraryHeader";
    case CMChunkType::Texture: return "Texture";
    case CMChunkType::Logic_NameList: return "Logic_NameList";
    case CMChunkType::Texture_IDList: return "Texture_IDList";
    case CMChunkType::Texture_Header: return "Texture_Header";
    case CMChunkType::Texture_Data: return "Texture_Data";
    case CMChunkType::Texture_Format: return "Texture_Format";
    case CMChunkType::Texture_PreLoadData: return "Texture_PreLoadData";
    case CMChunkType::Texture_HiMips: return "Texture_HiMips";
    case CMChunkType::GO_Header: return "GO_Header";
    case CMChunkType::GO_Info: return "GO_Info";
    case CMChunkType::GO_Logic: return "GO_Logic";
    case CMChunkType::GO_Physic: return "GO_Physic";
    case CMChunkType::GO_Light: return "GO_Light";
    case CMChunkType::GO_Camera: return "GO_Camera";
    case CMChunkType::GO_Emitter: return "GO_Emitter";
    case CMChunkType::GO_3dObject: return "GO_3dObject";
    case CMChunkType::GO_DebugInfo: return "GO_DebugInfo";
    case CMChunkType::GO_ColPrimInfo: return "GO_ColPrimInfo";
    case CMChunkType::GO_MotionTrail: return "GO_MotionTrail";
    case CMChunkType::GO_Type: return "GO_Type";
    case CMChunkType::GO_Type_Info: return "GO_Type_Info";
    case CMChunkType::GO_Emitter_Emission: return "GO_Emitter_Emission";
    case CMChunkType::GO_Emitter_Field: return "GO_Emitter_Field";
    case CMChunkType::GO_Physic_Info: return "GO_Physic_Info";
    case CMChunkType::Logic_CodeLibInfo: return "Logic_CodeLibInfo";
    case CMChunkType::Logic_CodeHeader: return "Logic_CodeHeader";
    case CMChunkType::Logic_CodeHeaderInfo: return "Logic_CodeHeaderInfo";
    case CMChunkType::Logic_CodeFileHeader: return "Logic_CodeFileHeader";
    case CMChunkType::Logic_CodeFileInfo: return "Logic_CodeFileInfo";
    case CMChunkType::Logic_Code: return "Logic_Code";
    case CMChunkType::Logic_CodeData: return "Logic_CodeData";
    case CMChunkType::Logic_CodeReloc: return "Logic_CodeReloc";
    case CMChunkType::Logic_CodeSymbols: return "Logic_CodeSymbols";
    case CMChunkType::Logic_CodeSymbolsNames: return "Logic_CodeSymbolsNames";
    case CMChunkType::Logic_CodeDLLInfo: return "Logic_CodeDLLInfo";
    case CMChunkType::Logic_CodeStringTable: return "Logic_CodeStringTable";
    case CMChunkType::Logic_CodeRelModule: return "Logic_CodeRelModule";
    case CMChunkType::Logic_Resource: return "Logic_Resource";
    case CMChunkType::Logic_CodeRsoModule: return "Logic_CodeRsoModule";
    case CMChunkType::Logic_FrequencyParams: return "Logic_FrequencyParams";
    case CMChunkType::Logic_CodeRsoModuleList: return "Logic_CodeRsoModuleList";
    case CMChunkType::Logic_CodeRsoModuleListHeader: return "Logic_CodeRsoModuleListHeader";
    case CMChunkType::Font_Header: return "Font_Header";
    case CMChunkType::Font_Info: return "Font_Info";
    case CMChunkType::Font_Data: return "Font_Data";
    case CMChunkType::Font_TextureData: return "Font_TextureData";
    case CMChunkType::Geo_Model: return "Geo_Model";
    case CMChunkType::Geo_Geometry: return "Geo_Geometry";
    case CMChunkType::Geo_GeomInfo: return "Geo_GeomInfo";
    case CMChunkType::Geo_GeomTextureNames: return "Geo_GeomTextureNames";
    case CMChunkType::Geo_Material: return "Geo_Material";
    case CMChunkType::Geo_GeomLOD: return "Geo_GeomLOD";
    case CMChunkType::Geo_GeomLODInfo: return "Geo_GeomLODInfo";
    case CMChunkType::Geo_GeomMesh: return "Geo_GeomMesh";
    case CMChunkType::Geo_MorphTarget_UNUSED: return "Geo_MorphTarget_UNUSED";
    case CMChunkType::Geo_MorphTargetMesh_UNUSED: return "Geo_MorphTargetMesh_UNUSED";
    case CMChunkType::Geo_GeometryLibHeader: return "Geo_GeometryLibHeader";
    case CMChunkType::Geo_MeshSkinData_UNUSED: return "Geo_MeshSkinData_UNUSED";
    case CMChunkType::Geo_GeomMeshInfo_UNUSED: return "Geo_GeomMeshInfo_UNUSED";
    case CMChunkType::Geo_ShadowVolumeData_UNUSED: return "Geo_ShadowVolumeData_UNUSED";
    case CMChunkType::Geo_Morph: return "Geo_Morph";
    case CMChunkType::Geo_MorphMap_UNUSED: return "Geo_MorphMap_UNUSED";
    case CMChunkType::Geo_MaterialHeader: return "Geo_MaterialHeader";
    case CMChunkType::Geo_MaterialInfo: return "Geo_MaterialInfo";
    case CMChunkType::Geo_MorphNames_UNUSED: return "Geo_MorphNames_UNUSED";
    case CMChunkType::Geo_MorphMixResMap_UNUSED: return "Geo_MorphMixResMap_UNUSED";
    case CMChunkType::Geo_SubModels: return "Geo_SubModels";
    case CMChunkType::Geo_MorphCRC: return "Geo_MorphCRC";
    case CMChunkType::Geo_SBMeshData: return "Geo_SBMeshData";
    case CMChunkType::Geo_LODSkinningRLE: return "Geo_LODSkinningRLE";
    case CMChunkType::Geo_MaterialContext: return "Geo_MaterialContext";
    case CMChunkType::Geo_MaterialCRC: return "Geo_MaterialCRC";
    case CMChunkType::Geo_BoneToSkinningBoneTable: return "Geo_BoneToSkinningBoneTable";
    case CMChunkType::Geo_TextureCRC: return "Geo_TextureCRC";
    case CMChunkType::Geo_MaterialTechniquesHeader: return "Geo_MaterialTechniquesHeader";
    case CMChunkType::Geo_MaterialTechniques: return "Geo_MaterialTechniques";
    case CMChunkType::Geo_ProcTex: return "Geo_ProcTex";
    case CMChunkType::GeoSub_RLESkinningData: return "GeoSub_RLESkinningData";
    case CMChunkType::GeoSub_LODVtxData: return "GeoSub_LODVtxData";
    case CMChunkType::Hierarchy: return "Hierarchy";
    case CMChunkType::Hierarchy_Bones: return "Hierarchy_Bones";
    case CMChunkType::Hierarchy_Anims: return "Hierarchy_Anims";
    case CMChunkType::Hierarchy_Collision: return "Hierarchy_Collision";
    case CMChunkType::Hierarchy_LibHeader: return "Hierarchy_LibHeader";
    case CMChunkType::Hierarchy_BonesTRS: return "Hierarchy_BonesTRS";
    case CMChunkType::Hierarchy_BlendWeights: return "Hierarchy_BlendWeights";
    case CMChunkType::Hierarchy_BoneNames: return "Hierarchy_BoneNames";
    case CMChunkType::Hierarchy_ColPrimNames: return "Hierarchy_ColPrimNames";
    case CMChunkType::Hierarchy_Ragdoll: return "Hierarchy_Ragdoll";
    case CMChunkType::Hierarchy_RagdollNames: return "Hierarchy_RagdollNames";
    case CMChunkType::Hierarchy_BoneConstraints: return "Hierarchy_BoneConstraints";
    case CMChunkType::Hierarchy_Info: return "Hierarchy_Info";
    case CMChunkType::Audio_LibraryHeader: return "Audio_LibraryHeader";
    case CMChunkType::Audio_CueLibrary: return "Audio_CueLibrary";
    case CMChunkType::Audio_Cue: return "Audio_Cue";
    case CMChunkType::Audio_SoundLibrary: return "Audio_SoundLibrary";
    case CMChunkType::Audio_Sound: return "Audio_Sound";
    case CMChunkType::Audio_SoundHeader: return "Audio_SoundHeader";
    case CMChunkType::Audio_Track: return "Audio_Track";
    case CMChunkType::Audio_TrackHeader: return "Audio_TrackHeader";
    case CMChunkType::Audio_EventPlay: return "Audio_EventPlay";
    case CMChunkType::Audio_EventStop: return "Audio_EventStop";
    case CMChunkType::Audio_EventVolume: return "Audio_EventVolume";
    case CMChunkType::Audio_EventPitch: return "Audio_EventPitch";
    case CMChunkType::Audio_EventMarker: return "Audio_EventMarker";
    case CMChunkType::Audio_RPCIDs: return "Audio_RPCIDs";
    case CMChunkType::Audio_SampleLibrary: return "Audio_SampleLibrary";
    case CMChunkType::Audio_Sample: return "Audio_Sample";
    case CMChunkType::Audio_CategoryLibrary: return "Audio_CategoryLibrary";
    case CMChunkType::Audio_Category: return "Audio_Category";
    case CMChunkType::Audio_RPCLibrary: return "Audio_RPCLibrary";
    case CMChunkType::Audio_RPC: return "Audio_RPC";
    case CMChunkType::Audio_RPCHeader: return "Audio_RPCHeader";
    case CMChunkType::Audio_RPCCurve: return "Audio_RPCCurve";
    case CMChunkType::Audio_SampleBankLibrary: return "Audio_SampleBankLibrary";
    case CMChunkType::Audio_SampleBank: return "Audio_SampleBank";
    case CMChunkType::Audio_SampleSubtitles: return "Audio_SampleSubtitles";
    case CMChunkType::Audio_SampleData: return "Audio_SampleData";
    case CMChunkType::Audio_ReverbSettings: return "Audio_ReverbSettings";
    case CMChunkType::Audio_SampleSeekTable: return "Audio_SampleSeekTable";
    case CMChunkType::Audio_InterleavedStreams: return "Audio_InterleavedStreams";
    case CMChunkType::Particle_Resource: return "Particle_Resource";
    case CMChunkType::Particle_Info: return "Particle_Info";
    case CMChunkType::Particle_Anim: return "Particle_Anim";
    case CMChunkType::HAnim_Header: return "HAnim_Header";
    case CMChunkType::HAnim_Resource: return "HAnim_Resource";
    case CMChunkType::HAnim_Info: return "HAnim_Info";
    case CMChunkType::HAnim_LibHeader: return "HAnim_LibHeader";
    case CMChunkType::HAnim_BoneTable: return "HAnim_BoneTable";
    case CMChunkType::HAnim_BlendInfo: return "HAnim_BlendInfo";
    case CMChunkType::HAnim_Events: return "HAnim_Events";
    case CMChunkType::HAnim_BufferTimeTable: return "HAnim_BufferTimeTable";
    case CMChunkType::HAnim_EventsHeader: return "HAnim_EventsHeader";
    case CMChunkType::HAnim_MorphCRC: return "HAnim_MorphCRC";
    case CMChunkType::HAnim_Timings: return "HAnim_Timings";
    case CMChunkType::HAnim_Skip: return "HAnim_Skip";
    case CMChunkType::HAnim_BoneCRC: return "HAnim_BoneCRC";
    case CMChunkType::TextureAnim_Header: return "TextureAnim_Header";
    case CMChunkType::TextureAnim_Info: return "TextureAnim_Info";
    case CMChunkType::TextureAnim_Resource: return "TextureAnim_Resource";
    case CMChunkType::TextureAnim_LibHeader: return "TextureAnim_LibHeader";
    case CMChunkType::Movie_LibraryHeader: return "Movie_LibraryHeader";
    case CMChunkType::Movie: return "Movie";
    case CMChunkType::StringTable: return "StringTable";
    case CMChunkType::StringTable_Header: return "StringTable_Header";
    case CMChunkType::StringTable_Lib: return "StringTable_Lib";
    case CMChunkType::StringTable_LibHeader: return "StringTable_LibHeader";
    case CMChunkType::StringTable_Entry: return "StringTable_Entry";
    case CMChunkType::StringTable_Data: return "StringTable_Data";
    case CMChunkType::CustomParamStringTable: return "CustomParamStringTable";
    case CMChunkType::HUD: return "HUD";
    case CMChunkType::HUD_Window: return "HUD_Window";
    case CMChunkType::HUD_WindowHeader: return "HUD_WindowHeader";
    case CMChunkType::HUD_TextWindow: return "HUD_TextWindow";
    case CMChunkType::HUD_2DWindow: return "HUD_2DWindow";
    case CMChunkType::HUD_3DWindow: return "HUD_3DWindow";
    case CMChunkType::GOEmitterField_Base: return "GOEmitterField_Base";
    case CMChunkType::GOEmitterField_Gravity: return "GOEmitterField_Gravity";
    case CMChunkType::GOEmitterField_Fan: return "GOEmitterField_Fan";
    case CMChunkType::GOEmitterField_Drag: return "GOEmitterField_Drag";
    case CMChunkType::GOEmitterField_Radial: return "GOEmitterField_Radial";
    case CMChunkType::GOEmitterField_Vortex: return "GOEmitterField_Vortex";
    case CMChunkType::BinaryData_LibraryHeader: return "BinaryData_LibraryHeader";
    case CMChunkType::BinaryData_Header: return "BinaryData_Header";
    case CMChunkType::BinaryData_Info: return "BinaryData_Info";
    case CMChunkType::BinaryData_Data: return "BinaryData_Data";
    case CMChunkType::PackageInfo: return "PackageInfo";
    case CMChunkType::PackageInfoHeader: return "PackageInfoHeader";
    case CMChunkType::Foliage_LibraryHeader: return "Foliage_LibraryHeader";
    case CMChunkType::Foliage_WorldLibrary: return "Foliage_WorldLibrary";
    case CMChunkType::Foliage_World: return "Foliage_World";
    case CMChunkType::Foliage_LocalLibrary: return "Foliage_LocalLibrary";
    case CMChunkType::Foliage_Local: return "Foliage_Local";
    case CMChunkType::Foliage_InstanceLibrary: return "Foliage_InstanceLibrary";
    case CMChunkType::Foliage_Instance: return "Foliage_Instance";
    case CMChunkType::CutScene_LibraryHeader: return "CutScene_LibraryHeader";
    case CMChunkType::CutScene: return "CutScene";
    case CMChunkType::CutScene_Header: return "CutScene_Header";
    case CMChunkType::CutScene_Data: return "CutScene_Data";
    case CMChunkType::CutScene_PostLoadHeader: return "CutScene_PostLoadHeader";
    case CMChunkType::CutScene_Audio: return "CutScene_Audio";
    case CMChunkType::CutScene_Audio_SampleHeader: return "CutScene_Audio_SampleHeader";
    case CMChunkType::CutScene_Audio_SampleData: return "CutScene_Audio_SampleData";
    case CMChunkType::MaterialAnim_LibraryHeader: return "MaterialAnim_LibraryHeader";
    case CMChunkType::MaterialAnim: return "MaterialAnim";
    case CMChunkType::MaterialAnim_Header: return "MaterialAnim_Header";
    case CMChunkType::MaterialAnim_Channel: return "MaterialAnim_Channel";
    case CMChunkType::MaterialAnim_ChannelInfo: return "MaterialAnim_ChannelInfo";
    case CMChunkType::MaterialAnim_Data: return "MaterialAnim_Data";
    case CMChunkType::MaterialAnim_Names: return "MaterialAnim_Names";
    case CMChunkType::Logic_HeaderData: return "Logic_HeaderData";
    case CMChunkType::MotionTrail_LibraryHeader: return "MotionTrail_LibraryHeader";
    case CMChunkType::MotionTrail: return "MotionTrail";
    case CMChunkType::OcclusionData: return "OcclusionData";
    case CMChunkType::OcclusionCRC: return "OcclusionCRC";
    case CMChunkType::BSpline_LibraryHeader: return "BSpline_LibraryHeader";
    case CMChunkType::BSpline: return "BSpline";
    case CMChunkType::BSpline_Info: return "BSpline_Info";
    case CMChunkType::BSpline_Node: return "BSpline_Node";
    case CMChunkType::BSpline_NodeInfo: return "BSpline_NodeInfo";
    case CMChunkType::Zone_LibraryHeader_UNUSED: return "Zone_LibraryHeader_UNUSED";
    case CMChunkType::Zone_UNUSED: return "Zone_UNUSED";
    case CMChunkType::Zone_Info_UNUSED: return "Zone_Info_UNUSED";
    case CMChunkType::Zone_Logic_UNUSED: return "Zone_Logic_UNUSED";
    case CMChunkType::Zone_CubeMap: return "Zone_CubeMap";
    case CMChunkType::Zone_CubeMapInfo: return "Zone_CubeMapInfo";
    case CMChunkType::Billboard_Resource: return "Billboard_Resource";
    case CMChunkType::SoundOctree_Info: return "SoundOctree_Info";
    case CMChunkType::SoundOctree_Data: return "SoundOctree_Data";
    case CMChunkType::SoundOctree_Graph: return "SoundOctree_Graph";
    case CMChunkType::HAnimProc_Data: return "HAnimProc_Data";
    case CMChunkType::LightGrid_Library_DEPRECATED: return "LightGrid_Library_DEPRECATED";
    case CMChunkType::LightGrid_DEPRECATED: return "LightGrid_DEPRECATED";
    case CMChunkType::Env_LibraryHeader: return "Env_LibraryHeader";
    case CMChunkType::Env_Render: return "Env_Render";
    case CMChunkType::Env_Collision: return "Env_Collision";
    case CMChunkType::Env_Occlusion: return "Env_Occlusion";
    case CMChunkType::Env_SoundOcclusion: return "Env_SoundOcclusion";
    case CMChunkType::Env_NavMesh: return "Env_NavMesh";
    case CMChunkType::Env_NavMesh_Data: return "Env_NavMesh_Data";
    case CMChunkType::Env_NavMesh_FaceDataTable: return "Env_NavMesh_FaceDataTable";
    case CMChunkType::Env_NavMesh_FaceData: return "Env_NavMesh_FaceData";
    case CMChunkType::Env_NavMesh_Octree: return "Env_NavMesh_Octree";
    case CMChunkType::Env_EnlightenScene: return "Env_EnlightenScene";
    case CMChunkType::LightGrid_Group: return "LightGrid_Group";
    case CMChunkType::LightGrid_GroupHeader: return "LightGrid_GroupHeader";
    case CMChunkType::LightGrid: return "LightGrid";
    case CMChunkType::Anim_BaseTree_LibraryHeader: return "Anim_BaseTree_LibraryHeader";
    case CMChunkType::Anim_BaseTree: return "Anim_BaseTree";
    case CMChunkType::Anim_BaseTree_Header: return "Anim_BaseTree_Header";
    case CMChunkType::Anim_BaseTree_Leaves: return "Anim_BaseTree_Leaves";
    case CMChunkType::Anim_BaseTree_Blenders: return "Anim_BaseTree_Blenders";
    case CMChunkType::Anim_BaseTree_Children: return "Anim_BaseTree_Children";
    case CMChunkType::Anim_BaseTree_Names: return "Anim_BaseTree_Names";
    case CMChunkType::ParamBlock_Header: return "ParamBlock_Header";
    case CMChunkType::ParamBlock_Data: return "ParamBlock_Data";
    case CMChunkType::ParamBlock_Transform: return "ParamBlock_Transform";
    case CMChunkType::TextStyle_Header: return "TextStyle_Header";
    case CMChunkType::TextStyle_Info: return "TextStyle_Info";
    case CMChunkType::Anim_Cue_LibraryHeader: return "Anim_Cue_LibraryHeader";
    case CMChunkType::Anim_Cue: return "Anim_Cue";
    case CMChunkType::Anim_Cue_Header: return "Anim_Cue_Header";
    case CMChunkType::Anim_Cue_In: return "Anim_Cue_In";
    case CMChunkType::Anim_Cue_Loop: return "Anim_Cue_Loop";
    case CMChunkType::Anim_Cue_Out: return "Anim_Cue_Out";
    case CMChunkType::UNUSED: return "UNUSED";
    case CMChunkType::Curve: return "Curve";
    case CMChunkType::Curve_Info: return "Curve_Info";
    case CMChunkType::Curve_Sample: return "Curve_Sample";
    case CMChunkType::Curve_Node: return "Curve_Node";
    case CMChunkType::Curve_Node_Info: return "Curve_Node_Info";
    case CMChunkType::ResourcesList: return "ResourcesList";
    case CMChunkType::ResourcesList_Info_Deprecated: return "ResourcesList_Info_Deprecated";
    case CMChunkType::City_Info: return "City_Info";
    case CMChunkType::City_Base_Building_Group: return "City_Base_Building_Group";
    case CMChunkType::City_Building: return "City_Building";
    case CMChunkType::City_Building_Info: return "City_Building_Info";
    case CMChunkType::City_Wall_Group: return "City_Wall_Group";
    case CMChunkType::City_Wall_DEPRECATED: return "City_Wall_DEPRECATED";
    case CMChunkType::City_Roof_Group: return "City_Roof_Group";
    case CMChunkType::City_Roof: return "City_Roof";
    case CMChunkType::City_Roof_Info: return "City_Roof_Info";
    case CMChunkType::City_Node_Group: return "City_Node_Group";
    case CMChunkType::City_Node: return "City_Node";
    case CMChunkType::City_Node_Info: return "City_Node_Info";
    case CMChunkType::City_Blocks: return "City_Blocks";
    case CMChunkType::City_Props_Obj: return "City_Props_Obj";
    case CMChunkType::City_Low_Node: return "City_Low_Node";
    case CMChunkType::City_Low_Building_Group: return "City_Low_Building_Group";
    case CMChunkType::City_Low_Building: return "City_Low_Building";
    case CMChunkType::City_Low_Building_Info: return "City_Low_Building_Info";
    case CMChunkType::City_Low_Wall_Group: return "City_Low_Wall_Group";
    case CMChunkType::City_Low_Wall: return "City_Low_Wall";
    case CMChunkType::City_Low_Wall_Info: return "City_Low_Wall_Info";
    case CMChunkType::City_Low_Region_Group: return "City_Low_Region_Group";
    case CMChunkType::City_Low_Region: return "City_Low_Region";
    case CMChunkType::City_Low_Border_Group: return "City_Low_Border_Group";
    case CMChunkType::City_Low_DynamicProps: return "City_Low_DynamicProps";
    case CMChunkType::City_Low_Roof_Group: return "City_Low_Roof_Group";
    case CMChunkType::City_Low_Roof: return "City_Low_Roof";
    case CMChunkType::City_High_Node: return "City_High_Node";
    case CMChunkType::City_High_Building_Group: return "City_High_Building_Group";
    case CMChunkType::City_High_Building: return "City_High_Building";
    case CMChunkType::City_High_Wall_Group: return "City_High_Wall_Group";
    case CMChunkType::City_High_Wall: return "City_High_Wall";
    case CMChunkType::City_High_Region_Group: return "City_High_Region_Group";
    case CMChunkType::City_High_Region: return "City_High_Region";
    case CMChunkType::City_High_Region_Info: return "City_High_Region_Info";
    case CMChunkType::City_High_Block: return "City_High_Block";
    case CMChunkType::City_High_Block_Info: return "City_High_Block_Info";
    case CMChunkType::City_Material_Group: return "City_Material_Group";
    case CMChunkType::City_Material_Group_Info: return "City_Material_Group_Info";
    case CMChunkType::City_Low_Region_Info: return "City_Low_Region_Info";
    case CMChunkType::City_Low_Region_LOD1_Meshes: return "City_Low_Region_LOD1_Meshes";
    case CMChunkType::City_Low_Region_LOD1_Mesh_Info: return "City_Low_Region_LOD1_Mesh_Info";
    case CMChunkType::City_Low_Border: return "City_Low_Border";
    case CMChunkType::City_Low_Border_Info: return "City_Low_Border_Info";
    case CMChunkType::City_Med_CollisionMaterialCRCs: return "City_Med_CollisionMaterialCRCs";
    case CMChunkType::City_Med_OcclusionFaceCRCs: return "City_Med_OcclusionFaceCRCs";
    case CMChunkType::City_Med_Node: return "City_Med_Node";
    case CMChunkType::City_Med_Building_Group: return "City_Med_Building_Group";
    case CMChunkType::City_Med_Building: return "City_Med_Building";
    case CMChunkType::City_Med_Building_Info: return "City_Med_Building_Info";
    case CMChunkType::City_Med_Wall_Group_DEPRECATED: return "City_Med_Wall_Group_DEPRECATED";
    case CMChunkType::City_Med_Wall_DEPRECATED: return "City_Med_Wall_DEPRECATED";
    case CMChunkType::City_Med_Region_Group_DEPRECATED: return "City_Med_Region_Group_DEPRECATED";
    case CMChunkType::City_Med_Region_DEPRECATED: return "City_Med_Region_DEPRECATED";
    case CMChunkType::City_Med_Region_Info_DEPRECATED: return "City_Med_Region_Info_DEPRECATED";
    case CMChunkType::City_Med_Region_LOD1_Meshes_DEPRECATED: return "City_Med_Region_LOD1_Meshes_DEPRECATED";
    case CMChunkType::City_Med_Region_LOD1_Mesh_Info_DEPRECATED: return "City_Med_Region_LOD1_Mesh_Info_DEPRECATED";
    case CMChunkType::City_Med_Border_Group: return "City_Med_Border_Group";
    case CMChunkType::City_Med_Border: return "City_Med_Border";
    case CMChunkType::City_Med_Border_Info: return "City_Med_Border_Info";
    case CMChunkType::City_Med_Props: return "City_Med_Props";
    case CMChunkType::City_Med_DynamicProps: return "City_Med_DynamicProps";
    case CMChunkType::City_TextureCRC_Table: return "City_TextureCRC_Table";
    case CMChunkType::City_Med_Roof_Group_Deprecated: return "City_Med_Roof_Group_Deprecated";
    case CMChunkType::City_Med_Roof: return "City_Med_Roof";
    case CMChunkType::City_Low_Node_Group: return "City_Low_Node_Group";
    case CMChunkType::City_Med_Node_Group: return "City_Med_Node_Group";
    case CMChunkType::City_High_Node_Group: return "City_High_Node_Group";
    case CMChunkType::City_High_Border_Group: return "City_High_Border_Group";
    case CMChunkType::City_High_Border: return "City_High_Border";
    case CMChunkType::City_High_Border_Info: return "City_High_Border_Info";
    case CMChunkType::City_Dynamic_Prop_Library_DEPRECATED: return "City_Dynamic_Prop_Library_DEPRECATED";
    case CMChunkType::City_Dynamic_Prop_Info: return "City_Dynamic_Prop_Info";
    case CMChunkType::City_Dynamic_Prop: return "City_Dynamic_Prop";
    case CMChunkType::City_Emissive_Color_Palette: return "City_Emissive_Color_Palette";
    case CMChunkType::City_Med_LOD1_Color_Buffer_DEPRECATED: return "City_Med_LOD1_Color_Buffer_DEPRECATED";
    case CMChunkType::City_Low_TextureCRC_Table_DEPRECATED: return "City_Low_TextureCRC_Table_DEPRECATED";
    case CMChunkType::City_Med_TextureCRC_Table_DEPRECATED: return "City_Med_TextureCRC_Table_DEPRECATED";
    case CMChunkType::City_Node_Material_Group: return "City_Node_Material_Group";
    case CMChunkType::City_Node_Material_Group_Info: return "City_Node_Material_Group_Info";
    case CMChunkType::City_CubeMapZones: return "City_CubeMapZones";
    case CMChunkType::City_RezRefDataOffset: return "City_RezRefDataOffset";
    case CMChunkType::City_Base_Node_Header: return "City_Base_Node_Header";
    case CMChunkType::City_Low_Node_Header: return "City_Low_Node_Header";
    case CMChunkType::City_Med_Node_Header: return "City_Med_Node_Header";
    case CMChunkType::City_High_Node_Header: return "City_High_Node_Header";
    case CMChunkType::City_Node_References_DEPRECATED: return "City_Node_References_DEPRECATED";
    case CMChunkType::City_Block_Header: return "City_Block_Header";
    case CMChunkType::City_Collision_Node_Group_DEPRECATED: return "City_Collision_Node_Group_DEPRECATED";
    case CMChunkType::City_Collision_Node_DEPRECATED: return "City_Collision_Node_DEPRECATED";
    case CMChunkType::City_Collision_Node_Header_DEPRECATED: return "City_Collision_Node_Header_DEPRECATED";
    case CMChunkType::City_HeightMapInfo: return "City_HeightMapInfo";
    case CMChunkType::City_LOD3Root: return "City_LOD3Root";
    case CMChunkType::City_LOD3Info: return "City_LOD3Info";
    case CMChunkType::City_LOD3BuildingEntries: return "City_LOD3BuildingEntries";
    case CMChunkType::City_LOD3Buffer: return "City_LOD3Buffer";
    case CMChunkType::City_RZCityBlock_Container: return "City_RZCityBlock_Container";
    case CMChunkType::CityBlock_Info: return "CityBlock_Info";
    case CMChunkType::ParamTree: return "ParamTree";
    case CMChunkType::ParamTree_NodesDesc: return "ParamTree_NodesDesc";
    case CMChunkType::ParamTree_NodesData: return "ParamTree_NodesData";
    case CMChunkType::ParamTree_NodesDataInfo: return "ParamTree_NodesDataInfo";
    case CMChunkType::ParamTree_Names: return "ParamTree_Names";
    case CMChunkType::ParamGraph: return "ParamGraph";
    case CMChunkType::ParamGraph_Nodes: return "ParamGraph_Nodes";
    case CMChunkType::ParamGraph_Edges: return "ParamGraph_Edges";
    case CMChunkType::ParamGraph_Params: return "ParamGraph_Params";
    case CMChunkType::ParamGraph_ParamsInfo: return "ParamGraph_ParamsInfo";
    case CMChunkType::ParamGraph_Names: return "ParamGraph_Names";
    case CMChunkType::Graph3D: return "Graph3D";
    case CMChunkType::Graph3D_Nodes: return "Graph3D_Nodes";
    case CMChunkType::Graph3D_Edges: return "Graph3D_Edges";
    case CMChunkType::Graph3D_Params: return "Graph3D_Params";
    case CMChunkType::Graph3D_ParamsInfo: return "Graph3D_ParamsInfo";
    case CMChunkType::Graph3D_Names: return "Graph3D_Names";
    case CMChunkType::Hud3D: return "Hud3D";
    case CMChunkType::Hud3D_BaseInfo: return "Hud3D_BaseInfo";
    case CMChunkType::Hud3D_ElemInfo: return "Hud3D_ElemInfo";
    case CMChunkType::WwiseSoundBank: return "WwiseSoundBank";
    case CMChunkType::WwiseSoundBankData: return "WwiseSoundBankData";
    case CMChunkType::WwiseSoundBankHeader: return "WwiseSoundBankHeader";
    case CMChunkType::WwiseMediaHeader: return "WwiseMediaHeader";
    case CMChunkType::WwiseMediaData: return "WwiseMediaData";
    case CMChunkType::WwiseAudioRefHeader: return "WwiseAudioRefHeader";
    case CMChunkType::HeightMap: return "HeightMap";
    case CMChunkType::HeightMap_Info: return "HeightMap_Info";
    case CMChunkType::HeightMap_Data: return "HeightMap_Data";
    case CMChunkType::HeightMap_Container: return "HeightMap_Container";
    case CMChunkType::Streams: return "Streams";
    case CMChunkType::StreamsHeader: return "StreamsHeader";
    case CMChunkType::LocalizedStreamsHeader: return "LocalizedStreamsHeader";
    case CMChunkType::StreamsPackages: return "StreamsPackages";
    case CMChunkType::StreamsPackageHeader: return "StreamsPackageHeader";
    case CMChunkType::WwiseStreams: return "WwiseStreams";
    case CMChunkType::WwiseStreamsData: return "WwiseStreamsData";
    case CMChunkType::WwiseStreamsExtraHeader: return "WwiseStreamsExtraHeader";
    case CMChunkType::WwiseStreamsWaveData: return "WwiseStreamsWaveData";
    case CMChunkType::ProjDecal: return "ProjDecal";
    case CMChunkType::ProjDecal_Data: return "ProjDecal_Data";
    case CMChunkType::ProjDecalInstance: return "ProjDecalInstance";
    case CMChunkType::WwiseDebugPackageFileList: return "WwiseDebugPackageFileList";
    case CMChunkType::WwiseDebugLanguage: return "WwiseDebugLanguage";
    case CMChunkType::WwiseDebugPackage: return "WwiseDebugPackage";
    case CMChunkType::Sequence: return "Sequence";
    case CMChunkType::Sequence_Header: return "Sequence_Header";
    case CMChunkType::Sequence_TrackList: return "Sequence_TrackList";
    case CMChunkType::Sequence_Track: return "Sequence_Track";
    case CMChunkType::Sequence_TrackHeader: return "Sequence_TrackHeader";
    case CMChunkType::Sequence_TrackNodes: return "Sequence_TrackNodes";
    case CMChunkType::Sequence_Params: return "Sequence_Params";
    case CMChunkType::Sequence_ParamsInfo_DEPRECATED: return "Sequence_ParamsInfo_DEPRECATED";
    case CMChunkType::Sequence_Names: return "Sequence_Names";
    case CMChunkType::EnlightenScene_Header: return "EnlightenScene_Header";
    case CMChunkType::EnlightenScene_System: return "EnlightenScene_System";
    case CMChunkType::EnlightenScene_ProbeSet: return "EnlightenScene_ProbeSet";
    case CMChunkType::ProbeSet_Group: return "ProbeSet_Group";
    case CMChunkType::ProbeSet_GroupHeader: return "ProbeSet_GroupHeader";
    case CMChunkType::ProbeSet_Data: return "ProbeSet_Data";
    case CMChunkType::ProceduralMeshes: return "ProceduralMeshes";
    case CMChunkType::ProceduralMeshes_Base_Infos: return "ProceduralMeshes_Base_Infos";
    case CMChunkType::ProceduralMeshes_Deformation: return "ProceduralMeshes_Deformation";
    case CMChunkType::ProceduralMeshes_Deformation_Header: return "ProceduralMeshes_Deformation_Header";
    case CMChunkType::ProceduralMeshes_Deformation_Data: return "ProceduralMeshes_Deformation_Data";
    case CMChunkType::ProceduralMeshes_GerstnerDeformation_Data: return "ProceduralMeshes_GerstnerDeformation_Data";
    case CMChunkType::ProceduralMeshes_GerstnerZoneDeformation_Data: return "ProceduralMeshes_GerstnerZoneDeformation_Data";
    case CMChunkType::ProceduralMeshes_Geometry: return "ProceduralMeshes_Geometry";
    case CMChunkType::ProceduralMeshes_GeometryExtraData: return "ProceduralMeshes_GeometryExtraData";
    case CMChunkType::ProceduralMeshes_Material: return "ProceduralMeshes_Material";
    case CMChunkType::ProceduralMeshes_IndexBuffer: return "ProceduralMeshes_IndexBuffer";
    case CMChunkType::ProceduralMeshes_VertexBuffer: return "ProceduralMeshes_VertexBuffer";
    case CMChunkType::Moodbox: return "Moodbox";
    case CMChunkType::Moodbox_Info: return "Moodbox_Info";
    case CMChunkType::Moodbox_AmbientLight: return "Moodbox_AmbientLight";
    case CMChunkType::Moodbox_Fog: return "Moodbox_Fog";
    case CMChunkType::Moodbox_FXAA: return "Moodbox_FXAA";
    case CMChunkType::Moodbox_HDRBloom: return "Moodbox_HDRBloom";
    case CMChunkType::Moodbox_SSAO: return "Moodbox_SSAO";
    case CMChunkType::Moodbox_Bokeh: return "Moodbox_Bokeh";
    case CMChunkType::Moodbox_Clipping: return "Moodbox_Clipping";
    case CMChunkType::Moodbox_Colorization: return "Moodbox_Colorization";
    case CMChunkType::Moodbox_EnvCubemap: return "Moodbox_EnvCubemap";
    case CMChunkType::Moodbox_GlobalSpecColor: return "Moodbox_GlobalSpecColor";
    case CMChunkType::Moodbox_Irradiance: return "Moodbox_Irradiance";
    case CMChunkType::Moodbox_HeatHaze: return "Moodbox_HeatHaze";
    case CMChunkType::kCMChunkTypes_Count: return "kCMChunkTypes_Count";
    default: break;
    }
    static thread_local std::string fallback;
    fallback = "Unknown (0x" + std::to_string(static_cast<uint32_t>(type)) + ")";
    return fallback.c_str();
}


class LDChunk {
public:
    CMChunkType type = CMChunkType::Invalid;
    uint32_t version = 0;
    bool hasChildren = false;
    uint32_t length = 0;
    uint64_t offset = 0;

    std::vector<uint8_t> data;
    std::vector<LDChunk> children;

    LDChunk() = default;

    LDChunk(CMChunkType type, uint32_t version, bool hasChildren, uint32_t length, uint64_t offset)
        : type(type), version(version), hasChildren(hasChildren), length(length), offset(offset) {
    }

    void AddChild(const LDChunk& child) {
        children.push_back(child);
    }

    const std::vector<LDChunk>& GetChildren() const {
        return children;
    }

    bool IsLeaf() const {
        return !hasChildren || children.empty();
    }
};
