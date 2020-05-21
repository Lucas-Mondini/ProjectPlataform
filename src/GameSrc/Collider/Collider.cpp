#include "headers/Game/Collider/Collider.h"

bool Collider::checkRight(Map *map, Entity* entity) {
        for (int i = 0; i < entity->getEntityDimensions().h ; i++){
            if (map->getpMap()[entity->getEntityDimensions().x+ entity->getEntityDimensions().w + 5 + entity->getVelocity().Velx/2][entity->getEntityDimensions().y+i] != 0)
                return true;
            }

    return false;
}

bool Collider::checkLeft(Map* map, Entity* entity) {
        for (int i = 0; i < entity->getEntityDimensions().h ; i++){
            if (map->getpMap()[entity->getEntityDimensions().x + entity->getVelocity().Velx/2][entity->getEntityDimensions().y+i] != 0)
                return true;
            }

    return false;
}
bool Collider::checkUp(Map* map, Entity* entity) {
    for (int i = 0; i < entity->getEntityDimensions().w; i++){
        if (map->getpMap()[entity->getEntityDimensions().x + i][entity->getEntityDimensions().y + entity->getVelocity().Vely/2] != 0)
            return true;
    }
    return false;
}


bool Collider::checkDown(Map* map, Entity* entity) {
    for (int i = 0; i < entity->getEntityDimensions().w; i++){
        if (map->getpMap()[entity->getEntityDimensions().x + i][entity->getEntityDimensions().y + entity->getEntityDimensions().h] != 0)
            return true;
    }
    return false;
}

bool Collider::checkImpact (Entity* entity1, Entity* entity2){
    SDL_Rect rect1 = entity1->getEntityDimensions();
    SDL_Rect rect2 = entity2->getEntityDimensions();
    if (SDL_HasIntersection(&rect1, &rect2) && entity1->getAttacking() && entity1->getAlive() && entity2->getAlive()){
        entity2->hit();
        entity1->kill();
        return true;
    }
    else if (SDL_HasIntersection(&rect1, &rect2) && !entity1->getAttacking() && entity1->getAlive() && entity2->getAlive()){
        entity1->hit();
        return true;
    }
    return false;
}


