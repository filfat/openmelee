#include <chrono>
#include "engine.h"
#include "../stub/stub.h"

// FIXME
#ifndef f32_t
#define f32_t float
#endif

using namespace std::chrono_literals;

namespace Engine {
    std::vector<Engine::Characters::Character> g_characters;
    std::vector<Engine::Stages::Stage> g_stages;
    constexpr std::chrono::nanoseconds timestep(16ms); // TODO: Handle 144, 244, and "unlimited" (999)

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
        OS::OSReport("Force quiting...\n");
        exit(1);
    }

    void Start() {
        using clock = std::chrono::high_resolution_clock;

        Engine::State state;
        Engine::State previous_state;

        std::chrono::nanoseconds lag(0ns);
        auto time_start = clock::now();

        while(state.running && !VI::VIShouldCloseWindow()) {
            auto delta_time = clock::now() - time_start;
            time_start = clock::now();
            lag += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);

            while(lag >= timestep) {
                lag -= timestep;

                previous_state = state;
                Engine::Update(state);
            }

            auto alpha = (f32_t) lag.count() / timestep.count();
            auto interpolated_state = Engine::Interpolate(state, previous_state, alpha);

            Engine::Render(interpolated_state);
        }
    }

    void Update(State &state) {
        PAD::PADStatus input;
        PAD::PADRead(&input);
        stub();
    }
    void Render(const State &state) {
        GX::GXDrawBegin();
            GX::GXBegin(GX::GX_TRIANGLES, GX::GX_VTXFMT0, 3);
                GX::GXPosition2f32(-0.5f, -0.5f);
                GX::GXPosition2f32(0.5f, 0.5f);
                GX::GXPosition2f32(0.5f, -0.5f);
            GX::GXEnd();
        GX::GXDrawDone();

        stub();
    }
    State Interpolate(const State &current, const State &previous, f32_t alpha) {
        stub();
        return current;
    }
}