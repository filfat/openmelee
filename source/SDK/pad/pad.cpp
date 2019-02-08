#include "pad.h"
#include "../../stub/stub.h"

namespace PAD {
    #ifdef __LINUX__
        libusb_device_handle *g_device_handle;
        libusb_context *g_context;
    #endif

    int32_t PADInit (void) {
        #ifdef __LINUX__
            g_device_handle = nullptr;
            g_context = nullptr;

            libusb_init(&g_context);
            // TODO: ?
            return 0;
        #endif

        return stub();
    }

    int32_t PADExit (void) {
        #ifdef __LINUX__
            libusb_exit(g_context);
        #endif
        
        return stub();
    }
}