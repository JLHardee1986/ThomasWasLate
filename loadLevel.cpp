#include "Engine.h"

using namespace std;
using namespace sf;

void Engine::loadLevel()
{
	m_playing = false;

	// Delete the previously allocated memory
	for (int i = 0; i < m_lMgr.getLevelSize().y; i++)
	{
		delete[] m_arrayLevel[i];
	}
	delete[] m_arrayLevel;

	// Load the next 2d array with the map for the level
	// and repopulate the vertex array as well
	m_arrayLevel = m_lMgr.nextLevel(m_vertArrLevel);

	//  How long is this new time limit
	m_timeRemaining = m_lMgr.getTimeLimit();

	// Spawn Thomas and Bob
	m_thomas.spawn(m_lMgr.getStartPosition(), (float)GRAVITY);
	m_bob.spawn(m_lMgr.getStartPosition() + Vector2f( 100.f, 0.f ), (float)GRAVITY);

	//  make sure this code is not ran twice in a row
	m_newLevelRequired = false;

	m_playing = true;
}