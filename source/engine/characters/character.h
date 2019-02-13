#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>

// FIXME
#define f32_t float

namespace Engine {
    namespace Characters {
        class CharacterAttributes{
            public:
                f32_t walkInitVelocity = 0;
                f32_t walkMaxVelocity = 0;
                f32_t walkAcceleration = 0;
        };

        class Character {
            public:
                Character (const char* path);
                // ~Character (void);

            private:
                std::string id;
                std::string name;
                Engine::Characters::CharacterAttributes attributes;
        };
    };
}