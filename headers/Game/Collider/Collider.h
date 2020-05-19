#ifndef PROJECTPLATAFORMCOLLIDER_H
#define PROJECTPLATAFORMCOLLIDER_H

#include "headers/Game/map.h"
#include "headers/Game/Entity.h"

namespace Collider {
    bool checkRight(Map* map, Entity* entity);
    bool checkLeft(Map* map, Entity* entity);
}



#endif //PROJECTPLATAFORMCOLLIDER_H
