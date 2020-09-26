#include "Piece.hpp"

Piece::Piece(float sizeX, float sizeY, Direction dir)
    : sf::RectangleShape(sf::Vector2f(sizeX, sizeY)), dir_(dir) {
    setFillColor(sf::Color::Green);
}
