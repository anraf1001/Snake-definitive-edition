#include "snake.hpp"
#include <iostream>

Snake::Snake(float x, float y) {
    body_.emplace_back(tileSize, tileSize, Direction::LEFT);

    faceTexture_.loadFromFile("../asset/face.png");
    tailTextures.emplace(Direction::UP, sf::Texture());
    tailTextures.emplace(Direction::DOWN, sf::Texture());
    tailTextures.emplace(Direction::LEFT, sf::Texture());
    tailTextures.emplace(Direction::RIGHT, sf::Texture());
    tailTextures[Direction::UP].loadFromFile("../asset/tailUP.png");
    tailTextures[Direction::DOWN].loadFromFile("../asset/tailDOWN.png");
    tailTextures[Direction::RIGHT].loadFromFile("../asset/tailRIGHT.png");
    tailTextures[Direction::LEFT].loadFromFile("../asset/tailLEFT.png");

    if (bodyTexture_.loadFromFile("../asset/body.png")) {
        body_.front().setTexture(&bodyTexture_);
    }

    body_.front().setPosition(x, y);
}

void Snake::move() {
    for (size_t i = body_.size() - 1; i > 0; i--) {
        body_[i].setPosition(body_[i - 1].getPosition());
        body_[i].setDir(body_[i - 1].getDir());
    }

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

    body_.back().setTexture(&tailTextures[body_.back().getDir()]);
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

void Snake::addNewSegment() {
    auto backPos = body_.back().getPosition();
    body_.back().setTexture(&bodyTexture_);
    body_.emplace_back(tileSize, tileSize, body_.back().getDir());

    switch (body_.back().getDir()) {
    case Direction::UP:
        body_.back().setPosition(backPos.x, backPos.y - tileSize);
        break;
    case Direction::DOWN:
        body_.back().setPosition(backPos.x, backPos.y + tileSize);
        break;
    case Direction::RIGHT:
        body_.back().setPosition(backPos.x - tileSize, backPos.y);
        break;
    case Direction::LEFT:
        body_.back().setPosition(backPos.x + tileSize, backPos.y);
        break;
    }
    body_.back().setTexture(&tailTextures[body_.back().getDir()]);
}

bool Snake::checkSuicide() {
    for (auto it = body_.begin() + 1; it != body_.end(); it++) {
        if (it->getGlobalBounds().intersects(body_.front().getGlobalBounds())) {
            return true;
        }
    }

    return false;
}
