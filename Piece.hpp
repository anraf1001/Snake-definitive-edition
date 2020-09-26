#pragma once

#include <SFML/Graphics.hpp>

#include "config.hpp"

class Piece : public sf::RectangleShape {
public:
    Piece(float sizeX, float sizeY, Direction dir)
        : sf::RectangleShape(sf::Vector2f(sizeX, sizeY)), dir_(dir) {}

    Direction getDir() const { return dir_; }
    void setDir(Direction newDir) { dir_ = newDir; }

private:
    Direction dir_;
};
