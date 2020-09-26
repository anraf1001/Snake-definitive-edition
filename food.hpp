#pragma once

#include <SFML/Graphics.hpp>

class Food {
public:
    Food(float x, float y);

    void generateNewPos();

    sf::RectangleShape& getBody() { return body_; }

private:
    sf::Texture foodTexture_;
    sf::RectangleShape body_;
};
