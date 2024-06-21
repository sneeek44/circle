#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "window");

    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color(100, 250, 50));

    sf::Clock clock;
    float deltaTime;
    float speed;
    sf::Vector2(50, 0);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        deltaTime = clock.restart().asSeconds();
        speed = deltaTime * 200.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            if (shape.getPosition().y - speed >= 0.f) {
                shape.move(0.f, -speed);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            if (shape.getPosition().y + speed < 500.f) {
                shape.move(0.f, speed);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            if (shape.getPosition().x - speed >= 0.f) {
                shape.move(-speed, 0.f);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            if (shape.getPosition().x + speed <= 700.f) {
                shape.move(speed, 0.f);
            }
        }
        window.clear();
        window.draw(shape);
        window.display();
    }

    return EXIT_SUCCESS;
}
