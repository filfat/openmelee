#include "os.h"
#include "../stub/stub.h"

namespace OS {
    void OSReport (std::string out, __int32_t u1) {
        stub();
        
        printf((char*)out.c_str());
    }
}