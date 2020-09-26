#include "drawable.hpp"

#include "config.hpp"

Drawable::Drawable(float x, float y)
    : body_(sf::Vector2f(tileSize, tileSize)) {
    body_.setPosition(x, y);
}
