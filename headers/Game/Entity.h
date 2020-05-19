#ifndef Entity_H
#define Entity_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "headers/pptexturemanager.h"
#include "headers/tools.h"

struct Position {
    int x;
    int y;
};

struct Velocity {
    int Velx = 0;
    int Vely = 0;
};

struct MoveKeys {
    bool up;
    bool down;
    bool left;
    bool right;
    bool z;
};


enum State {
    IdleR,
    IdleL,
    RunningR,
    RunningL,
    JumpR,
    JumpL,
    AtackR,
    AtackL
};


class Entity
{
    SDL_Rect source;
    SDL_Rect destiny;

    int life;
    bool alive;
    bool playable;

    Position position;
    State Entitystate;
    SDL_Texture* actualTexture;
    SDL_Texture *Textures[20];

    void moveX();
    void moveY();
public:
    Velocity velocity;
    MoveKeys movekeys;

    Entity(SDL_Renderer* renderer, int x, int y, bool playable);
    void Render(SDL_Renderer* renderer);
    void move(int direction);

    void setPosition(Position newPosition);
    void setVelocity(Velocity newVelocity);
    void setDimension(SDL_Rect newDimension);


    SDL_Texture* GetTexture ();
    Position getPosition();
    SDL_Rect getEntityDimensions();
    Velocity getVelocity ();
};

#endif // Entity_H
