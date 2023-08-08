#include <iostream>

#include <SFML/Graphics.hpp>

#include <memory>
#include <utility>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	std::unique_ptr<sf::RenderWindow> upWnd = std::make_unique<sf::RenderWindow>(sf::VideoMode(1280U, 720U, 32U), "Template", sf::Style::None, settings);

	while (upWnd->isOpen())
	{
		sf::Event e;
		while (upWnd->pollEvent(e))
		{
			switch (e.type)
			{
				case sf::Event::Closed:
					upWnd->close();
					break;
				case sf::Event::KeyPressed:
					if (e.key.code == sf::Keyboard::Escape)
					{
						upWnd->close();
					}
					break;
				default:
					break;
			}

		}
		upWnd->clear(sf::Color(47, 147, 247, 255));

		upWnd->display();
	}

	return EXIT_SUCCESS;
}