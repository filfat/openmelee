#include "../../libs/termcolor.hpp"

#include "dvd.h"
#include "../stub/stub.h"

#define _HOME_PATH "~/.openmelee"

namespace DVD {
    int32_t DVDInit (void) {
        struct stat info;

        /*if(stat(_HOME_PATH, &info) != 0) {
            std::cout << termcolor::blue << "(DVD)      " << termcolor::reset;
            printf("DVDInit->Info: Creating game folder (%s)\n", _HOME_PATH);
            mkdir(_HOME_PATH, 0777);
        }
        
        if(stat("~/.openmelee/assets/", &info) != 0) {
            std::cout << termcolor::blue << "(DVD)      " << termcolor::reset;
            printf("DVDInit->Warning: assets are missing\n");
            return -1;
        }*/

		return stub();
    }
}