#ifndef PROJECTPLATAFORMMAP_H
#define PROJECTPLATAFORMMAP_H

#include <SDL2/SDL.h>

class Map{
    const static int TOTALMAP_width = 800, TOTALMAP_height = 600;
    int map [TOTALMAP_width][TOTALMAP_height];
    SDL_Texture* texture;
public:
    Map(int level, SDL_Renderer* renderer);
    void Build(SDL_Renderer* renderer);
    void setMap(int x, int y, int value);
    int* getMap();
    ~Map();
};

#endif //PROJECTPLATAFORMMAP_H
