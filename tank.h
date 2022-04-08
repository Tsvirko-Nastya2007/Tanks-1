#pragma once
#include "SFML/Graphics.hpp"

class Tank {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Tank() {};
	Tank(float startx, float starty) {
		sprite.setPosition(startx, starty);
		sprite.setTexture(texture);
	}
	void update() {
		sf::Vector2f position = sprite.getPosition();
	}
	void draw(sf::RenderWindow& window) { window.draw(sprite); }
};
