#pragma once
#include <cstdint>
#include <vector>
#include <string>
// WIP RZResource implementation lol
// Not accurate to how Beenox's Goliath does it.

enum RezType : uint8_t {
    Invalid = 0,
    LogicCode = 0x1,
    Hierarchy = 0x2,
    Geometry = 0x3,
    Texture = 0x4,
    HAnim = 0x5,
    BinaryData = 0x6,
    Font = 0x7,
    ParticleDesc = 0x8,
    AudioRPC = 0x9,
    AudioBank = 0xa,
    CutScene = 0xb,
    AudioCue = 0xc,
    AudioSound = 0xd,
    AudioSample = 0xe,
    AudioCategory = 0xf,
    Billboard = 0x10,
    MotionTrail = 0x11,
    BSpline_TODEL = 0x12,
    HAnimProc = 0x13,
    Unused = 0x14,
    ParamBlock = 0x15,
    AudioReverb = 0x16,
    AnimCue = 0x17,
    AnimTree = 0x18,
    TextStyle = 0x19,
    AnimGraph = 0x1a,
    Curve = 0x1b,
    ResourcesList = 0x1c,
    CityBlock = 0x1d,
    ParamTree = 0x1e,
    ParamGraph = 0x1f,
    AudioInterleavedStreams = 0x20,
    Unused2 = 0x21,
    AudioEvent = 0x22,
    HeightMap = 0x23,
    ProjectedDecalInstance = 0x24,
    ProjectedDecal = 0x25,
    AudioBankCutscene = 0x26,
    Sequence = 0x27,
    BaseCount = 0x28,
    TotalCount = 0x29,
};

class RZResource {
public:
    uint32_t uiCRC;
    uint32_t postLoadDataCRC;
    uint32_t uiQualityLevel;
    uint64_t dataOffset;
    std::vector<RZResource> mRefResourceArray;
    uint8_t refCount;
    RZResource* next;
    RezType rezType;
    std::string rezName;

    void SetName(const std::string& name) { rezName = name; }
};

class RZResourceDicardable : RZResource {
    uint32_t muiPostLoadDataCRC;
};