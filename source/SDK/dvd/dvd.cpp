#include "dvd.h"
#include "../../../libs/termcolor.hpp"
#include "../../stub/stub.h"
#include "../../engine/iso/iso.h"

#ifdef __LINUX__
    #define HOME_PATH "~/.openmelee"
#elif __WIN32__
    #define HOME_PATH "%%appdata%%/.openmelee"
#else
    #define HOME_PATH "/openmelee"
#endif


namespace DVD {
    int32_t DVDInit (void) {
        if(opendir(HOME_PATH)) {
            std::cout << termcolor::blue << "(DVD)      " << termcolor::reset;
            printf("DVDInit->Info: Creating game folder (%s)\n", HOME_PATH);
            
            system(std::string(std::string("mkdir ") + std::string(HOME_PATH)).c_str());
        }
        
        if(opendir(std::string(std::string(HOME_PATH) + "/assets").c_str())) {
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

            Engine::ISO::ExtractISO(iso_file);
        }

		return stub();
    }
}