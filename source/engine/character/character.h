#pragma once
#include <stdio.h>
#include <iostream>
#include "../../stub/stub.h"

// FIXMR
#define f32_t float

namespace Engine {
    class CharacterAttributes{
        f32_t walkIntVelocity;
        f32_t walkMaxVelocity;
        f32_t walkAcceleration;
    };

    class Character {
        public:
            Character (std::string id);
            ~Character (void);

        private:
            Engine::CharacterAttributes attributes;
    };
}