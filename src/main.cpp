#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <headers/tools.h>
#include "headers/Game/map.h"
using namespace std;


int main()
{
    if (!tools::testInitFunction(SDL_Init(SDL_INIT_EVERYTHING)))
        return -1;

    SystemTools system(800, 600, false);


    cout <<"system initialized!" <<endl;

    Map map(0, system.GetRenderer());

    while (system.GetRunning()){
        SDL_RenderClear(system.GetRenderer());

        map.Build(system.GetRenderer());
        SDL_RenderPresent(system.GetRenderer());
        SDL_Delay(1000/60);
    }

    system.~SystemTools();



    return 0;
}
