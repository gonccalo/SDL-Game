#include "Player.h"

void Player::load(int x, int y, int width, int height, std::string textureID) {
	GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer) {
	GameObject::draw(pRenderer);
}

void Player::update() {
	m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean()
{
	GameObject::clean();
}
