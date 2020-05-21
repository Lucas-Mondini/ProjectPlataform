#include "headers/Game/Entity.h"
#include "headers/Game/Controller.h"
#include "headers/Game/Collider/Collider.h"



Entity::Entity(SDL_Renderer* renderer, int x, int y, bool playable)
{
    this->playable = playable;
    if (playable){
        this->Textures[0] = TextureManager::LoadImage("assets/idle/FoxIdleRSpritesheet.bmp", renderer);
        this->Textures[1] = TextureManager::LoadImage("assets/idle/FoxIdleLSpritesheet.bmp", renderer);

        this->Textures[2] = TextureManager::LoadImage("assets/run/FoxRunningRSpritesheet.bmp", renderer);
        this->Textures[3] = TextureManager::LoadImage("assets/run/FoxRunningLSpritesheet.bmp", renderer);

        this->Textures[4] = TextureManager::LoadImage("assets/bitcoin.bmp", renderer);
    }
    else {
        this->Textures[0] = TextureManager::LoadImage("assets/idle/CommieIdleRSpritesheet.bmp", renderer);
        this->Textures[1] = TextureManager::LoadImage("assets/idle/CommieIdleLSpritesheet.bmp", renderer);

        this->Textures[2] = TextureManager::LoadImage("assets/run/CommieRunningRSpritesheet.bmp", renderer);
        this->Textures[3] = TextureManager::LoadImage("assets/run/CommieRunningLSpritesheet.bmp", renderer);

        this->Textures[4] = TextureManager::LoadImage("assets/Communism.bmp", renderer);
        this->R = true;
    }
    this->Textures[5] = TextureManager::LoadImage("assets/Rip.bmp", renderer);

    this->canattack = true;
    this->killCount = 0;
    this->KilledAll = false;
    this->timeInAnimation = 0;
    this->actualTexture = this->Textures[0];

    this->alive = true;
    if (playable)
        this->life = 300;
    else
        this->life = 1;
    this->velocity.Velx = this->velocity.Vely = 0;
    this->takeTime();
    this->canJump = false;
    this->FPS = 0;
    this->jumping = false;
    this->Entitystate = State::IdleR;
    this->position.x = x;
    this->position.y = y;
    this->source = {0, 0, 17, 16};
    this->destiny = {this->position.x, this->position.y, 17, 16};
}


void Entity::processJump(){
        if(jumping && this->jumpDestiny < this->destiny.y)
            this->destiny.y = this->destiny.y -8;
        else if (this->jumpDestiny > this->destiny.y)
            this->jumping = false;
}
void Entity::processAttack(){
    canattack = false;
    this->now = SDL_GetTicks();
    int duration = now - attackInit;
    if(duration > 1000){
        attacking = false;
    }
}
void Entity::takeTime(){
    this->attackInit = SDL_GetTicks();
}
void Entity::clowdown(){
    this->now = SDL_GetTicks();
    int duration = now - attackInit;
    if (duration > 3000){
        canattack = true;
    }
}


void Entity::move(int direction){
    switch (direction) {
    case 1:
        moveX();
        this->velocity.Velx = 0;
        break;
    case 2:
        moveY();
        this->velocity.Vely = 0;
        break;
    case 3:
        Jump();
        break;
    }
}

void Entity::moveX(){
    this->destiny.x = this->velocity.Velx + this->destiny.x;

}
void Entity::moveY(){
    this->destiny.y = this->velocity.Vely + this->destiny.y;
}
void Entity::Jump(){
    if(playable)
        this->jumping = true;
}
void Entity::hit(){
    this->life--;
}
void Entity::kill(){
    this->killCount++;
}
void Entity::killedAll(){
    this->KilledAll = true;
}
void Entity::jumpCalc(){
    this->jumpDestiny = this->destiny.y - 60;
}




bool Entity::getCanAttack(){
    return this->canattack;
}
bool Entity::getJumping(){
    return this->jumping;
}

Position Entity::getPosition(){
    return this->position;
}

SDL_Rect Entity::getEntityDimensions(){
    return this->destiny;
}
Velocity Entity::getVelocity (){
    return this->velocity;
}
bool Entity::getCanJump(){
    return this->canJump;
}
bool Entity::getAttacking(){
    return this->attacking;
}
bool Entity::getPlayable(){
    return this->playable;
}
State Entity::getState(){
    return this->Entitystate;
}
bool Entity::getAlive(){
    return this->alive;
}
int Entity::getKillCount(){
    return this->killCount;
}
bool Entity::getKilledAll(){
    return this->KilledAll;
}


void Entity::setState(State newState){
    this->Entitystate = newState;
}

void Entity::setAttacking(bool newattacking){
    this->attacking = newattacking;
}
void Entity::setCanJump(bool newCanJump){
    this->canJump = newCanJump;
}

void Entity::setJumping(bool newJumping){
    this->jumping = newJumping;
}
void Entity::setPosition(SDL_Rect newPosition){
    this->destiny = newPosition;
}
void Entity::setVelocity(Velocity newVelocity){
    this->velocity = newVelocity;
}
void Entity::setDimension(SDL_Rect newDimension){
    this->source = newDimension;
}

void Entity::Render(SDL_Renderer* renderer){
    if (this->FPS > 60)
        this->FPS = 0;
    this->actualTexture = this->Textures[Entitystate];
    if (this->Entitystate == State::IdleL ||  this->Entitystate == State::IdleR){
        this->source.y = ((int)timeInAnimation%8)*16;
        this->source.w = 17;
    }
    else {
        this->source.y = ((int)timeInAnimation%8)*16;
        this->source.w = 19;
    }
    if(this->life < 0)
        this->alive = false;
    if(this->attacking)
        processAttack();
    else
        clowdown();




    if(!this->playable)
        SDL_RenderCopy(renderer, this->Textures[4], NULL, &this->destiny);
    if (alive){
        if (this->attacking)
            SDL_RenderCopy(renderer, this->Textures[4], NULL, &this->destiny);
        SDL_RenderCopy(renderer, this->actualTexture, &this->source, &this->destiny);
    }
    else
        SDL_RenderCopy(renderer, this->Textures[5], NULL, &this->destiny);

}




