#pragma once
#include <SFML/Graphics.hpp>
#include "right-tank.h"
#include "left-tank.h"
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"


class Game {
public:
	enum GameState { INTRO, PLAY, GAME_OVER };
	Game();
	void play();
private:
	sf::RenderWindow window;
	GameState game_state = PLAY;
	RightTank righttank;
	LeftTank lefttank;
	Labyrinth1 l1;
	Labyrinth2 l2;
	Labyrinth3 l3;
	Labyrinth4 l4;
	void check_events();
	void update();
	void draw();
	void check_colisions();

	//sf::RenderWindow getWindow() { return window; }
};