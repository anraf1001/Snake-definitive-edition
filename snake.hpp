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
    sf::Texture bodyTexture_;
    std::map<Direction, sf::Texture> faceTextures_{{Direction::UP, sf::Texture()},
                                                   {Direction::DOWN, sf::Texture()},
                                                   {Direction::LEFT, sf::Texture()},
                                                   {Direction::RIGHT, sf::Texture()}};
    std::map<Direction, sf::Texture> tailTextures_{{Direction::UP, sf::Texture()},
                                                   {Direction::DOWN, sf::Texture()},
                                                   {Direction::LEFT, sf::Texture()},
                                                   {Direction::RIGHT, sf::Texture()}};
    std::vector<Piece> body_;
};
