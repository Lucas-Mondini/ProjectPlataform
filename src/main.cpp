#define SDL_MAIN_HANDLED
#include <iostream>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <headers/tools.h>
#include "headers/Game/map.h"
#include "headers/Game/Entity.h"
#include "headers/Game/Controller.h"
#include "headers/Game/Collider/Collider.h"
using namespace std;


int main()
{
    srand(time(NULL));
    if (!tools::testInitFunction(SDL_Init(SDL_INIT_EVERYTHING)))
        return -1;

    SystemTools system(800, 600, 1, false);


    Map map(0, system.GetRenderer());
    Entity player(system.GetRenderer(), 10, 10, true);
    int enemyNum = 50;
        Entity *comunista[enemyNum];
        for (int i = 0; i < enemyNum; i++){
            comunista[i] = new Entity(system.GetRenderer(), (i+rand()%20)+rand()%300, 50, false);
            comunista[i]->R = rand()%2;
        }


    int fps = 0;
    while (system.GetRunning()){
        system.renderBackground();
        SDL_RenderClear(system.GetRenderer());

        system.renderBackground();

        SDL_PollEvent(system.GetEvent());
        Controller::DataEntry(&map, &player);
        for (int i = 0; i < enemyNum; i++)
            Controller::DataEntry(&map, comunista[i]);
        for (int i = 0; i < enemyNum; i++)
            Collider::checkImpact(&player, comunista[i]);

        player.Render(system.GetRenderer());
        for (int i = 0; i < enemyNum; i++)
            comunista[i]->Render(system.GetRenderer());

        map.Build(system.GetRenderer());
        SDL_RenderPresent(system.GetRenderer());
        SDL_Delay(1000/60);

        if(fps++ >= 60)
            fps = 0;
        if(!player.getAlive()){
            system.setRunning(false);
        }
        if(player.getKilledAll())
            system.setRunning(false);

    }

    for (int i = 0; i < enemyNum; i++)
        delete [] comunista[i];





    return 0;
}
