#ifndef PROJECTPLATAFORMCOLLIDER_H
#define PROJECTPLATAFORMCOLLIDER_H

#include "headers/Game/map.h"
#include "headers/Game/Entity.h"

namespace Collider {
    bool checkRight(Map* map, Entity* entity);
    bool checkLeft(Map* map, Entity* entity);
    bool checkUp(Map* map, Entity* entity);
    bool checkDown(Map* map, Entity* entity);
    bool checkImpact (Entity* entity1, Entity* entity2);
}



#endif //PROJECTPLATAFORMCOLLIDER_H
