#pragma once
#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class AnimatedGraphic : public SDLGameObject
{
public:
	AnimatedGraphic();
	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	int m_animSpeed;
};
class AnimatedGraphicCreator : public BaseCreator
{
public:
	GameObject* createGameObject() const {
		return new AnimatedGraphic();
	}
};