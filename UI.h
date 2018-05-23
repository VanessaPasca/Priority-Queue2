#pragma once
#include "Controller.h"
class UI {
private:
	Controller controller;
public:
	UI(Controller c) :controller{ c } {};
	void printMenu();
	void run();
	void displayAll();

};