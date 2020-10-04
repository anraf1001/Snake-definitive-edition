#include "snake.hpp"
#include <iostream>

constexpr const char* kfaceUPTexPath = "../asset/faceUP.png";
constexpr const char* kfaceDOWNTexPath = "../asset/faceDOWN.png";
constexpr const char* kfaceRIGHTTexPath = "../asset/faceRIGHT.png";
constexpr const char* kfaceLEFTTexPath = "../asset/faceLEFT.png";

constexpr const char* ktailUPTextPath = "../asset/tailUP.png";
constexpr const char* ktailDOWNTextPath = "../asset/tailDOWN.png";
constexpr const char* ktailRIGHTTextPath = "../asset/tailRIGHT.png";
constexpr const char* ktailLEFTTextPath = "../asset/tailLEFT.png";

constexpr const char* kBodyTexPath = "../asset/body.png";

Snake::Snake(float x, float y) {
    body_.emplace_back(tileSize, tileSize, Direction::LEFT);

    faceTextures_[Direction::UP].loadFromFile(kfaceUPTexPath);
    faceTextures_[Direction::DOWN].loadFromFile(kfaceDOWNTexPath);
    faceTextures_[Direction::RIGHT].loadFromFile(kfaceRIGHTTexPath);
    faceTextures_[Direction::LEFT].loadFromFile(kfaceLEFTTexPath);

    tailTextures_[Direction::UP].loadFromFile(ktailUPTextPath);
    tailTextures_[Direction::DOWN].loadFromFile(ktailDOWNTextPath);
    tailTextures_[Direction::RIGHT].loadFromFile(ktailRIGHTTextPath);
    tailTextures_[Direction::LEFT].loadFromFile(ktailLEFTTextPath);

    bodyTexture_.loadFromFile(kBodyTexPath);
    body_.front().setTexture(&faceTextures_[body_.front().getDir()]);

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

    body_.front().setTexture(&faceTextures_[body_.front().getDir()]);
    if (body_.size() > 1) {
        body_.back().setTexture(&tailTextures_[body_.back().getDir()]);
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
    body_.back().setTexture(&tailTextures_[body_.back().getDir()]);
}

bool Snake::checkSuicide() {
    for (auto it = body_.begin() + 1; it != body_.end(); it++) {
        if (it->getGlobalBounds().intersects(body_.front().getGlobalBounds())) {
            return true;
        }
    }

    return false;
}
