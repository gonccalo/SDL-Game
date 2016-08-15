#pragma once
#include <SDL.h>
#include <iostream>
#include "TextureManager.h"

class GameObject
{
public:
	void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean() { std::cout << "clean object"; }

protected:
	int m_x;
	int m_y;
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_width;
	int m_height;
};
