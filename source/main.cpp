#include <stdio.h>

#include "main.h"

int main(int argc, char *argv[]) {
    __int32_t res = DB::DBInit();
    OS::OSInit();

    OS::OSReport("# ---------------------------------------------\n");
    OS::OSReport("# OpenMelee %s\n", "(Based on SSBM NTSC 1.02)");

    VI::VIInit();                                               // 8034ee9c
    res = DVD::DVDInit();                                       // 80337de8
    PAD::PADInit(res);                                          // 8034d7ec
    CARD::CARDInit();                                           // 803530e4

    OS::OSInitAlarm();

    //TODO: Call to unknown function                               80225374
    //TODO: Call to unknown function                               8015fda4

    __uint32_t mem_size = OS::OSGetPhysicalMemSize();
    if(mem_size /* FIXME: figure out actual check here */) {
        OS::OSAllocFromArenaHi((__uint32_t)0x1800000, (__uint32_t)4);
        OS::OSReport("# Arena Size %d MB\n", mem_size / 1000 / 1000);
    }

    //TODO: Call to unknown function                               803444c8
    //TODO: Call to unknown function                               803444d0

    HSD::HSDSetInitParameter(1, 2);

    //TODO: Call to unknown function                               80228c4c

    HSD::HSDAllocateXFB(2, NULL);
    HSD::HSDAllocateFIFO(0x40000);

    GX::GXFifoObj *fifo = GX::GXInit(NULL, NULL);
    HSD::HSDGXSetFifoObj(fifo);

    res = GX::GXSetMisc(1, 8);
    __int32_t time = OS::OSGetTick();

    //TODO: Call to unknown function                               8002838c
    //TODO: Call to unknown function                               80019aac

    HSD::HSDVISetUserPostRetraceCallback();                     // 80375934

    //TODO: Call to unknown function                               8037598c

    HSD::HSDVISetBlack(false);

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

    if (false) {
        // TODO: Branch                                            80160170
    } else {

        // TODO: Branch                                            80160168
    }

    OS::OSPanic(__FILE__, __LINE__, "TODO");
    return 0;
}