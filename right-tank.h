#pragma once
#include "tank.h"
#include "const.h"
#include "game.h"

class RightTank :public Tank {
public:
    RightTank() {
        texture.loadFromFile("texture.png");
        sprite.setTexture(texture);
        const int starty = WINDOW_HEIGHT / 2 + sprite.getGlobalBounds().height / 2;
        const int startx = WINDOW_WIDTH - 50 - sprite.getGlobalBounds().width;
        sprite.setPosition(startx, starty);
    }
    void stop() { sprite.move(-speed,0); }
    void move(float x, float y) { sprite.move(x, y); }
    void update() {
        //sf::RenderWindow window;
        sf::Event event;
        while (Game::window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Down) {
                    moveDown = false;
                }
                if (event.key.code == sf::Keyboard::Left) {
                    moveLeft = false;
                }
                if (event.key.code == sf::Keyboard::Right) {
                    moveRight = false;
                }
                if (event.key.code == sf::Keyboard::Up) {
                    moveUp = false;
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left &&
                    sprite.getPosition().x > 0)
                {
                    moveLeft = true;
                }
                if (event.key.code == sf::Keyboard::Right &&
                    sprite.getPosition().x < (WINDOW_WIDTH - sprite.getGlobalBounds().width))
                {
                    moveRight = true;
                }
                if (event.key.code == sf::Keyboard::Up &&
                    sprite.getPosition().y > 0)
                {
                    moveUp = true;
                }
                if (event.key.code == sf::Keyboard::Down &&
                    sprite.getPosition().y < (WINDOW_HEIGHT - sprite.getGlobalBounds().width))
                {
                    moveDown = true;
                }
            }
            if (moveRight) {
                sprite.move(speed, 0);
            }
            if (moveLeft) {
                sprite.move(-speed, 0);
            }
            if (moveUp) {
                sprite.move(0, -speed);
            }
            if (moveDown) {
                sprite.move(0, speed);
            }
        }
        
    }
    void draw(sf::RenderWindow& window) { window.draw(sprite); }
    sf::FloatRect getHitBox() {
        return sprite.getGlobalBounds();
    }
};