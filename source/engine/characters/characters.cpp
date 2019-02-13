#include "characters.h"
#include "../../stub/stub.h"

namespace Engine {
    namespace Characters {
        std::vector<Engine::Characters::Character> g_characters;

        int32_t Init(void) {
            std::string path = "./assets/characters";
            for (const auto & entry : std::experimental::filesystem::directory_iterator(path))
                Engine::Characters::g_characters.push_back(Engine::Characters::Character((const char*)entry.path().c_str()));

            return 0;
        }
    }
}
