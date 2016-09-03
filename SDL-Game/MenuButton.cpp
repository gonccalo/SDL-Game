#include "MenuButton.h"
#include "InputHandler.h"

MenuButton::MenuButton() :
	SDLGameObject() {

}

void MenuButton::load(const LoaderParams* pParams) {
	SDLGameObject::load(pParams);
	m_callbackID = pParams->getCallbackID();
	m_currentFrame = MOUSE_OUT;
}

void MenuButton::draw() {
	SDLGameObject::draw();
}

void MenuButton::update() {
	Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();
	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < m_position.getY() + m_height
		&& pMousePos->getY() > m_position.getY()){

		m_currentFrame = MOUSE_OVER;

		if (TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			m_currentFrame = CLICKED;
			if (m_bReleased) {
				m_callback();
				m_bReleased = false;
			}
		}
		else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT)) {
			m_bReleased = true;
		}
	}
	else {
		m_currentFrame = MOUSE_OUT;

	}
}

void MenuButton::clean() {
	SDLGameObject::clean();

}