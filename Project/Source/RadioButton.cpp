#include "..\Header\RadioButton.h"

RadioButton::RadioButton(std::string s, float x, float y, std::string tag) :
	Widget()
{
	m_id = "radiobutton";
	m_tag = tag;
	m_icon.setFillColor(sf::Color::White);
	m_icon.setOutlineColor(sf::Color::White);
	m_icon.setPosition(x - 5, y + 10);
	m_icon.setScale(2, 2);
	m_icon.setRadius(3);
	m_icon.setOutlineThickness(1.3);
	m_isActive = false;
	m_focus = false;
	if (!m_font.loadFromFile("..\Fonts\impact.ttf"))
	{
		std::cout << "Radio button font failed to load" << std::endl;
	}
	m_text.setFont(m_font);
	m_text.setString(s);
	m_text.setPosition((x + 10), y);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(25);

	m_rect.setPosition(x - 10, y);
	m_rect.setSize(sf::Vector2f((m_icon.getGlobalBounds().width + m_text.getGlobalBounds().width) + 10, m_text.getGlobalBounds().height + 15));
	m_rect.setFillColor(sf::Color::Transparent);
	m_rect.setOutlineColor(sf::Color::Transparent);
	m_rect.setOutlineThickness(1);
}

// Draw loop
void RadioButton::draw(sf::RenderWindow &window)
{
	window.draw(m_rect);
	window.draw(m_icon);
	window.draw(m_text);

}

bool RadioButton::checkFocus()
{
	return m_focus;
}

void RadioButton::gainFocus()
{
	m_focus = true;
}

void RadioButton::loseFocus()
{
	m_focus = false;
}

void RadioButton::becomeActive()
{
	m_isActive = true;
}

void RadioButton::loseActive()
{
	m_isActive = false;
}

// Update loop
void RadioButton::update()
{
	if (m_focus == true)
	{
		m_text.setFillColor(sf::Color::Red);
		m_rect.setOutlineColor(sf::Color::Red);
	}
	else {
		m_text.setFillColor(sf::Color::White);
		m_rect.setOutlineColor(sf::Color::Transparent);
	}

	if (m_isActive) //if active fill the circle
	{
		m_icon.setFillColor(sf::Color::Black);

	}
	else {
		m_icon.setFillColor(sf::Color::White);
	}

}

bool RadioButton::checkActive()
{
	return m_isActive;
}