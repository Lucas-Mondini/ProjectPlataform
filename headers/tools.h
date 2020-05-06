#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <SDL2/SDL.h>

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

public:
    bool GetRunning();
    void setRunning(bool newValue);
    SDL_Renderer* GetRenderer();
    SDL_Window* GetWindow();

    SystemTools(int width, int height, bool isFullScreen);
    ~SystemTools();
};

#endif // TOOLS_H
