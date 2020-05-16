#include "headers/Game/Controller.h"
#include "headers/Game/Collider/Collider.h"

bool Controller::moveX(Entity* entity, int **map){
    if (!(Collider::checkRight(map, entity->getPosition().x+1, entity->getPosition().y, entity->getEntityDimensions().h, entity->velocity.Velx))){
        entity->setPosition({entity->getPosition().x+entity->getVelocity().Velx, entity->getPosition().y});
        return true;
    }
    return false;
}

void Controller::DataEntry(int **map, int Map_height, int Map_width, Entity entity){
        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        if  (keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_RIGHT]){
            entity.velocity.Velx++;
            if (!Controller::moveX(&entity, map)){
                entity.velocity.Velx = 0;
            }
        }

        if  (keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_LEFT]){
            entity.velocity.Velx--;
            if (!Controller::moveX(&entity, map)){
                entity.velocity.Velx = 0;
            }
        }
}
