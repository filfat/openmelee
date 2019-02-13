#include "characters.h"
#include "../../stub/stub.h"

namespace Engine {
    namespace Characters {
        std::vector<Engine::Characters::Character> g_characters;

        std::vector<Engine::Characters::Character> Init(void) {
            std::string path = "./assets/characters";
            for (const auto & entry : std::experimental::filesystem::directory_iterator(path)) {
                auto character = Engine::Characters::Character((const char*)entry.path().c_str());
                Engine::Characters::g_characters.push_back(character);
            }

            return g_characters;
        }
    }
}
