#include "..\Header\Slider.h"

Slider::Slider(float x, float y, float &value, std::string s) :
	Widget()
{
	if (!m_font.loadFromFile("..\Fonts\impact.ttf"))
	{
		std::cout << "Error loading fonts in the slider class" << std::endl; 
	}
	m_text.setFont(m_font);
	m_text.setString(s);
	m_text.setPosition(x - 30, y - 5);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(20);

	m_val = value;
	m_id = "slider";
	m_focus = false;

	// Outer rectangle
	m_rect.setPosition(x + (m_text.getGlobalBounds().width), y);
	m_rect.setSize(sf::Vector2f(200.0f, 20.0f));
	m_rect.setFillColor(sf::Color::Transparent);
	m_rect.setOutlineColor(sf::Color::Transparent);
	m_rect.setOutlineThickness(1);

	// Inner rectangle, size dictacted by a value
	m_innerRect.setPosition(x + (m_text.getGlobalBounds().width) + 10, y + 5);
	m_innerRect.setSize(sf::Vector2f(m_rectX, m_rectY));
	m_innerRect.setFillColor(sf::Color::White);
	m_innerRect.setOutlineColor(sf::Color::Black);
	m_innerRect.setOutlineThickness(1);


}

void Slider::gainFocus()
{
	m_focus = true;
}

void Slider::loseFocus()
{
	m_focus = false;
}

bool Slider::checkFocus()
{
	return m_focus;
}

void Slider::decreaseValue()
{
	if (m_val > 0)
	{
		m_val--;
	}
}

void Slider::increaseValue()
{
	if (m_val < 100)
	{
		m_val++;
	}
}

// Draw loop
void Slider::draw(sf::RenderWindow &window)
{
	window.draw(m_rect);
	window.draw(m_innerRect);
	window.draw(m_text);

}

int Slider::getValue()
{
	return m_val;
}

// Update loop
void Slider::update()
{

	m_innerRect.setSize(sf::Vector2f(m_rectX*(m_val / 100), m_rectY)); // Change the rectangles size based on the value


	if (m_focus == true)
	{

		m_rect.setOutlineColor(sf::Color::Red);
	}
	else
	{
		m_rect.setOutlineColor(sf::Color::Transparent);
	}

}