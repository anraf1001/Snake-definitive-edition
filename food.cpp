#include "food.hpp"

#include <random>

#include "config.hpp"

Food::Food(float x, float y)
    : body_(sf::Vector2f(tileSize, tileSize)) {
    body_.setPosition(x, y);
    body_.setFillColor(sf::Color::Red);
}

void Food::generateNewPos() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, screenWidth * tileSize - body_.getSize().x);

    body_.setPosition(distrib(gen), distrib(gen));
}
