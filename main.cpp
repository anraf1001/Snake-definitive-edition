#include <SFML/Graphics.hpp>

#include "config.hpp"
#include "food.hpp"
#include "snake.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(screenWidth * tileSize, screenHeight * tileSize), "Snake");

    Snake snake(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
    Food food(window.getSize().x / 2.0f + 60, window.getSize().y / 2.0f + 60);
    sf::Clock clock;
    float deltaTime{};
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    snake.updateDirection(Direction::UP);
                } else if (event.key.code == sf::Keyboard::Down) {
                    snake.updateDirection(Direction::DOWN);
                } else if (event.key.code == sf::Keyboard::Left) {
                    snake.updateDirection(Direction::LEFT);
                } else if (event.key.code == sf::Keyboard::Right) {
                    snake.updateDirection(Direction::RIGHT);
                }
            }
        }

        if (deltaTime > 0.2) {
            deltaTime = 0.0f;
            snake.move();
            if (snake.checkBorderCollision(window)) {
                window.close();
            } else if (snake.getBody().getGlobalBounds().intersects(food.getBody().getGlobalBounds())) {
                food.generateNewPos();
            }

        } else {
            deltaTime += clock.restart().asSeconds();
        }

        window.clear();
        window.draw(snake.getBody());
        window.draw(food.getBody());
        window.display();
    }
    return 0;
}
