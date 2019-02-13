#include <stdio.h>
#include <stdlib.h>
#ifdef __LINUX__
    #include <signal.h>
#endif
#include "main.h"

void handle_force_quit(sig_t s) {
    Engine::ForceExit();
}

int main(int argc, char *argv[]) {
    #ifdef __LINUX__
        signal(SIGINT, (sighandler_t)handle_force_quit);
    #endif

    #ifndef __DEBUG__
    stdout = freopen("openmelee.log", "w", stdout);
    #endif

    Engine::Init();
    Engine::Characters::Init();
    // Engine::State *state = new Engine::State();

    do {
        Engine::PrepareTick();
        Engine::GUI::DoTick();
    } while(Engine::DoTick());

    Engine::Exit();
    return 0;
}