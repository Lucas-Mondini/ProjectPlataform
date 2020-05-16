#ifndef PROJECTPLATAFORMCOLLIDER_H
#define PROJECTPLATAFORMCOLLIDER_H

#include "headers/Game/map.h"
#include "headers/Game/Entity.h"

namespace Collider {
    bool checkRight(int** map, int x, int y, int height, int &vel);
}



#endif //PROJECTPLATAFORMCOLLIDER_H
