#pragma once
#include <iostream>

namespace Engine {
    class State {
        public:
            bool running = true;

            State();
            ~State();
    };
}