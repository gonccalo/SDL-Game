#include "Player.h"

Player::Player(const LoaderParams* pParams) :
	SDLGameObject(pParams){
}

void Player::draw() {
	SDLGameObject::draw();
}

void Player::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();

	SDLGameObject::update();
}

void Player::handleInput() {
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
		m_velocity.setX(0.01);
	}
	if (TheInputHandler::Instance()->getMouseButtonState(RIGHT)) {
		m_velocity.setX(-0.01);
	}
}
void Player::clean()
{
}
