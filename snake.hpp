#pragma once

#include <SFML/Graphics.hpp>

#include "config.hpp"

class Snake {
public:
    Snake(float x, float y);

    void move();
    void updateDirection(Direction newDir);
    bool checkBorderCollision(const sf::RenderWindow& window) const;

    sf::RectangleShape& getBody() { return body_; }

private:
    sf::RectangleShape body_;
    Direction dir_;
};
