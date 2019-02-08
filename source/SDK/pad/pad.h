#pragma once

#include <iostream>
#ifdef __LINUX__
#include <libusb-1.0/libusb.h>
#endif

namespace PAD {
    #ifdef __LINUX__
        extern libusb_device_handle *g_device_handle;
        extern libusb_context *g_context;
    #endif

    int32_t PADInit (void); // 8034d7ec
    int32_t PADExit (void); // not official
}