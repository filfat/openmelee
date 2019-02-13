#include "character.h"
#include "../../stub/stub.h"
#include "../../../libs/termcolor.hpp"
#include "../../../libs/json.hpp"

using namespace nlohmann;

namespace Engine {
    namespace Characters {
        Character::Character (const char* path) {
            std::cout << termcolor::blue << "(ENGINE)   " << termcolor::reset;
            printf("Characters->Character->Loading: \"%s\"...\n", path);

            std::ifstream file_stream(path);
            std::string file_content((std::istreambuf_iterator<char>(file_stream)), (std::istreambuf_iterator<char>()));

            json data = json::parse(file_content);

            id = data["id"].get<std::string>();
            name = data["name"].get<std::string>();

            attributes = Engine::Characters::CharacterAttributes();
            attributes.walkInitVelocity = data["attributes"]["walkInitVelocity"].get<float>();
            attributes.walkMaxVelocity = data["attributes"]["walkMaxVelocity"].get<float>();
            attributes.walkAcceleration = data["attributes"]["walkAcceleration"].get<float>();
        }
    }
}