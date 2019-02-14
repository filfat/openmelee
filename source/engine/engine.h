#pragma once
#include "characters/characters.h"
#include "gl/gl.h"
#include "gui/gui.h"
#include "iso/iso.h"
#include "stages/stages.h"
#include "state/state.h"

#include "../SDK/sdk.h"

namespace Engine {
    extern bool g_running;

    int32_t Init(void);
    void GameInit(void);
    void Exit(void);
    void ForceExit(void);

    void PrepareTick(void);
    bool DoTick(void);
}