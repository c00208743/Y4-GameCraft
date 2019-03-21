#include "..\Header\Button.h"

Button::Button(std::string s = "", float x = 0, float y = 0) : Widget()
{
	isActive = true; //starts active

	m_id = "button";

	if (!m_font.loadFromFile("Asset/Fonts/impact.ttf"))
	{
		std::cout << "Button font failed to load" << std::endl;
	}

	m_hasFocus = false; //no focus
	m_text.setFont(m_font);
	m_text.setString(s);
	m_text.setPosition(x, y);
	m_text.setFillColor(sf::Color::White); //no focus means element is white
	m_text.setCharacterSize(35);

	m_rect.setPosition(x - 5, y);
	m_rect.setSize(sf::Vector2f(m_text.getGlobalBounds().width + 10, m_text.getGlobalBounds().height + 15)); //dynamic rectangle sizing based on text
	m_rect.setFillColor(sf::Color::Transparent);
	m_rect.setOutlineColor(sf::Color::Transparent); //set to transparent
	m_rect.setOutlineThickness(2);
}

Button::Button(std::string s, float x = 0, float y = 0, std::string font = "impact.ttf") : Widget()
{
	isActive = true; //starts active

	m_id = "button";

	if (!m_font.loadFromFile("Fonts/" + font))
	{
		std::cout << "Button font failed to load" << std::endl;
	}

	m_hasFocus = false; //no focus
	m_text.setFont(m_font);
	m_text.setString(s);
	m_text.setPosition(x, y);
	m_text.setFillColor(sf::Color::White); //no focus means element is white
	m_text.setCharacterSize(35);

	m_rect.setPosition(x - 5, y);
	m_rect.setSize(sf::Vector2f(m_text.getGlobalBounds().width + 10, m_text.getGlobalBounds().height + 15)); //dynamic rectangle sizing based on text
	m_rect.setFillColor(sf::Color::Transparent);
	m_rect.setOutlineColor(sf::Color::Transparent); //set to transparent
	m_rect.setOutlineThickness(2);
}

Button::Button(std::string s, float x, float y, int size) : Widget()
{
	isActive = true; //starts active

	m_id = "button";

	if (!m_font.loadFromFile("Fonts/AmericanCaptain.ttf"))
	{
	}

	m_hasFocus = false; //no focus
	m_text.setFont(m_font);
	m_text.setString(s);
	m_text.setPosition(x, y);
	m_text.setFillColor(sf::Color::White); //no focus means element is white
	m_text.setCharacterSize(size);

	m_rect.setPosition(x - 5, y);
	m_rect.setSize(sf::Vector2f(m_text.getGlobalBounds().width + 10, m_text.getGlobalBounds().height + 15)); //dynamic rectangle sizing based on text
	m_rect.setFillColor(sf::Color::Transparent);
	m_rect.setOutlineColor(sf::Color::Transparent); //set to transparent
	m_rect.setOutlineThickness(2);
}

Button::Button(std::string s, float x, float y, sf::Color color, std::string tag)
{
	isActive = true;
	m_tag = tag;
	m_id = "button";
	if (!m_font.loadFromFile("Figurativative.ttf"))
	{
		//error message
	}
	m_hasFocus = false;
	m_text.setFont(m_font);
	m_text.setString(s);
	m_text.setPosition(x, y);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(35);

	m_rect.setPosition(x - 5, y);
	m_rect.setSize(sf::Vector2f(m_text.getGlobalBounds().width + 10, m_text.getGlobalBounds().height + 15));
	m_rect.setFillColor(color);
	m_rect.setOutlineColor(sf::Color::Transparent);
	m_rect.setOutlineThickness(2);
}

Button::~Button()
{

}

// Give the focus to this element
void Button::gainFocus()
{
	m_hasFocus = true;
}

// Take the focus from this element
void Button::loseFocus()
{
	m_hasFocus = false;
}

// Check elements focus
bool Button::checkFocus()
{
	return m_hasFocus;
}

// Update loop 
void Button::update()
{
	if (m_hasFocus == true && isActive == true)
	{
		m_text.setFillColor(sf::Color::Red);
		m_rect.setOutlineColor(sf::Color::Red);
	}
	else
	{
		m_text.setFillColor(sf::Color::White);
		m_rect.setOutlineColor(sf::Color::Transparent);
	}
}

// Draw Button
void Button::draw(sf::RenderWindow &window)
{
	if (isActive == true)
	{
		window.draw(m_text);
		window.draw(m_rect);
	}
}

// Change colour of the rectangle
void Button::setRectColour(sf::Color colour)
{
	m_rect.setFillColor(colour);
}

void Button::changeTextSize(int size)
{
	m_text.setCharacterSize(size); 

	m_rect.setPosition(m_text.getPosition().x - 5, m_text.getPosition().y);
	m_rect.setSize(sf::Vector2f(m_text.getGlobalBounds().width + 10, m_text.getGlobalBounds().height + 15)); //dynamic rectangle sizing based on text

}