#include "engine.h"
#ifdef __LINUX__
    #include <unistd.h>
#endif

namespace Engine {
    Engine::State g_state;
    std::vector<Engine::Characters::Character> g_characters;
    std::vector<Engine::Stages::Stage> g_stages;

    int32_t Init(void) {
        Engine::GameInit();

        static const char *vert_shader = "\
        #version 330 core\n\n\
        layout(location = 0) in vec4 position;\n\
        void main(){\n\
            gl_Position = position;\n\
        }";

        static const char *frag_shader = "\
        #version 330 core\n\n\
        layout(location = 0) out vec4 color;\n\
        void main(){\n\
            color = vec4(1.0, 0.0, 0.0, 1.0);\n\
        }";

        GX::g_program = GL::GLCompileShader((const char*)vert_shader, (const char*)frag_shader);

        g_state = Engine::State();
        g_characters = Engine::Characters::Init();
        g_stages = Engine::Stages::Init();

        return 0;
    }
    void GameInit(void) {
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
    }

    void Exit(void) {
        PAD::PADExit();
        GX::GXExit();
        VI::VIExit();
        
        OS::OSHalt("Exiting...\n");
    }
    void ForceExit(void) {
        g_state.running = false;
        OS::OSReport("Force quiting...\n");
        exit(1);
    }
    
    void PrepareTick(void) {
        #ifdef __LINUX__
            usleep(0);
        #endif

        GX::GXDrawBegin();
    }
    bool DoTick(void) {
        // TODO: Game logic?

        GX::GXBegin(GX::GX_TRIANGLES, GX::GX_VTXFMT0, 3);
            GX::GXPosition2f32(-0.5f, -0.5f);
            GX::GXPosition2f32(0.5f, 0.5f);
            GX::GXPosition2f32(0.5f, -0.5f);
        GX::GXEnd();

        GX::GXDrawDone();
        return !(g_state.running && VI::VIShouldCloseWindow());
    }
}