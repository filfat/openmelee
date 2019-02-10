#include <stdio.h>
#include "main.h"

int main(int argc, char *argv[]) {
    #ifndef __DEBUG__
    stdout = freopen("openmelee.log", "w", stdout);
    #endif

    Engine::Init();
    // Engine::State *state = new Engine::State();

    do {
        Engine::PrepareTick();
        Engine::GUI::DoTick();
    } while(Engine::DoTick());

    Engine::Exit();
    return 0;
}