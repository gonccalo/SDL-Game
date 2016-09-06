#pragma once
#include "MenuState.h"
#include <vector>
#include "GameObject.h"

class GameOverState : public MenuState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual void setCallbacks(const std::vector<Callback> &callbacks);
	virtual std::string getStateID() const { return s_gameOverID; }

private:
	static void s_gameOverToMain();
	static void s_restartPlay();

	static const std::string s_gameOverID;
	std::vector<GameObject*> m_gameObjects;

};
