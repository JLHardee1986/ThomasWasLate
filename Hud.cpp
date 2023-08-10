#include "HUD.h"

using namespace sf;
using namespace std;

Hud::Hud()
{
	Vector2u resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_font.loadFromFile("fonts/Roboto-Light.ttf");

	// When Paused
	m_startText.setFont(m_font);
	m_startText.setCharacterSize(100);
	m_startText.setFillColor(Color::White);
	m_startText.setString("Press Enter when ready!");

	// Position the text
	FloatRect textRect = m_startText.getLocalBounds();

	m_startText.setPosition(resolution.x / 2.0f, resolution.y / 2.f);

	// Time
	m_timeText.setFont(m_font);
	m_timeText.setCharacterSize(75);
	m_timeText.setFillColor(Color::White);
	m_timeText.setPosition(resolution.x - 150, 0);
	m_timeText.setString("------");

	// Level
	m_timeText.setFont(m_font);
	m_timeText.setCharacterSize(75);
	m_timeText.setFillColor(Color::White);
	m_timeText.setPosition(25, 0);
	m_timeText.setString("1");


}

sf::Text Hud::getMessage()
{
	return m_startText;
}

sf::Text Hud::getLevel()
{
	return m_levelText;
}

sf::Text Hud::getTime()
{
	return m_timeText;
}

void Hud::setLevel(sf::String text)
{
	m_levelText.setString(text);
}

void Hud::setTime(sf::String text)
{
	m_timeText.setString(text);
}
