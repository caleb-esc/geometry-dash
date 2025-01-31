#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

const float GRAVITY = 0.5f;
const float JUMP_STRENGTH = -10.0f;
const float PLAYER_SPEED = 5.0f;

class Player {
public:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    
    Player() {
        shape.setSize(sf::Vector2f(50.0f, 50.0f));
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(100.0f, 500.0f);
    }
    
    void move(float deltaTime) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            shape.move(-PLAYER_SPEED * deltaTime, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            shape.move(PLAYER_SPEED * deltaTime, 0);
        }
    }
    
    void jump() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            velocity.y = JUMP_STRENGTH;
        }
    }
    
    void update(float deltaTime) {
        velocity.y += GRAVITY;  // Gravity effect
        shape.move(0, velocity.y);
        
        if (shape.getPosition().y >= 500.0f) {  // Floor collision
            shape.setPosition(shape.getPosition().x, 500.0f);
            velocity.y = 0;
        }
        
        move(deltaTime);
    }
    
    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Geometry Dash Remake");

    Player player;
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.update(deltaTime.asSeconds());
        
        window.clear(sf::Color::Black);
        player.draw(window);
        window.display();
    }

    return 0;
}
