#include "MenuState.h"
#include <iostream>

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {

}

void MenuState::render() {

}

bool MenuState::onEnter() {
	std::cout << "a entrar no menu";
	return true;
}

bool MenuState::onExit() {
	std::cout << "a sair do menu";
	return true;
}