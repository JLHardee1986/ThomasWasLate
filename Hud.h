#ifndef __HUD__
#define __HUD__

#include <SFML/Graphics.hpp>

class Hud
{
	sf::Font m_font;
	sf::Text m_startText;
	sf::Text m_timeText;
	sf::Text m_levelText;

public:
	Hud();

	sf::Text getMessage();
	sf::Text getLevel();
	sf::Text getTime();

	void setLevel(sf::String text);
	void setTime(sf::String text);

};

#endif
