#include "iso.h"

namespace Engine {
    namespace ISO {
        int32_t ExtractISO (const char* path) {
            // std::string cmd = "wit EXTRACT " + std::string(path) + " ~/.openmelee/assets";
            // system(cmd.c_str());

            #ifdef __LINUX__
                system("mkdir ~/.openmelee/assets");
            #endif

            return -1;
        }
    }
}