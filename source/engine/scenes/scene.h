#pragma once
#include "../../../libs/sol.hpp"
#include "../../stub/stub.h"
#include "../state/state.h"

namespace Engine {
    namespace Scenes {
        class Scene {
            public:
                Scene(const char* path);
                ~Scene();
                void Update (Engine::State &state);
                void Render (const Engine::State &state);
            private:
                
        };
    }
}