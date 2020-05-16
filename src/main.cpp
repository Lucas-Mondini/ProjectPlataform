#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <headers/tools.h>
#include "headers/Game/map.h"
#include "headers/Game/Entity.h"
#include "headers/Game/Controller.h"
using namespace std;


int main()
{
    if (!tools::testInitFunction(SDL_Init(SDL_INIT_EVERYTHING)))
        return -1;

    SystemTools system(800, 600, 1.5, false);

    Map map(0, system.GetRenderer());
    Entity player(system.GetRenderer(), 300, 400, true);

//    for (int i = 8; i < 15; i++)
//        map.setMap(i, 5, 1);

    while (system.GetRunning()){
        SDL_RenderClear(system.GetRenderer());

        Controller::DataEntry(map.)
        player.Render(system.GetRenderer());

        map.Build(system.GetRenderer());
        SDL_RenderPresent(system.GetRenderer());
        SDL_Delay(1000/60);
    }




    return 0;
}
