#pragma once
#include <iostream>

namespace Engine {
    class State {
        private:
            std::string current_view;

        public:
            State(std::string default_view = "openmelee:title");
            ~State();
    };
}