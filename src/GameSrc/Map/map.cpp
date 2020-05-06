#include "headers/Game/map.h"
#include "headers/pptexturemanager.h"

Map::Map(int level, SDL_Renderer* renderer){
    this->texture = TextureManager::LoadImage("assets/grass.bmp", renderer);
    if (level == 0){
        for (int i = 0; i < 80; i++){
            for (int j = 0; j < 60; j++){
                if (i == 0 || i == 79 || j == 0 || j == 59)
                    this->map[i][j] = 1;
                else
                    this->map[i][j] = 0;
            }
        }
    }
}

void Map::Build(SDL_Renderer* renderer){
    for (int y = 600; y >= 540; y -= 10){
        for (int x = 0; x < 80; x += 10){
            if(this->map[x/10][y/10] != 0){
                SDL_Rect src = {0, 0, 32, 32};
                SDL_Rect dst = {x, y, 10, 10};
                SDL_RenderCopy(renderer, this->texture, &src, &dst);
            }
        }
    }
}

Map::~Map(){

}
