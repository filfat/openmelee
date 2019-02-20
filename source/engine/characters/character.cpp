#include "character.h"
#include "../../SDK/os/os.h"
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

            try {
                attributes.walk_velocity_init = data["attributes"]["walkInitVelocity"].get<float>();
                attributes.walk_velocity_max = data["attributes"]["walkMaxVelocity"].get<float>();
                attributes.walk_acceleration = data["attributes"]["walkAcceleration"].get<float>();
                attributes.walk_speed_medium = data["attributes"]["walkMediumSpeed"].get<float>();
                attributes.walk_speed_fast = data["attributes"]["walkFastSpeed"].get<float>();
            } catch (...) {
                printf("                                  Failed to get attributes!\n");
                
                ready = false;
                return;
            }

            ready = true;
        }
    }
}