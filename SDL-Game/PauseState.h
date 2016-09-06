#pragma once
#include "MenuState.h"
#include "GameObject.h"
#include "MenuButton.h"
#include <vector>

class PauseState : public MenuState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();
	virtual void setCallbacks(const std::vector<Callback> &callbacks);
	virtual std::string getStateID() const { return s_pauseID; }

private:
	static const std::string s_pauseID;
	static void s_pauseToMain();
	static void s_resumePlay();

	std::vector<GameObject*> m_gameObjects;
};
