#pragma once
#include <chrono>
#include "characters/characters.h"
#include "gl/gl.h"
#include "gui/gui.h"
#include "iso/iso.h"
#include "stages/stages.h"
#include "state/state.h"

#include "../SDK/sdk.h"

namespace Engine {
    int32_t Init(void);
    void GameInit(void);

    void Exit(void);
    void ForceExit(void);

    void Start(void);
    void Update(State &state);
    void Render(const State &state);

    State Interpolate(const State &current, const State &previous, float alpha);
}