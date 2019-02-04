#include "../../libs/termcolor.hpp"

#include "dvd.h"
#include "../../stub/stub.h"

#define _HOME_PATH "~/.openmelee"

namespace DVD {
    int32_t DVDInit (void) {
        struct stat info;

        if(stat(_HOME_PATH, &info) != 0) {
            std::cout << termcolor::blue << "(DVD)      " << termcolor::reset;
            printf("DVDInit->Info: Creating game folder (%s)\n", _HOME_PATH);
            
            #ifdef __LINUX__
                system("mkdir ~/.openmelee");
                system("mkdir ~/.openmelee/assets");
            #endif
        }
        
        if(stat("~/.openmelee/assets/", &info) != 0) {
            std::cout << termcolor::blue << "(DVD)      " << termcolor::reset;
            printf("DVDInit->Warning: assets are missing\n");

            sfd_Options options = {
                "Open SSBM iso file",
                "",
                "ISO File",
                "*.iso"
            };

            const char *iso_file = sfd_open_dialog(&options);

            if(!iso_file) {
                std::cout << termcolor::blue << "(DVD)      " << termcolor::reset;
                printf("DVDInit->sfd->Erorr: %s\n", sfd_get_error());

                return -1;
            }
        }

		return stub();
    }
}