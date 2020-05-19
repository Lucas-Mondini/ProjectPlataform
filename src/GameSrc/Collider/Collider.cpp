#include "headers/Game/Collider/Collider.h"

bool Collider::checkRight(Map *map, Entity* entity) {
    if ((entity->getEntityDimensions().x + entity->velocity.Velx > map->getWidth()))
        return true;
        for (int i = 0; i < entity->getEntityDimensions().h ; i++){
            if (map->getpMap()[entity->getEntityDimensions().x + entity->getVelocity().Velx][entity->getEntityDimensions().y+i] > 0)
                return true;
            }

    return false;
}

bool Collider::checkLeft(Map* map, Entity* entity) {
    if ((entity->getEntityDimensions().x + entity->velocity.Velx < 0))
        return true;
        for (int i = 0; i < entity->getEntityDimensions().h ; i++){
            if (map->getpMap()[entity->getEntityDimensions().x + entity->getVelocity().Velx][entity->getEntityDimensions().y+i] > 0)
                return true;
            }

    return false;
}
