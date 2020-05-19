#include "headers/Game/Entity.h"
#include "headers/Game/Controller.h"
#include "headers/Game/Collider/Collider.h"


Entity::Entity(SDL_Renderer* renderer, int x, int y, bool playable)
{
    this->playable = playable;
    this->Textures[0] = TextureManager::LoadImage("assets/idle/FoxIdleRSpritesheet.bmp", renderer);
    this->Textures[1] = TextureManager::LoadImage("assets/idle/FoxIdleLSpritesheet.bmp", renderer);

    this->Textures[2] = TextureManager::LoadImage("assets/run/FoxRunningRSpritesheet.bpm", renderer);
    this->Textures[3] = TextureManager::LoadImage("assets/run/FoxRunningLSpritesheet.bpm", renderer);

    this->actualTexture = this->Textures[0];

    this->velocity.Velx = this->velocity.Vely = 0;

    this->Entitystate = State::IdleR;
    this->position.x = x;
    this->position.y = y;
    this->source = {0, 0, 17, 16};
    this->destiny = {this->position.x, this->position.y, 17, 16};
}

void Entity::move(int direction){
    switch (direction) {
    case 1:
        moveX();
    case 2:
        moveY();
    }
}

void Entity::moveX(){
    this->destiny.x = this->velocity.Velx + this->destiny.x;
}
void Entity::moveY(){
    this->destiny.y = this->velocity.Vely + this->destiny.y;
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
void Entity::setPosition(Position newPosition){
    this->position = newPosition;
}
void Entity::setVelocity(Velocity newVelocity){
    this->velocity = newVelocity;
}
void Entity::setDimension(SDL_Rect newDimension){
    this->source = newDimension;
}

void Entity::Render(SDL_Renderer* renderer){
    SDL_RenderCopy(renderer, this->actualTexture, &this->source, &this->destiny);
}




