#include "os.h"

namespace OS {
    void OSReport (std::string out, __int32_t u1) {
        printf((char*)out.c_str());
    }
}