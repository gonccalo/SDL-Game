#pragma once
#include "SDL.h"
#include <iostream>
#include <map>

class TextureManager
{
public:
	TextureManager();
	bool load(std::string filename, std::string id, SDL_Renderer* pRenderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	~TextureManager();
	
private:
	std::map<std::string, SDL_Texture*> m_textureMap;
};
