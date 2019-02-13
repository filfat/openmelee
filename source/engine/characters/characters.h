#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <experimental/filesystem>
#include "../../../libs/json.h"
#include "character.h"

namespace Engine {
    namespace Characters {
        extern std::vector<Engine::Characters::Character> g_characters;

        int32_t Init(void);
    }
}