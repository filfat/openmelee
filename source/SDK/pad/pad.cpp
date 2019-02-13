#include "pad.h"
#include "../../stub/stub.h"

namespace PAD {
    #ifdef __LINUX__
        libusb_device_handle *g_device_handle = nullptr;
        libusb_context *g_context = nullptr;
    #endif
    PADStatus g_previous_status;

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

    void PADRead (PAD::PADStatus* status) {
        PAD::g_previous_status = *status;

        stub();
    }

    u_int16_t PADButtonUp(PAD::PADStatus status) {
        return ((g_previous_status.button ^ status.button) & (status.button));
    }
    u_int16_t PADButtonDown(PAD::PADStatus status) {
        return ((g_previous_status.button ^ status.button) & (g_previous_status.button));
    }
}