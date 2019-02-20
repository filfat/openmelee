#include "scenes.h"

namespace Engine {
    namespace Scenes {
        std::vector<Engine::Scenes::Scene> g_scenes;

        std::vector<Engine::Scenes::Scene> Init(void) {
            std::string path = "./assets/scenes";
            for (const auto & entry : std::experimental::filesystem::directory_iterator(path)) {
                auto scene = Engine::Scenes::Scene((const char*)entry.path().c_str());
                Engine::Scenes::g_scenes.push_back(scene);
            }

            return g_scenes;
        }
    }
}