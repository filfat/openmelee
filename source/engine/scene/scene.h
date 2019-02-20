#pragma once
extern "C" {
    #include "../../../libs/sol_forward.hpp"
}
#include "../../stub/stub.h"
#include "../state/state.h"

namespace Engine {
    namespace Scenes {
        class Scene {
            public:
                Scene(const char* path);
                void Update (Engine::State &state);
                void Render (const Engine::State &state);
            private:
                sol::state lua_state;
        };
    }
}