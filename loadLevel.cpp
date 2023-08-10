#include "Engine.h"

using namespace std;
using namespace sf;

#include <iostream>

void Engine::loadLevel()
{
	cout << "loadingLevel" << endl;

	

	if (m_arrayLevel)
	{
		
		delete[] m_arrayLevel;
		m_arrayLevel = nullptr;
	}

	// Load the next 2d array with the map for the level
	// and repopulate the vertex array as well
	m_arrayLevel = m_lMgr.nextLevel(m_vertArrLevel);

	// Prepare the sound emitters
	populateEmitters(m_fireEmitters, m_arrayLevel);

	//  How long is this new time limit
	m_timeRemaining = m_lMgr.getTimeLimit();

	// Spawn Thomas and Bob
	m_thomas.spawn(m_lMgr.getStartPosition(), (float)GRAVITY);
	m_bob.spawn(m_lMgr.getStartPosition() + Vector2f( 100.f, 0.f ), (float)GRAVITY);

	//  make sure this code is not ran twice in a row
	m_newLevelRequired = false;

	m_playing = true;
}