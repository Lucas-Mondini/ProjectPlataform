#include "headers/Game/map.h"
#include "headers/pptexturemanager.h"

Map::Map(int level, SDL_Renderer* renderer){
    this->texture = TextureManager::LoadImage("assets/grass.bmp", renderer);
    if (level == 0){
        for (int x = 0; x < TOTALMAP_width; x++){
            for (int y = 0; y < TOTALMAP_height; y++){
                if (x == 0 || x == (TOTALMAP_width - 10) || y == 0 || y == (TOTALMAP_height - 10))
                    this->map[x][y] = 1;
                else
                    this->map[x][y] = 0;

                if(this->map[x][y] == 1 && x < TOTALMAP_width - 10 && y < TOTALMAP_height - 10)
                    this->map[x+10][y+10] = -1;
            }
        }
    }
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
            }

        }
    }
}
int* Map::getMap(){

}

Map::~Map(){

}
