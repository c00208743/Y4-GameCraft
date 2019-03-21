#include "../Header/Label.h"

Label::Label(std::string s, float x = 0, float y = 0) : Widget()
{
	m_id = "label";

	if (!m_font.loadFromFile("Fonts/impact.ttf"))
	{
		std::cout << "Couldn't load label font" << std::endl;
	}
	m_text.setFont(m_font);
	m_text.setString(s);
	m_text.setPosition(x, y);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(50);

}

Label::Label(std::string s, float x = 0, float y = 0, std::string font = "impact.ttf") : Widget()
{
	m_id = "label";
	
	if (!m_font.loadFromFile("Fonts/" + font))
	{
		std::cout << "Couldn't load label font" << std::endl;
	}

	m_text.setFont(m_font);
	m_text.setString(s);
	m_text.setPosition(x, y);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(50);

}

void Label::draw(sf::RenderWindow & window)
{
	window.draw(m_text);
}

void Label::update()
{

}

void Label::setUnderLined()
{
	m_text.setStyle(sf::Text::Underlined);
}

void Label::updateText(std::string s)
{
	m_text.setString(s);
}

void Label::changeTextSize(int size)
{
	m_text.setCharacterSize(size);
	m_fontSize = size;
}

void Label::changeFont(sf::Font font)
{
	m_text.setFont(font);
}