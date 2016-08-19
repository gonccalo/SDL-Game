#include "MousePointer.h"

MousePointer::MousePointer(const LoaderParams* pParams) :
	SDLGameObject(pParams) {

}

void MousePointer::draw() {
	SDLGameObject::draw();
}
void MousePointer::update() {
	m_velocity.setX(0);
	m_velocity.setY(0);
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position);
	SDLGameObject::update();
}
void MousePointer::clean() {
	SDLGameObject::clean();
}