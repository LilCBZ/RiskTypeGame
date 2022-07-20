#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Menu.h"
#include "MouseInput.h"

const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	sf::View view(sf::Vector2f(1920, 1080), sf::Vector2f(1920, 1080));
	view.zoom(2);
	window.setView(view);
	Map map("map1");
	Menu menu;

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		map.draw(window);
		menu.draw(window);
		window.display();
		MouseInput::update();
	}

	return 0;
}