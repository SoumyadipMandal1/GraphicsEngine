#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>

sf::Color hexToColor(const std::string &color)
{
    int R = std::stoi(color.substr(1, 2), nullptr, 16);
    int G = std::stoi(color.substr(3, 2), nullptr, 16);
    int B = std::stoi(color.substr(5, 2), nullptr, 16);

    return sf::Color(R, G, B);
}

void point(sf::RenderWindow &window, const sf::Vector2f &position,
           const sf::Color &color)
{
    // Defining the point
    sf::VertexArray point(sf::PrimitiveType::Points, 1);
    point[0].position = position;
    point[0].color = color;

    window.draw(point);
}

void line(sf::RenderWindow &window, const sf::Vector2f &start,
          const sf::Vector2f &end, const sf::Color &color)
{
    // Defining the line
    sf::VertexArray line(sf::PrimitiveType::Lines, 2);
    line[0].position = start;
    line[1].position = end;

    // color
    line[0].color = color;
    line[1].color = color;

    window.draw(line);
}

int main()
{
    // Creating a window
    sf::RenderWindow window(sf::VideoMode({1000, 900}), "Hello World!");

    // Main Loop
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            // For closing the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clearing window
        window.clear();

        line(window, sf::Vector2f(100, 100), sf::Vector2f(700, 500),
             sf::Color::Red);
        point(window, sf::Vector2f(500, 500), sf::Color::Green);

        window.display();
    }
}
