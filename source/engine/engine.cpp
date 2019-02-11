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

        HSD::HSDInitComponent();

        HSD::HSDSetInitParameter(HSD::HSD_INIT_XFB_MAX_NUM, 2);
        HSD::HSDSetInitParameter(HSD::HSD_INIT_RENDER_MODE_OBJ, NULL);
        HSD::HSDSetInitParameter(HSD::HSD_INIT_FIFO_SIZE, 0x40000);
        HSD::HSDSetInitParameter(HSD::HSD_INIT_HEAP_MAX_NUM, 4);

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
        glLoadIdentity();//load identity matrix
        glTranslatef(0.0f,0.0f,-4.0f);//move forward 4 units
        glColor3f(0.0f,0.0f,1.0f); //blue color
        glPointSize(10.0f);//set point size to 10 pixels
    }
    bool DoTick(void) {
        // TODO: Game logic?

        GX::GXBegin(GX::GX_LINES, GX::GX_VTXFMT0, 1);
            glVertex3f(1.0f,1.0f,0.0f);//upper-right corner
            glVertex3f(-1.0f,-1.0f,0.0f);//lower-left corner
        GX::GXEnd();

        GX::GXDrawDone();
        return !(VI::VIShouldCloseWindow());
    }
}