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

    HSD::HSDSetInitParameter(1, 2);                             // 803756f8

    //TODO: Call to unknown function                               80228c4c

    HSD::HSDAllocateXFB(2, NULL);                               // 80374f7c
    HSD::HSDAllocateFIFO(0x40000);                              // 80375194

    res = GX::GXInit();                                         // 8033a780
    HSD::HSDGXSetFifoObj(res);                                  // 80374f60

    res = GX::GXSetMisc(1, 8);                                  // 8033cbc0
    OS::OSGetTick();                                            // 8034c408

    //TODO: Call to unknown function                               8002838c
    //TODO: Call to unknown function                               80019aac

    HSD::HSDVISetUserPostRetraceCallback();                     // 80375934

    //TODO: Call to unknown function                               8037598c

    HSD::HSDVISetBlack(NULL);                                   // 803767a0

    //TODO: Call to unknown function                               8001564c
    //TODO: Call to unknown function                               80015f3c
    //TODO: Call to unknown function                               80018f68
    //TODO: Call to unknown function                               80014d2c
    //TODO: Call to unknown function                               8001c5bc
    //TODO: Call to unknown function                               8001d21c
    //TODO: Call to unknown function                               8001e290
    //TODO: Call to unknown function                               8015fcc0
    //TODO: Call to unknown function                               8001f87c
    //TODO: Call to unknown function                               803a6048
    //TODO: Call to unknown function                               8015fba4

    if (false) {
        // TODO: Branch                                            80160018
    }

    //TODO: Call to unknown function                               8022886c

    OS::OSReport("# ---------------------------------------------\n", (__int32_t *)0x10000);
    OS::OSReport("#    Super Smash Bros. Melee\n", (__int32_t *)0x10000);

    //TODO: Call to unknown function                               8000ad8c
    OS::OSReport("# Distribution %d\n", NULL);

    //TODO: Call to unknown function                               8000adf4
    OS::OSReport("# Language %d\n", NULL);

    OS::OSReport("# DbLevel %d\n", NULL);
    OS::OSReport("# Arena Size %d MB\n", NULL);

    //TODO: Call to unknown function                               800154bc
    OS::OSReport("# ARAM Free Size %d MB\n", NULL);

    //TODO: Call to unknown function                               8000afbc
    //TODO: Call to unknown function                               801692e8

    OS::OSReport("# GC Calendar Year %d Month %d Day %d\n", NULL);
    OS::OSReport("#             Hour %d Min %d Sec %d \n", NULL);

    if (false) {
        // TODO: Branch                                            80160170
    } else {
        
        // TODO: Branch                                            80160168
    }

    OS::OSPanic(NULL, NULL, NULL, NULL);
    return 0;
}