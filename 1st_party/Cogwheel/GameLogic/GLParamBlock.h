#pragma once
#include "GameLogic/GLBaseAPI.h"

class GLParamBlock {
    BaseArgs* mpData;
    GLParamBlock* mpOwner;
    GLParamBlock* mpNext;
    int miRefCount;
    bool mbGameLogicAllocatedData : 1;
};