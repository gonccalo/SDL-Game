#pragma once
#include <iostream>

class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height, std::string textureID, int numFrames = 0, int callBackID = 0, int animSpeed = 0) :
		m_x(x),
		m_y(y),
		m_width(width),
		m_height(height),
		m_textureID(textureID),
		m_numFrames(numFrames),
		m_callBackID(callBackID),
		m_animSpeed(animSpeed){

	}
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	std::string getTextureID() const { return m_textureID; }
	int getCallbackID() const { return m_callBackID; }

private:
	int m_x;
	int m_y;

	int m_width;
	int m_height;
	int m_numFrames;
	int m_callBackID;
	int m_animSpeed;

	std::string m_textureID;
};
