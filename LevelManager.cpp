#include "LevelManager.h"
#include "TextureHolder.h"
#include <string>
#include <sstream>
#include <fstream>


using namespace sf;
using namespace std;

LevelManager::LevelManager()
{

}

float LevelManager::getTimeLimit()
{
	return m_baseTimeLimit * m_timeModifier;
}

sf::Vector2f LevelManager::getStartPosition()
{
	return m_startPosition;
}

int** LevelManager::nextLevel(sf::VertexArray& rVaLevel)
{
	m_levelSize.x = 0;
	m_levelSize.y = 0;

	// Get the next level
	m_currentLevel++;

	if (m_currentLevel > NUM_LEVELS)
	{
		m_currentLevel = 1;
		m_timeModifier -= 0.1f;
	}

	// Load the appropriate level from a text file
	string levelToLoad;
	switch (m_currentLevel)
	{
		
		case 1:
			levelToLoad = "levels/level1.txt";
			m_startPosition.x = 100;
			m_startPosition.y = 100;
			m_baseTimeLimit = 30.f;
			break;

		case 2:
			levelToLoad = "levels/level2.txt";
			m_startPosition.x = 100;
			m_startPosition.y = 3600;
			m_baseTimeLimit = 100.f;
			break;

		case 3:
			levelToLoad = "levels/level3.txt";
			m_startPosition.x = 1250;
			m_startPosition.y = 0;
			m_baseTimeLimit = 30.f;
			break;

		case 4:
			levelToLoad = "levels/level4.txt";
			m_startPosition.x = 50;
			m_startPosition.y = 200;
			m_baseTimeLimit = 50.f;
			break;

	}

	ifstream inputFile(levelToLoad);
	string s;

	// Count the number of rows in the file
	while (getline(inputFile, s))
	{
		++m_levelSize.y;
	}

	// Store the length of the rows
	m_levelSize.x = (int)s.length();

	// go back to the start of the file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	// Prepare the 2D array to hold the int values from the file
	int** arrayLevel = new int* [m_levelSize.y];
	for (int i = 0; i < m_levelSize.y; ++i)
	{
		// Add a new array into each array element
		arrayLevel[i] = new int[m_levelSize.x];
	}

	// Loop through the file and store all
	// the values in the 2d array
	string row;
	int y = 0;
	while (inputFile >> row)
	{
		for (int x = 0; x < row.length(); x++)
		{
			const char val = row[x];
			arrayLevel[y][x] = atoi(&val);
		}

		y++;
	}

	// Close the file
	inputFile.close();

	// What type of primitive are we using
	rVaLevel.setPrimitiveType(Quads);

	// Set the size of the vertex array
	rVaLevel.resize(m_levelSize.x * m_levelSize.y * VERTS_IN_QUAD);

	// Start at the beginning of the vertex array
	int currentVertex = 0;

	for (int x = 0; x < m_levelSize.x; x++)
	{

		for (int y = 0; y < m_levelSize.y; y++)
		{
			// Position each vertex in the current quad
			rVaLevel[currentVertex + 0].position = Vector2f((float)x * (float)TILE_SIZE, (float)y * (float)TILE_SIZE);

			rVaLevel[currentVertex + 1].position = Vector2f(((float)x * (float)TILE_SIZE) + (float)TILE_SIZE, (float)y * (float)TILE_SIZE);

			rVaLevel[currentVertex + 2].position = Vector2f(((float)x * (float)TILE_SIZE) + (float)TILE_SIZE, ((float)y * (float)TILE_SIZE) + (float)TILE_SIZE);

			rVaLevel[currentVertex + 3].position = Vector2f((float)x * (float)TILE_SIZE, ((float)y * (float)TILE_SIZE) + (float)TILE_SIZE);

			// Which tile from the sprite sheet should we use
			int verticalOffset = arrayLevel[y][x] * TILE_SIZE;

			rVaLevel[currentVertex + 0].texCoords = Vector2f(0.f, 0.f + verticalOffset);

			rVaLevel[currentVertex + 1].texCoords = Vector2f((float)TILE_SIZE, 0.f + verticalOffset);

			rVaLevel[currentVertex + 2].texCoords = Vector2f((float)TILE_SIZE, (float)TILE_SIZE + verticalOffset);

			rVaLevel[currentVertex + 3].texCoords = Vector2f(0.f, (float)TILE_SIZE + verticalOffset);

			// Position ready for the next four vertices
			currentVertex = currentVertex + (int)VERTS_IN_QUAD;
		}
	}
	return arrayLevel;
} // End of nextLevel fundtion



sf::Vector2i LevelManager::getLevelSize()
{
	return m_levelSize;
}

int LevelManager::getCurrentLevel()
{
	return m_currentLevel;
}
