#ifndef PPLATTEXTUREMANAGER_H
#define PPLATTEXTUREMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "headers/tools.h"

namespace TextureManager {
    SDL_Texture* LoadImage(const char* fileName, SDL_Renderer* renderer);

    void GetSurfaceSuccessfull(const char* fileName);
    void GetTextureSuccessfull(const char* fileName);

    int TestLoadSurface (SDL_Surface* surface, const char* fileName);
    int TestLoadTexture (SDL_Texture* texture, const char* fileName);

}


#endif // PPTEXTUREMANAGER_H
