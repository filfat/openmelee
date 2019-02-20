#pragma once
#include <iostream>
#include <vector>
#include <experimental/filesystem>
#include "scene.h"

namespace Engine {
    namespace Scenes {
        extern std::vector<Engine::Scenes::Scene> g_scenes;

        std::vector<Engine::Scenes::Scene> Init(void);
    }
}