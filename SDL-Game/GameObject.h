#pragma once
#include <iostream>

class GameObject
{
public:
	GameObject();
	void draw() { std::cout << "draw object"; }
	void update() { std::cout << "update object"; }
	void clean() { std::cout << "clean object"; }
	~GameObject();

protected:
	int m_x;
	int m_y;
};

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}