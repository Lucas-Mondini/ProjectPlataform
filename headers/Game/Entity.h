#ifndef Entity_H
#define Entity_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "headers/pptexturemanager.h"
#include "headers/tools.h"
#include <time.h>
#include <chrono>
#include <thread>

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
};


class Entity
{
    SDL_Rect source;
    SDL_Rect destiny;


    int attackInit;
    int now;


    int life;
    bool alive;
    bool playable;
    bool attacking;
    bool canattack;
    int FPS;
    int lastFPS;
    bool jumping;
    bool canJump;
    time_t timer;

    int killCount;
    bool KilledAll;

    Position position;
    State Entitystate;
    SDL_Texture* actualTexture;
    SDL_Texture *Textures[6];

    void moveX();
    void moveY();
    void Jump();
public:
    Velocity velocity;
    MoveKeys movekeys;
    float timeInAnimation;
    bool R;
    int jumpDestiny;

    Entity(SDL_Renderer* renderer, int x, int y, bool playable);
    void Render(SDL_Renderer* renderer);
    void move(int direction);
    void processJump();
    void hit();
    void kill();
    void killedAll();
    void jumpCalc();
    void processAttack();
    void takeTime();
    void clowdown();

    void setPosition(SDL_Rect newPosition);
    void setVelocity(Velocity newVelocity);
    void setDimension(SDL_Rect newDimension);
    void setJumping(bool newJumping);
    void setCanJump(bool newCanJump);
    void setAttacking(bool newattacking);
    void setState(State newState);

    bool getCanAttack();
    bool getKilledAll();
    int getKillCount();
    bool getAlive();
    State getState();
    bool getPlayable();
    bool getAttacking();
    bool getCanJump();
    bool getJumping();
    SDL_Texture* GetTexture ();
    Position getPosition();
    SDL_Rect getEntityDimensions();
    Velocity getVelocity ();
};

#endif // Entity_H
