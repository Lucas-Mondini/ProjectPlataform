#include "headers/Game/map.h"
#include "headers/pptexturemanager.h"
#include <time.h>

Map::Map(int level, SDL_Renderer* renderer){
    srand(time(NULL));
    this->pMap = new int*[TOTALMAP_width];
    for (int i = 0; i < TOTALMAP_width; i++)
        pMap[i] = new int[TOTALMAP_height];

    for(int i = 0; i < TOTALMAP_width; i++){
        for (int j = 0; j < TOTALMAP_height; j++){
            pMap[i][j] = this->map[i][j];
        }
    }


    this->texture = TextureManager::LoadImage("assets/grass.bmp", renderer);
    if (level == 0){
        for (int i = 0; i < TOTALMAP_height/10; i++){
            this->setMap(0, i, 1);
            this->setMap(TOTALMAP_width/10-1, i, 1);
        }
        for (int i = 0; i < TOTALMAP_width/10; i++){
            this->setMap(i, 0, 1);
            this->setMap(i, TOTALMAP_height/10-1, 1);
        }
        for (int i = 0; i < 20; i++){
            this->setMap(i, 20, 1);
            this->setMap(i, 40, 1);
            this->setMap(i+20, 40, 1);
        }

        for (int i = 28; i >= 0; i--)
            this->setMap(10+i, i/2+23, 1);

        for (int i = 0; i < 15; i++)
            this->setMap(i+33, 56, 1);
        for (int i = 15; i >= 0; i--){
            this->setMap(40-i, i/2+40, 1);
            this->setMap(25+i, i/2+48, 1);
        }

        for (int i = 0; i < 20; i++)
            this->setMap(i+40, 40, 1);


    }

}

int Map::getWidth(){
    return this->TOTALMAP_width;
}
int Map::getHeight(){
    return this->TOTALMAP_height;
}


void Map::Build(SDL_Renderer* renderer){
    for (int y = 0; y < TOTALMAP_height; y += 10){
        for (int x = 0; x < TOTALMAP_width; x += 10){
            if(this->map[x][y] != 0){
                SDL_Rect src = {0, 0, 32, 32};
                SDL_Rect dst = {x, y, 10, 10};
                SDL_RenderCopy(renderer, this->texture, &src, &dst);
            }
        }
    }
}


void Map::setMap(int x, int y, int value){
    if (!(x > TOTALMAP_width/10 || x < 0 || y > TOTALMAP_height/10 || y < 0)){
        for (int i = x*10 ; i < x*10+10 ; i++){
            for (int j = y*10 ; j < y*10+10 ; j++){
                this->map[i][j] = value;
                this->pMap[i][j] = this->map[i][j];
            }

        }
    }
}
int** Map::getpMap(){
    return this->pMap;
}

Map::~Map(){
    for (int i = 0; i < TOTALMAP_width ; i++){
        delete [] this->pMap[i];
    }

}
