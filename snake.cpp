#include "snake.hpp"

Snake::Snake(float x, float y) {
    body_.emplace_back(tileSize, tileSize, Direction::LEFT);
    body_.front().setPosition(x, y);
    body_.front().setFillColor(sf::Color::Green);
}

void Snake::move() {
    switch (body_.front().getDir()) {
    case Direction::UP:
        body_.front().move(0, -tileSize);
        break;
    case Direction::DOWN:
        body_.front().move(0, tileSize);
        break;
    case Direction::RIGHT:
        body_.front().move(tileSize, 0);
        break;
    case Direction::LEFT:
        body_.front().move(-tileSize, 0);
        break;
    }
}

void Snake::updateDirection(Direction newDir) {
    auto actualDir = body_.front().getDir();
    if ((newDir == Direction::LEFT || newDir == Direction::RIGHT) && (actualDir == Direction::UP || actualDir == Direction::DOWN)) {
        body_.front().setDir(newDir);
    } else if ((newDir == Direction::UP || newDir == Direction::DOWN) && (actualDir == Direction::LEFT || actualDir == Direction::RIGHT)) {
        body_.front().setDir(newDir);
    }
}

bool Snake::checkBorderCollision(const sf::RenderWindow& window) const {
    auto actualPos = body_.front().getPosition();
    return actualPos.x <= 0.0f ||
           actualPos.x >= window.getSize().x ||
           actualPos.y <= 0.0f ||
           actualPos.y >= window.getSize().y;
}
