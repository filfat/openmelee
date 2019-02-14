#include "stages.h"

namespace Engine {
    namespace Stages {
        std::vector<Engine::Stages::Stage> g_stages;

        std::vector<Engine::Stages::Stage> Init (void) {
            std::string path = "./assets/stages";
            for (const auto & entry : std::experimental::filesystem::directory_iterator(path)) {
                auto stage = Engine::Stages::Stage((const char*)entry.path().c_str());
                Engine::Stages::g_stages.push_back(stage);
            }

            return g_stages;
        }
    }
}