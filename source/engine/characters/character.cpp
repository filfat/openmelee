#include "character.h"
#include "../../stub/stub.h"
#include "../../../libs/termcolor.hpp"

namespace Engine {
    namespace Characters {
        Character::Character (const char* path) {
            std::cout << termcolor::blue << "(ENGINE)   " << termcolor::reset;
            printf("Characters->Character->Loading: \"%s\"...\n", path);
            stub();
        }
        Character::~Character (void) {
            stub();
        }
    }
}