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
                f32_t walk_velocity_init    = 0;
                f32_t walk_velocity_max     = 0;
                f32_t walk_acceleration     = 0;
                f32_t walk_speed_medium     = 0;
                f32_t walk_speed_fast       = 0;

                f32_t run_velocity_init     = 0;
                f32_t run_velocity_max      = 0;
                f32_t run_acceleration      = 0;
        };

        class Character {
            public:
                bool ready = false;
                Character (const char* path);
                // ~Character (void);

            private:
                std::string id;
                std::string name;
                Engine::Characters::CharacterAttributes attributes;
        };
    };
}