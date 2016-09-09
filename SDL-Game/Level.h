#pragma once
#include <string>
#include <vector>
#include "Layer.h"

class LevelParser;

struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	std::string name;
};

class Level
{
	friend class LevelParser;
public:
	~Level() {};
	std::vector<Tileset>* getTilesets() { return &m_tilesets; }
	std::vector<Layer*>* getLayers() { return &m_layers; }


	void update();
	void render();

private:
	Level() {};
	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;
};
