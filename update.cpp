#include "Engine.h"

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_newLevelRequired)
	{
		// These calls to spawn will be moved to a new loadLevel() function soon
		// loadLevel() function soon
		

		// Load a level
		loadLevel();

	}

	if (m_playing)
	{
		// Update Thomas
		m_thomas.update(dtAsSeconds);

		// Update Bob
		m_bob.update(dtAsSeconds);

		// Detect collisions and see if characters
		// have reached the goal tile
		//  The second part of the condition is only execyted
		// when thomas is touching the home tile
		if (detectCollisions(m_thomas) && detectCollisions(m_bob))
		{
			// new level required
			m_newLevelRequired = true;

			// Play the reach goal sound
		}
		else
		{
			// Run bobs collision detection
			detectCollisions(m_bob);
		}

		// Let bob and thomas jump on each other's heads
		if (m_bob.getFeet().intersects(m_thomas.getHead()))
		{
			m_bob.stopFalling(m_thomas.getHead().top);
		}
		else if (m_thomas.getFeet().intersects(m_bob.getHead()))
		{
			m_thomas.stopFalling(m_bob.getHead().top);
		}
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