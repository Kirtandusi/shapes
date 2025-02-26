#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <iostream>

int main() {
    int sides;
    std::cout << "Enter the number of sides: ";
    std::cin >> sides;

    if (sides < 3) {
        std::cout << "A shape must have at least 3 sides!" << std::endl;
        return 1;
    }

    sf::ContextSettings settings;
    settings.depthBits = 24;

    sf::Vector2u windowSize(500, 500);
    sf::RenderWindow window(sf::VideoMode(windowSize), "3D Tube Drawer", sf::Style::Default, settings);
    window.setActive(true);

#pragma GCC diagnostic push  // Push current warning flags
#pragma GCC diagnostic ignored "-Wdeprecated-declarations" // Disable deprecated warnings

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-250, 250, -250, 250, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);

#pragma GCC diagnostic pop // Restore warning flags

    glTranslatef(0.0f, 0.0f, -500.0f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);

        float angleStep = 2 * M_PI / sides;
        float height = 200.0f;
        float radius = 100.0f;

        glBegin(GL_QUADS);
        // ... (rest of the drawing code is the same)
        glEnd();

        glBegin(GL_POLYGON);
        // ...
        glEnd();

        glBegin(GL_POLYGON);
        // ...
        glEnd();

        window.display();
    }

    return 0;
}