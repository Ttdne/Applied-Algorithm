#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

const float PI = 3.14159;

std::vector<sf::Vector2f> generateHeartShape(float scale, float offsetX, float offsetY) {
    std::vector<sf::Vector2f> points;
    for (float t = 0; t <= 2 * PI; t += 0.01f) {
        float x = scale * 16 * std::pow(std::sin(t), 3) + offsetX;
        float y = scale * (13 * std::cos(t) - 5 * std::cos(2 * t) - 2 * std::cos(3 * t) - std::cos(4 * t)) + offsetY;
        points.emplace_back(x, y);
    }
    return points;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Moving Heart");

    float scale = 10.0f;
    float posX = 400, posY = 300; // Initial position
    float speed = 100.0f; // Pixels per second

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update position
        float deltaTime = clock.restart().asSeconds();
        posX += speed * deltaTime;

        if (posX > 800) posX = -scale * 16; // Reset position if it goes off-screen

        // Draw heart shape
        window.clear();
        auto points = generateHeartShape(scale, posX, posY);
        sf::VertexArray heart(sf::LineStrip, points.size());
        for (size_t i = 0; i < points.size(); ++i) {
            heart[i].position = points[i];
            heart[i].color = sf::Color::Red;
        }
        window.draw(heart);
        window.display();
    }

    return 0;
}
