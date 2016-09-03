#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed) :
	SDLGameObject(), m_animSpeed(animSpeed){
	SDLGameObject::load(pParams);
}

void AnimatedGraphic::draw() {
	SDLGameObject::draw();
}

void AnimatedGraphic::update() {
	m_currentRow = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % 2)+1);
}

void AnimatedGraphic::clean() {

}