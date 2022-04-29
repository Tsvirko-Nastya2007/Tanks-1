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
        //sf::Event event;
        //while (Game::window.pollEvent(event)) {
            
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
    void draw(sf::RenderWindow& window) { window.draw(sprite); }
    sf::FloatRect getHitBox() {
        return sprite.getGlobalBounds();
    }
    
};