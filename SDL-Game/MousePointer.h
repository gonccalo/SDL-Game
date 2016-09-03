#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
class MousePointer : public SDLGameObject
{
public:
	MousePointer();
	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	void handleInput();
};
