#include "Engine.h"

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_newLevelRequired)
	{
		// These calls to spawn will be moved to a new loadLevel() function soon
		// loadLevel() function soon
		// Spawn Thomas and Bob
		m_thomas.spawn(Vector2f(0, 0), (float)GRAVITY);
		m_bob.spawn(Vector2f(100,0), (float)GRAVITY);

		// Make sure the spawn is called only once
		m_timeRemaining = 10;
		m_newLevelRequired = false;
		m_playing = true;
	}

	if (m_playing)
	{
		// Update Thomas
		m_thomas.update(dtAsSeconds);

		// Update Bob
		m_bob.update(dtAsSeconds);


		// count down the time the player has left
		m_timeRemaining -= dtAsSeconds;

		// Have Thomas and Bob run out of time
		if (m_timeRemaining <= 0)
		{
			m_newLevelRequired = true;
		}
	} // END of  --  if (m_playing)

	// Set the appropriate view around the appropriate character
	if (m_splitScreen)
	{

		m_leftView.setCenter(m_thomas.getCenter());
		m_rightView.setCenter(m_bob.getCenter());

	}
	else
	{

		// Center full screeen around appropriate character
		if (m_character1)
		{
			m_mainView.setCenter(m_thomas.getCenter());
		}
		else
		{
			m_mainView.setCenter(m_bob.getCenter());
		}

	}
}