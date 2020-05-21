#include "headers/tools.h"
#include "headers/pptexturemanager.h"

void tools::GetError(){
    std::cout <<SDL_GetError() <<std::endl;
}
void tools::CallError(bool *running){
    *running = false;
    GetError();
}
bool tools::testInitFunction(int flag){
    if (flag < 0){
        tools::GetError();
        return false;
    }
    return true;
}

bool SystemTools::GetRunning(){
    return this->running;
}

void SystemTools::setRunning(bool newValue){
    this->running = newValue;
}
SDL_Renderer* SystemTools::GetRenderer(){
    return this->renderer;
}
SDL_Window* SystemTools::GetWindow(){
    return this->window;
}
SDL_Event* SystemTools::GetEvent(){
    return &this->event;
}


SystemTools::SystemTools(int width, int height, float scale, bool isFullScreen){
    this->running = true;
    this->pRunning = &this->running;
    if (isFullScreen)
        this->window = SDL_CreateWindow("Project Plataform",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        width*scale, height*scale, SDL_WINDOW_FULLSCREEN_DESKTOP);
    else
        this->window = SDL_CreateWindow("Project Plataform",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        width*scale, height*scale, 0);
    if (this->window == NULL)
        tools::CallError(this->pRunning);
    else
        this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

    if(this->renderer == NULL)
        tools::CallError(this->pRunning);
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
    this->background = TextureManager::LoadImage("assets/Background.bmp", this->renderer);
    this->fim = TextureManager::LoadImage("assets/fim.bmp", this->renderer);
}

void SystemTools::renderBackground(){
    SDL_RenderCopy(this->renderer, this->background, NULL, NULL);
}

SystemTools::~SystemTools(){
    SDL_RenderClear(this->renderer);
    SDL_RenderCopy(this->renderer, this->fim, NULL, NULL);
    SDL_RenderPresent(this->renderer);
    SDL_Delay(3000);
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
}



