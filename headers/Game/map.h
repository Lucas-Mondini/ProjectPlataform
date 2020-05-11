#ifndef PROJECTPLATAFORMMAP_H
#define PROJECTPLATAFORMMAP_H

#include <SDL2/SDL.h>

class Map{
    const static int TOTALMAP_height = 80, TOTALMAP_width = 60;
    int map [TOTALMAP_height][TOTALMAP_width];
    SDL_Texture* texture;
public:
    Map(int level, SDL_Renderer* renderer);
    void Build(SDL_Renderer* renderer);
    ~Map();
};

#endif //PROJECTPLATAFORMMAP_H
