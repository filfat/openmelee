#include "stub.h"

__int32_t _stub (char const *function, char const *file, long line) {
    std::cout << "\033[33m(STUBBED)\033[0m " << file << ':' << line << ' ' << function << std::endl;
    return -1;
}