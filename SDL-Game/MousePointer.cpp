#include "MousePointer.h"

MousePointer::MousePointer() :
	SDLGameObject() {

}

void MousePointer::load(const LoaderParams* pParams) {
	SDLGameObject::load(pParams);
}

void MousePointer::draw() {
	SDLGameObject::draw();
}
void MousePointer::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % 2));
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();
	SDLGameObject::update();
}
void MousePointer::clean() {
	SDLGameObject::clean();
}

void MousePointer::handleInput() {
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position);
	m_velocity /= 50;
}