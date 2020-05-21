#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <SDL2/SDL.h>
#include "headers/Game/Entity.h"

namespace tools {
    bool testInitFunction(int flag);
    void GetError();
    void CallError(bool* running);
}
struct ToRender {
    SDL_Rect Source;
    SDL_Rect Destiny;
    SDL_Texture* Texture;
};

class SystemTools {
    bool running;
    bool *pRunning = nullptr;
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Event event;
    SDL_Texture* background;
    SDL_Texture* fim;

public:
    bool GetRunning();
    void setRunning(bool newValue);
    SDL_Renderer* GetRenderer();
    SDL_Window* GetWindow();
    SDL_Event* GetEvent();
    void renderBackground();
    SystemTools(int width, int height, float scale, bool isFullScreen);
    ~SystemTools();
};

#endif // TOOLS_H
