#include "../libs/termcolor.hpp"

#include "logger.h"

namespace Logger {
    void Info (const char *scope, const char *out, va_list args) {
        std::cout << termcolor::blue << "(" << scope << ") " << termcolor::reset;
        vprintf(out, args);
    }
}