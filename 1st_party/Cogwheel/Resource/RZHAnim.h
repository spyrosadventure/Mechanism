#pragma once
#include "BaseUtils/BUMath.h"
#include "BaseUtils/BUCRC.h"

#include "GameLogic/GLParamBlock.h"

#include "Resource/RZResource.h"
#include "Resource/RZAnimMap.h"
#include "Resource/RZCutscene.h"
#include "Resource/RZHierarchy.h"

#include <cstdint>

class CMTransforms {
    BUVector3 trans;
    BUQuaternion rot;
    BUVector3 scale;
};

class RZAnimEvent {
    float fTime;
    uint32_t uiType;
    uint32_t uiFlags;
    GLParamBlock* pParamBlock;
};

class RZBoneKFInfo {
    BUVector3 position;
    BUVector3 velocity;
};

class RZAnimInfo {
public:
    RZHierarchy* pHierarchyOfAnim;
    uint32_t uiCRCHierarchyOfAnim;
    float fDuration;
    float fFrameTime;
    uint32_t uiDispBone;
    CMTransforms dispFinalPos;
    uint16_t uiFlags;
    uint16_t uiMaxBoneIndex;
    uint16_t uiMaxMorphTargetIndex;
    uint8_t uiBufferCount;
private:
    uint8_t uiPadding[1];
};

class RZAnimBuffer {
private:
    uint32_t padding;
public:
    uint32_t muiBufferSize;
    RZAnimBuffer* mpNext;
    void* mpAnimData;
};

class RZHanim : RZResourceDicardable {
public:
    RZAnimBuffer* mpFirstBuffer;
    RZAnimInfo mAnimInfo;
    BUCRCTable mMorphsCRCTable;
    RZBoneKFInfo* mpBoneKFInfo;
    RZAnimEvent* mpAnimEvents;
    uint32_t muiNbAnimEvents;
    RZAnimMapHandler mAnimMaps;
    RZCutScene* mpCutsceneOwner;
    uint32_t muiLinkUpdateFrameCount;

    bool IsAdditive() const { return (mAnimInfo.uiFlags & 1) != 0; }
    bool IsDOFAdditive() const { return (mAnimInfo.uiFlags & 0x10) != 0; }
    bool IsFOVAdditive() const { return (mAnimInfo.uiFlags & 8) != 0; }
    bool IsHDRAdditive() const { return (mAnimInfo.uiFlags & 0x20) != 0; }
    float GetDuration() const { return mAnimInfo.fDuration; }
    uint32_t GetMaxBoneIndex() const { return (uint32_t)mAnimInfo.uiMaxBoneIndex; }
    uint32_t GetNbAnimEvents() const { return muiNbAnimEvents; }
    uint32_t MorphGetCount() const { return (uint32_t)mAnimInfo.uiMaxMorphTargetIndex; }
};