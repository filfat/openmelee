#define __DEBUG__
#define __LINUX__

#include <stdio.h>
#include "main.h"

int main(int argc, char *argv[]) {
    #ifndef __DEBUG__
    stdout = freopen("openmelee.log", "w", stdout);
    #endif

    OS::OSInit();

    OS::OSReport("# ---------------------------------------------\n");
    OS::OSReport("# OpenMelee %s\n", "(Based on SSBM 1.02 NTSC)");

    DVD::DVDInit();
    VI::VIInit();
    PAD::PADInit();
    CARD::CARDInit();

    OS::OSInitAlarm();

    uint32_t mem_size = OS::OSGetPhysicalMemSize();
    OS::OSAllocFromArenaHi((uint32_t)0x1800000, (uint32_t)4);
    OS::OSReport("# Arena Size %d MB\n", mem_size / 1000 / 1000);

    HSD::HSDSetInitParameter(1, 2);
    HSD::HSDAllocateXFB(2, NULL);
    HSD::HSDAllocateFIFO(0x40000);

    GX::GXFifoObj *fifo = GX::GXInit(NULL, NULL);
    HSD::HSDGXSetFifoObj(fifo);

    int32_t res = GX::GXSetMisc(1, 8);

    HSD::HSDVISetUserPostRetraceCallback();
    HSD::HSDVISetBlack(false);

    int32_t time = OS::OSGetTick();
    OS::OSCalendarTime *calendar = new OS::OSCalendarTime();
    OS::OSTicksToCalendarTime(time, calendar);

    OS::OSReport("# GC Calendar Year %d Month %d Day %d\n", calendar->year, calendar->mon, calendar->mday);
    OS::OSReport("#             Hour %d Min %d Sec %d \n", calendar->hour, calendar->min, calendar->sec);

    GX::GXSetCopyClear({ (int8_t)0, (int8_t)0, (int8_t)0, (int8_t)255 }, 0);
    while(!VI::VIShouldCloseWindow()) {
        GX::GXDrawBegin();

        GX::GXDrawDone();
    };

    OS::OSHalt("Exiting...\n");
    return 0;
}