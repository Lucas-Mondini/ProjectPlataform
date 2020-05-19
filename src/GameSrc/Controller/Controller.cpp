#include "headers/Game/Controller.h"
#include "headers/Game/Collider/Collider.h"
#include "headers/Game/map.h"







void Controller::DataEntry(Map* map, Entity* entity){
        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        if  ((keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_RIGHT])){
            if (!Collider::checkRight(map, entity)){
                    entity->velocity.Velx++;
                if (entity->velocity.Velx > 2)
                    entity->velocity.Velx = 2;
                    entity->move(1);
            }

        }

        if  ((keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_LEFT])){
            if (!Collider::checkLeft(map, entity))
                entity->velocity.Velx--;
            if (entity->velocity.Velx < 2)
                entity->velocity.Velx = -2;
                entity->move(1);
        }

        entity->velocity.Velx = 0;


}
