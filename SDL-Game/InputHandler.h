#pragma once
#include "SDL.h"
#include <vector>

enum mouse_buttons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
			return s_pInstance;
		}
		return s_pInstance;
	}
	
	void update();
	void clean() {};
	bool getMouseButtonState(int buttonNumber) { return m_mouseButtonStates[buttonNumber]; }

private:
	InputHandler();
	~InputHandler(){}
	static InputHandler* s_pInstance;

	std::vector<bool> m_mouseButtonStates;
};
typedef InputHandler TheInputHandler;