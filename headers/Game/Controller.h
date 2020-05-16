#ifndef PPCONTROLLER_H
#define PPCONTROLLER_H

#include "headers/Game/Entity.h"
#include "headers/Game/map.h"

namespace Controller {
    void DataEntry(int **map, int height, int width, Entity entity);
    bool moveX (Entity* entity, int **map);
}

#endif  //PPCONTROLLER_H
