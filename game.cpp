#include "game.h"
#include "const.h"

Game::Game() :
	window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE)
{
	window.setVerticalSyncEnabled(true);
}
void Game::play() {
	while (window.isOpen()) {
		check_events();
		check_colisions();
		update();
		draw();
	}
}
void Game::check_events() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
		if (event.type == sf::Event::Closed) window.close();
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Down) {
				righttank.setMoveDown(false);
			}
			if (event.key.code == sf::Keyboard::Left) {
				righttank.setMoveLeft(false);
			}
			if (event.key.code == sf::Keyboard::Right) {
				righttank.setMoveRight(false);
			}
			if (event.key.code == sf::Keyboard::Up) {
				righttank.setMoveUp(false);
			}
		}
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Left &&
				righttank.getPosition().x > 0)
			{
				righttank.setMoveLeft(true);
			}
			if (event.key.code == sf::Keyboard::Right &&
				righttank.getPosition().x < WINDOW_WIDTH - righttank.getWidth())
			{
				righttank.setMoveRight(true);
			}
			if (event.key.code == sf::Keyboard::Up &&
				righttank.getPosition().y > 0)
			{
				righttank.setMoveUp(true);
			}
			if (event.key.code == sf::Keyboard::Down &&
				righttank.getPosition().y < WINDOW_HEIGHT - righttank.getWidth())
			{
				righttank.setMoveDown(true);
			}
		}
	}
}

void Game::check_colisions() {
	//pravy tank
	while (righttank.getHitBox().intersects(l1.getHitBox())|| righttank.getHitBox().intersects(l2.getHitBox()) ||
		righttank.getHitBox().intersects(l3.getHitBox()) || righttank.getHitBox().intersects(l4.getHitBox())
		&& righttank.getMoveRight()) {
		righttank.setMoveRight(false);
		righttank.move(-1,0);
	}
	while (righttank.getHitBox().intersects(l1.getHitBox()) || righttank.getHitBox().intersects(l2.getHitBox()) ||
		righttank.getHitBox().intersects(l3.getHitBox()) || righttank.getHitBox().intersects(l4.getHitBox())
		&& righttank.getMoveLeft()) {
		righttank.setMoveLeft(false);
		righttank.move(1, 0);
	}
	while (righttank.getHitBox().intersects(l1.getHitBox()) || righttank.getHitBox().intersects(l2.getHitBox()) ||
		righttank.getHitBox().intersects(l3.getHitBox()) || righttank.getHitBox().intersects(l4.getHitBox())
		&& righttank.getMoveUp()) {
		righttank.setMoveUp(false);
		righttank.move(0,1);
	}
	while (righttank.getHitBox().intersects(l1.getHitBox()) || righttank.getHitBox().intersects(l2.getHitBox()) ||
		righttank.getHitBox().intersects(l3.getHitBox()) || righttank.getHitBox().intersects(l4.getHitBox())
		&& righttank.getMoveDown()) {
		righttank.setMoveDown(false);
		righttank.move(0, -1);
	}
	//levy tank
	while (lefttank.getHitBox().intersects(l1.getHitBox()) || lefttank.getHitBox().intersects(l2.getHitBox()) ||
		   lefttank.getHitBox().intersects(l3.getHitBox()) || lefttank.getHitBox().intersects(l4.getHitBox())
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		lefttank.move(-1, 0);
	}
	while (lefttank.getHitBox().intersects(l1.getHitBox()) || lefttank.getHitBox().intersects(l2.getHitBox()) ||
		   lefttank.getHitBox().intersects(l3.getHitBox()) || lefttank.getHitBox().intersects(l4.getHitBox())
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		lefttank.move(1, 0);
	}
	while (righttank.getHitBox().intersects(l1.getHitBox()) || righttank.getHitBox().intersects(l2.getHitBox()) ||
		righttank.getHitBox().intersects(l3.getHitBox()) || righttank.getHitBox().intersects(l4.getHitBox())
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		righttank.move(0, 1);
	}
	while (righttank.getHitBox().intersects(l1.getHitBox()) || righttank.getHitBox().intersects(l2.getHitBox()) ||
		righttank.getHitBox().intersects(l3.getHitBox()) || righttank.getHitBox().intersects(l4.getHitBox())
		&& sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
		righttank.move(0, -1);
	}
}

void Game::update() {
	righttank.update();
	lefttank.update();
}

void Game::draw() {
	window.clear(sf::Color::Black);
	righttank.draw(window);
	lefttank.draw(window);
	l1.draw(window);
	l2.draw(window);
	l3.draw(window);
	l4.draw(window);
	window.display();
}