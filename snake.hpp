#pragma once

#include <SFML/Graphics.hpp>

#include "config.hpp"
#include "drawable.hpp"

class Snake : public Drawable {
public:
    Snake(float x, float y);

    void move();
    void updateDirection(Direction newDir);
    bool checkBorderCollision(const sf::RenderWindow& window) const;

private:
    Direction dir_;
};
