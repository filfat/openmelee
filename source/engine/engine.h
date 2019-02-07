#pragma once
#include "gui/gui.h"
#include "iso/iso.h"
#include "state/state.h"

#include "../SDK/sdk.h"

namespace Engine {
    int32_t Init(void);
    void Exit(void);

    void PrepareTick(void);
    bool DoTick(void);
}