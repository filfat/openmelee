#pragma once
#include <iostream>
#ifdef __LINUX__
#include <libusb-1.0/libusb.h>
#endif

#define PAD_BUTTON_LEFT         0x0001
#define PAD_BUTTON_RIGHT        0x0002
#define PAD_BUTTON_DOWN         0x0004
#define PAD_BUTTON_UP           0x0008
#define PAD_TRIGGER_Z           0x0010
#define PAD_TRIGGER_R           0x0020
#define PAD_TRIGGER_L           0x0040
#define PAD_BUTTON_A            0x0100
#define PAD_BUTTON_B            0x0200
#define PAD_BUTTON_X            0x0400
#define PAD_BUTTON_Y            0x0800
#define PAD_BUTTON_MENU         0x1000
#define PAD_ERR_NONE            0
#define PAD_ERR_NO_CONTROLLER   -1
#define PAD_ERR_NOT_READY       -2
#define PAD_ERR_TRANSFER        -3

namespace PAD {
    typedef struct {
        u_int16_t button;
        int8_t stickX;
        int8_t stickY;
        int8_t substickX;
        int8_t substickY;
        u_int8_t triggerLeft;
        u_int8_t triggerRight;
        u_int8_t analogA;
        u_int8_t analogB;
        int8_t err;
    } PADStatus;

    #ifdef __LINUX__
        extern libusb_device_handle *g_device_handle;
        extern libusb_context *g_context;
    #endif
    extern PADStatus g_previous_status;

    int32_t PADInit (void); // 8034d7ec
    int32_t PADExit (void); // not official

    void PADRead(PAD::PADStatus* status);
    u_int16_t PADButtonUp(PAD::PADStatus status);
    u_int16_t PADButtonDown(PAD::PADStatus status);
}