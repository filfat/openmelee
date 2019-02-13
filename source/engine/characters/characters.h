#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <experimental/filesystem>
#include "character.h"

namespace Engine {
    namespace Characters {
        extern std::vector<Engine::Characters::Character> g_characters;

        std::vector<Engine::Characters::Character> Init(void);
    }
}