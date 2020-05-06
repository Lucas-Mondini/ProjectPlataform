#include "headers/pptexturemanager.h"

SDL_Texture* TextureManager::LoadImage(const char* fileName, SDL_Renderer* renderer){
    SDL_Surface* surface = SDL_LoadBMP(fileName);
    if (TestLoadSurface(surface, fileName) == NULL){
        return NULL;
    }


    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (TestLoadTexture(texture, fileName) == NULL){
        return NULL;
    }

    SDL_FreeSurface(surface);

    return  texture;
}

void TextureManager::GetSurfaceSuccessfull(const char* fileName){
    std::cout<<"Surface of fileName: \" "<<fileName <<" \" Loaded!\n";
}
void TextureManager::GetTextureSuccessfull(const char* fileName){
    std::cout <<"Texture : \" "<< fileName <<" \" Created!\n";
}

int TextureManager::TestLoadSurface (SDL_Surface* surface, const char* fileName){
    if (surface == NULL){
        tools::GetError();
        return NULL;
    }
    else{
        GetSurfaceSuccessfull(fileName);
        return 1;
    }
}

int TextureManager::TestLoadTexture (SDL_Texture* texture, const char* fileName){
    if (texture == NULL){
        tools::GetError();
        return NULL;
    }
    else{
        GetTextureSuccessfull(fileName);
        return 1;
    }
}
