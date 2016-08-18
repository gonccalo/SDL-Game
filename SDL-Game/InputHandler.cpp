#include "InputHandler.h"
#include "Game.h"


InputHandler* InputHandler::s_pInstance = 0;
InputHandler::InputHandler() {
	for (int i = 0; i < 3; i++) {
		m_mouseButtonStates.push_back(false);
	}
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
			if (event.button.button == SDL_BUTTON_LEFT){
				m_mouseButtonStates[LEFT] = true;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE) {
				m_mouseButtonStates[MIDDLE] = true;
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				m_mouseButtonStates[RIGHT] = true;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT) {
				m_mouseButtonStates[LEFT] = false;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE) {
				m_mouseButtonStates[MIDDLE] = false;
			}
			if (event.button.button == SDL_BUTTON_RIGHT) {
				m_mouseButtonStates[RIGHT] = false;
			}
			break;
		default:
			break;
		}
	}
}