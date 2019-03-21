#include "../Header/Platform.h"

/// <summary>
/// @Platform Class for all platforms and the ground in gameplay 
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Platforms to be used during gameplay
/// </summary>

//Constructs the platform object
Platform::Platform(float x, float y, int w, int h) : rect(sf::Vector2f(w, h))
{
	pos = sf::Vector2f(x, y);
	width = w;
	height = h;
	rect.setPosition(x, y);
}

// Destructor
Platform::~Platform()
{

}

//Updates platform object
void Platform::update()
{

}

//Render platform object
void Platform::render(sf::RenderWindow & window)
{
	window.draw(rect);
}

// Get the size of the platform
sf::Vector2f Platform::getSize()
{
	return sf::Vector2f(width, height);
}

// Get the position of the platform
sf::Vector2f Platform::getPos()
{
	return pos;
}