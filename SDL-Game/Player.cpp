#include "Player.h"
#include "Game.h"

Player::Player() :
	SDLGameObject(){
}

void Player::load(const LoaderParams* pParams) {
	SDLGameObject::load(pParams);
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
	if (m_position.getY() > 400) {
		m_acceleration.setY(0);
	}
	else
	{
		m_acceleration.setY(0.1);
	}
	
	handleInput();

	SDLGameObject::update();
}

void Player::handleInput() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		m_velocity.setX(0.1);
		m_flip = false;
	}
	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)){
		m_velocity.setX(-0.1);
		m_flip = true;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
		m_acceleration.setY(-0.1);
	}
}
void Player::clean()
{
}
