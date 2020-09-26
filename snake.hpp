#pragma once

#include <SFML/Graphics.hpp>
#include <map>
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
    sf::Texture faceTexture_;
    sf::Texture bodyTexture_;
    std::map<Direction, sf::Texture> tailTextures;
    std::vector<Piece> body_;
};
