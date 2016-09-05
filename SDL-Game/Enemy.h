#pragma once
#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Enemy : public SDLGameObject
{
public:
	Enemy();
	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();


private:

};
class EnemyCreator : public BaseCreator {
public:
	virtual GameObject* createGameObject() const {
		return new Enemy();
	}
	~EnemyCreator() {}
};