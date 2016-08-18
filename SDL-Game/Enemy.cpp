#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {

}

void Enemy::draw() {
	SDLGameObject::draw();
}

void Enemy::update() {
	m_velocity.setX(1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}

void Enemy::clean(){
	
}
