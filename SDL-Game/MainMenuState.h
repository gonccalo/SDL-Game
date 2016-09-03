#pragma once
#include "MenuState.h"
#include "GameObject.h"

class MainMenuState : public MenuState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }

private:
	virtual void setCallbacks(const std::vector<Callback> &callbacks);
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
	static void s_menuToPlay();
};

