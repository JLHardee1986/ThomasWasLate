#ifndef __LEVELMANAGER__
#define __LEVELMANAGER__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class LevelManager
{

	sf::Vector2i m_levelSize;
	sf::Vector2f m_startPosition{0.f, 0.f};

	float m_timeModifier = 1;
	float m_baseTimeLimit = 0;

	int m_currentLevel = 0;
	const int NUM_LEVELS = 4;



public:

	LevelManager();

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	float getTimeLimit();

	sf::Vector2f getStartPosition();

	int** nextLevel(sf::VertexArray& rVaLevel);

	sf::Vector2i getLevelSize();

	int getCurrentLevel();
};

#endif
