#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Piece.hpp"
#include "config.hpp"

class Snake {
public:
    Snake(float x, float y);

    void move();
    void updateDirection(Direction newDir);
    bool checkBorderCollision(const sf::RenderWindow& window) const;
    void addNewSegment();
    bool checkSuicide();

    std::vector<Piece>& getBody() { return body_; }

private:
    std::vector<Piece> body_;
};
