#include "../../libs/termcolor.hpp"

#include "stub.h"

int32_t _stub (char const *function, char const *file, long line) {
    std::cout << termcolor::yellow << "(STUBBED)  " << termcolor::reset << file << ':' << line << ' ' << function << std::endl;
    return NULL;
}