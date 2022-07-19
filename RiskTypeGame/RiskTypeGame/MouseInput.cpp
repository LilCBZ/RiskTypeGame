#include "MouseInput.h"
#include <iostream>

bool MouseInput::lockLeftClick = false;

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
	const float x = sf::Mouse::getPosition().x;
	const float y = sf::Mouse::getPosition().y;
	return rect.contains(x, y);
}

bool MouseInput::textLeftClick(const sf::Text &text) const
{
	auto rect = text.getGlobalBounds();
	return rectangleLeftClick(rect);
}



void MouseInput::update()
{
	lockLeftClickUpdate();
}

void MouseInput::lockLeftClickUpdate()
{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		lockLeftClick = true;
	}
	else
	{
		lockLeftClick = false;
	}
}
