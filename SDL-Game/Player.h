#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "GameObjectFactory.h"

class Player : public SDLGameObject
{
public:
	Player();
	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	void handleInput();
	bool m_flip;
};
class PlayerCreator : public BaseCreator
{
public:
	GameObject* createGameObject() const {
		return new Player();
	}

private:

};