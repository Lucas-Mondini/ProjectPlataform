#include "headers/Game/Controller.h"
#include "headers/Game/Collider/Collider.h"
#include "headers/Game/map.h"







void Controller::DataEntry(Map* map, Entity* entity){
        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        if (!entity->getPlayable()){
            if (entity->R){
                entity->velocity.Velx = 1;
                entity->setState(RunningR);
            }
            else{
                entity->velocity.Velx = -1;
                entity->setState(RunningL);
            }
            if(Collider::checkRight(map, entity))
                entity->R = false;
            else if (Collider::checkLeft(map, entity))
                entity->R = true;
            if(entity->getAlive())
                entity->move(1);
        }



        if  ((keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_RIGHT]) && entity->getPlayable() && entity->getAlive()){
            entity->setState(State::RunningR);
            entity->velocity.Velx = 2;
            if (!Collider::checkRight(map, entity)){
                    entity->move(1);
            }

        }
        else if  ((keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_LEFT]) && entity->getPlayable() && entity->getAlive()){
            entity->setState(State::RunningL);
            entity->velocity.Velx = -2;
            if (!Collider::checkLeft(map, entity))
                entity->move(1);
        }
        else {
            if (entity->getState() == State::RunningR)
                entity->setState(State::IdleR);
            else if (entity->getState() == State::RunningL)
                entity->setState(State::IdleL);

        }

        if  ((keystate[SDL_SCANCODE_W] || keystate[SDL_SCANCODE_UP]) && entity->getPlayable() && entity->getAlive()){
                if (!Collider::checkUp(map, entity))
                    if(entity->getCanJump()){
                        entity->jumpCalc();
                        entity->move(3);
                    }
        }
                entity->velocity.Vely += 2;
                if(entity->velocity.Vely > 2)
                    entity->velocity.Vely = 2;

                if (!Collider::checkDown(map, entity)){
                    entity->move(2);
                    entity->setCanJump(false);
                }
                else {
                    entity->setCanJump(true);
                }
        if ((keystate[SDL_SCANCODE_LSHIFT]) && entity->getPlayable() && entity->getAlive()) {
            if(entity->getCanAttack()){
                entity->setAttacking(true);
                entity->takeTime();
            }
        }

        if(keystate[SDL_SCANCODE_P])
            entity->killedAll();

        entity->processJump();
        entity->velocity.Velx = 0;
        entity->velocity.Vely = 0;
        entity->timeInAnimation+= 0.25;


}
