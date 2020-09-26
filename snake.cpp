#include "snake.hpp"

Snake::Snake(float x, float y)
    : body_(sf::Vector2f(tileSize, tileSize)), dir_(Direction::LEFT) {
    body_.setPosition(x, y);
    body_.setFillColor(sf::Color::Green);
}

void Snake::move() {
    switch (dir_) {
    case Direction::UP:
        body_.move(0, -tileSize);
        break;
    case Direction::DOWN:
        body_.move(0, tileSize);
        break;
    case Direction::RIGHT:
        body_.move(tileSize, 0);
        break;
    case Direction::LEFT:
        body_.move(-tileSize, 0);
        break;
    }
}

void Snake::updateDirection(Direction newDir) {
    if ((newDir == Direction::LEFT || newDir == Direction::RIGHT) && (dir_ == Direction::UP || dir_ == Direction::DOWN)) {
        dir_ = newDir;
    } else if ((newDir == Direction::UP || newDir == Direction::DOWN) && (dir_ == Direction::LEFT || dir_ == Direction::RIGHT)) {
        dir_ = newDir;
    }
}

bool Snake::checkBorderCollision(const sf::RenderWindow& window) const {
    auto actualPos = body_.getPosition();
    return actualPos.x <= 0.0f ||
           actualPos.x >= window.getSize().x ||
           actualPos.y <= 0.0f ||
           actualPos.y >= window.getSize().y;
}
