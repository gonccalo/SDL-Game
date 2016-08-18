#include "Player.h"
#include "Game.h"

Player::Player(const LoaderParams* pParams) :
	SDLGameObject(pParams){
}

void Player::draw() {
	if (m_flip) {
		TheTextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	}
	else
	{
		SDLGameObject::draw();
	}
}

void Player::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	m_velocity.setX(0);
	m_velocity.setY(0);
	m_acceleration.setY(0);
	handleInput();

	SDLGameObject::update();
}

void Player::handleInput() {
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	if (vec->getX() >= m_position.getX()) {
		m_flip = false;
	}
	else {
		m_flip = true;
	}
	m_velocity = (*vec - m_position) / 1000;
	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
		m_acceleration.setY(-1);
	}
}
void Player::clean()
{
}
