#include "Menu.h"
#include <iostream>
#include "MouseInput.h"

void Menu::draw(sf::RenderWindow &window)
{
	MouseInput mi(window);

	sf::Font font;
	font.loadFromFile("Aller_Bd.ttf");
	sf::Text text1("New Game", font, 30);
	sf::Text text2("adsfasdffasdf3e", font, 30);
	sf::Text text3("adsfaadsfasdfasfew3432432423 sd    dfsf ssd  d f  fdasdasdffasdf3e", font, 35);

	centerText(text1, window, 60);
	centerText(text2, window, 20);
	centerText(text3, window, -10);

	drawTextRect(text1, window);

	if(mi.textLeftClick(text1))
	{
		std::cout << "OK";
	}

	window.draw(text1);
	window.draw(text2);
	window.draw(text3);
}


void centerText(sf::Text &text, const sf::RenderWindow &window, const int yDisplacement)
{
	const int x = (window.getSize().x - text.getGlobalBounds().width) / 2;
	const int y = (window.getSize().y - text.getGlobalBounds().height) / 2 + yDisplacement;
	text.setPosition(sf::Vector2f(x, y));
}

void drawTextRect(const sf::Text &text, sf::RenderWindow &window)
{
	auto rect = text.getGlobalBounds();
	sf::RectangleShape shape(sf::Vector2f(rect.width, rect.height));
	shape.setPosition(sf::Vector2f(rect.left, rect.top));
	window.draw(shape);
}


