#include "engine.h"

namespace Engine {
    int32_t Init(void) {
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

        /*int32_t res = */ GX::GXSetMisc(1, 8);

        HSD::HSDVISetUserPostRetraceCallback();
        HSD::HSDVISetBlack(false);

        int32_t time = OS::OSGetTick();
        OS::OSCalendarTime *calendar = new OS::OSCalendarTime();
        OS::OSTicksToCalendarTime(time, calendar);

        OS::OSReport("# GC Calendar Year %d Month %d Day %d\n", calendar->year, calendar->mon, calendar->mday);
        OS::OSReport("#             Hour %d Min %d Sec %d \n", calendar->hour, calendar->min, calendar->sec);

        GX::GXSetCopyClear({ 0, 0, 0, 255 }, 0);

        return 0;
    }
    void Exit(void) {
        PAD::PADExit();
        
        OS::OSHalt("Exiting...\n");
    }
    
    void PrepareTick(void) {
        GX::GXDrawBegin();
    }
    bool DoTick(void) {
        // TODO: Game logic?

        GX::GXDrawDone();
        return !(VI::VIShouldCloseWindow());
    }
}