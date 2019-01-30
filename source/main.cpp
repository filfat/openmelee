#include <stdio.h>

#include "main.h"

int main(int argc, char *argv[]) {
    __int32_t res = DB::DBInit();                               // 80335ec0
    OS::OSInit();                                               // 80342fc8
    VI::VIInit();                                               // 8034ee9c
    res = DVD::DVDInit();                                       // 80337de8
    PAD::PADInit(res);                                          // 8034d7ec
    CARD::CARDInit();                                           // 803530e4

    OS::OSInitAlarm();                                          // 80343720

    //TODO: Call to unknown function                               80225374
    //TODO: Call to unknown function                               8015fda4

    __uint32_t mem_size = OS::OSGetConsoleSimulatedMemSize();   // 80347bf0
    if(mem_size /* FIXME: figure out actual check here */) {
        OS::OSAllocFromArenaHi(0x1800000, 4);
    }

    //TODO: Call to unknown function                               803444c8
    //TODO: Call to unknown function                               803444d0

    HSD::HSD_SetInitParameter(1, 2);                            // 803756f8

    //TODO: Call to unknown function                               80228c4c

    HSD::HSD_AllocateXFB(2, NULL);                              // 80374f7c
    HSD::HSD_AllocateFIFO(0x40000);                             // 80375194

    return 0;
}