#include "InputHandler.h"
#include "Game.h"


InputHandler* InputHandler::s_pInstance = 0;
InputHandler::InputHandler() {
	for (int i = 0; i < 3; i++) {
		m_mouseButtonStates.push_back(false);
	}
	m_mousePosition = new Vector2D(0,0);
}

void InputHandler::onMouseMove(SDL_Event& event) {
	m_mousePosition->setX(event.motion.x);
	m_mousePosition->setY(event.motion.y);
}

void InputHandler::onMouseButtonDown(SDL_Event& event) {
	switch (event.button.button)
	{
	case SDL_BUTTON_LEFT:
		m_mouseButtonStates[LEFT] = true;
		break;
	case SDL_BUTTON_MIDDLE:
		m_mouseButtonStates[MIDDLE] = true;
		break;
	case SDL_BUTTON_RIGHT:
		m_mouseButtonStates[RIGHT] = true;
		break;
	default:
		break;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event& event) {
	switch (event.button.button)
	{
	case SDL_BUTTON_LEFT:
		m_mouseButtonStates[LEFT] = false;
		break;
	case SDL_BUTTON_MIDDLE:
		m_mouseButtonStates[MIDDLE] = false;
		break;
	case SDL_BUTTON_RIGHT:
		m_mouseButtonStates[RIGHT] = false;
		break;
	default:
		break;
	}
}

void InputHandler::onKeyDown() {
	m_keystates = SDL_GetKeyboardState(0);
}
void InputHandler::onKeyUp() {
	m_keystates = SDL_GetKeyboardState(0);
}

void InputHandler::update() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;
		case SDL_KEYDOWN:
			onKeyDown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		default:
			break;
		}
	}
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
	if (m_keystates != 0) {
		if (m_keystates[key] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}