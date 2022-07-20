#include "MouseInput.h"
#include <iostream>

bool MouseInput::lockLeftClick = false;

MouseInput::MouseInput(const sf::RenderWindow &window)
	: window(window)
{
}

bool MouseInput::rectangleLeftClick(const sf::IntRect &rect) const
{
	if(lockLeftClick || !sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return false;
	}

	return rect.contains(sf::Mouse::getPosition());
}

bool MouseInput::rectangleLeftClick(const sf::FloatRect &rect) const
{
	if(lockLeftClick || !sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return false;
	}
	lockLeftClick = true;  // Since button is pressed.

	const float x = window.mapPixelToCoords(sf::Mouse::getPosition(window)).x;
	const float y = window.mapPixelToCoords(sf::Mouse::getPosition(window)).y;

	std::cout << rect.left << ", " << rect.top << std::endl;
	std::cout << x << ", " << y << std::endl << std::endl;

	return rect.contains(x, y);
}

bool MouseInput::textLeftClick(const sf::Text &text) const
{
	auto rect = text.getGlobalBounds();
	return rectangleLeftClick(rect);
}



void MouseInput::update()
{
	unlockLeftClick();
}

void MouseInput::unlockLeftClick()
{
	if(!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		lockLeftClick = false;
	}
}
