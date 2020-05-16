#include "headers/Game/Collider/Collider.h"

bool Collider::checkRight(int** map, int x, int y, int height, int &vel) {
    for (int i = 0; i < height ; i++){
        if(map[x+vel][y+i] != 0 && vel > 0)
            return true;
    }
    return false;
}
