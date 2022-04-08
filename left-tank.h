#pragma once
#include "tank.h"
#include "const.h"

class LeftTank :public Tank {
public:
    void draw(sf::RenderWindow& window) { window.draw(sprite); }
    static float d;
    LeftTank() {
        texture.loadFromFile("texture.png");
        sprite.setTexture(texture);
        const int starty = WINDOW_HEIGHT / 2 + sprite.getGlobalBounds().height / 2;
        const int startx = 50;
        sprite.setPosition(startx, starty);
    }
    void move(float x, float y) { sprite.move(x, y); }
    void update() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
            sprite.getPosition().x > 0)
        {
            sprite.move(-speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
            sprite.getPosition().x < (WINDOW_WIDTH - sprite.getGlobalBounds().width))
        {
            sprite.move(speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
            sprite.getPosition().y > 0)
        {
            sprite.move(0, -speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) &&
            sprite.getPosition().y < (WINDOW_HEIGHT - sprite.getGlobalBounds().width))
        {
            sprite.move(0, speed);
        }
    }
    void stop() { sprite.move(0, 0); }
    sf::FloatRect getHitBox() {
        return sprite.getGlobalBounds();
    }
};