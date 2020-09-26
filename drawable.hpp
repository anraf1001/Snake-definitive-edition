#pragma once

#include <SFML/Graphics.hpp>

class Drawable {
public:
    Drawable(float x, float y);

    sf::RectangleShape& getBody() { return body_; }

protected:
    sf::RectangleShape body_;
};
