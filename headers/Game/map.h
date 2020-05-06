#ifndef PROJECTPLATAFORMMAP_H
#define PROJECTPLATAFORMMAP_H

#include <SDL2/SDL.h>

class Map{
    int map [80][60];
    SDL_Texture* texture;
public:
    Map(int level, SDL_Renderer* renderer);
    void Build(SDL_Renderer* renderer);
    ~Map();
};

#endif //PROJECTPLATAFORMMAP_H
