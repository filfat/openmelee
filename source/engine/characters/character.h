#pragma once
#include <stdio.h>
#include <iostream>

// FIXME
#define f32_t float

namespace Engine {
    namespace Characters {
        class CharacterAttributes{
            f32_t walkInitVelocity;
            f32_t walkMaxVelocity;
            f32_t walkAcceleration;
        };

        class Character {
            public:
                Character (const char* path);
                ~Character (void);

            private:
                Engine::Characters::CharacterAttributes attributes;
        };
    };
}