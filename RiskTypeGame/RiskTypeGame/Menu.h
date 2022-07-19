#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>

class Menu
{
public:
	void draw(sf::RenderWindow &window);

private:

};

void centerText(sf::Text &text, const sf::RenderWindow &window, const int yDisplacement = 0);

void drawTextRect(const sf::Text &text, sf::RenderWindow &window);