#include "Enemy.h"
#include "Game.h"

Enemy::Enemy() : SDLGameObject() {
	
}

void Enemy::load(const LoaderParams* pParams) {
	SDLGameObject::load(pParams);
	m_velocity.setY(0.02);
	m_velocity.setX(0.001);
}

void Enemy::draw() {
	//SDLGameObject::draw();
	TheTextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);

}

void Enemy::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % 2));
	if (m_position.getY() < 0) {
		m_velocity.setY(0.02);
	}
	else if (m_position.getY() > 400) {
		m_velocity.setY(-0.02);
	}
	SDLGameObject::update();
}

void Enemy::clean(){
	
}
