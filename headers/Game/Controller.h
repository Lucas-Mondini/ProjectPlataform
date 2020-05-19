#ifndef PPCONTROLLER_H
#define PPCONTROLLER_H

#include "headers/Game/Entity.h"
#include "headers/Game/map.h"

struct MapSize{
    int w;
    int h;
};

namespace Controller {
    void DataEntry(Map* map, Entity* entity);
}

#endif  //PPCONTROLLER_H
