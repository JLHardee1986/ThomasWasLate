#include "Engine.h"

using namespace sf;
using namespace std;
#include <vector>
#include <sstream>


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
		

		

		// Detect collisions and see if characters
		// have reached the goal tile
		//  The second part of the condition is only execyted
		// when thomas is touching the home tile
		if (detectCollisions(m_thomas) && detectCollisions(m_bob))
		{
			// new level required
			m_newLevelRequired = true;

			// Play the reach goal sound
			m_sMgr.playReachGoal();
		}
		else
		{
			// Run bobs collision detection
			detectCollisions(m_bob);
		}

		// Update Thomas
		m_thomas.update(dtAsSeconds);

		// Update Bob
		m_bob.update(dtAsSeconds);

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


	// Sound checks
	// Check if a fire sound needs to be played
	vector<Vector2f>::iterator it;

	// Iterate through the vector of Vector2f objects
	for (it = m_fireEmitters.begin(); it != m_fireEmitters.end(); it++)
	{
		// Where is this emitter?
		// Store the location in pos
		float posX = (*it).x;
		float posY = (*it).y;
		// is the emitter near the player?
		// Make a 500 pixel rectangle around the emitter
		FloatRect localRect(posX - 250, posY - 250, 500, 500);
		// Is the player inside localRect?
		if (m_thomas.getPosition().intersects(localRect))
		{
			// Play the sound and pass in the location as well
			m_sMgr.playFire(Vector2f(posX, posY), m_thomas.getCenter());
		}
	}
	
	m_rs.setPosition({ m_thomas.getPosition().left, m_thomas.getPosition().top });
	m_rsBob.setPosition({ m_bob.getPosition().left, m_bob.getPosition().top });

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

	// Time to update the HUD?
 // Increment the number of frames since 
 // the last HUD calculation
	m_FramesSinceLastHUDUpdate++;
	// Update the HUD every m_TargetFramesPerHUDUpdate frames
	if (m_FramesSinceLastHUDUpdate > m_TargetFramesPerHUDUpdate)
	{
		// Update game HUD text
		stringstream ssTime;
		stringstream ssLevel;
		// Update the time text
		ssTime << (int)m_timeRemaining;
		m_Hud.setTime(ssTime.str());
		// Update the level text
		ssLevel << "Level:" << m_lMgr.getCurrentLevel();
		m_Hud.setLevel(ssLevel.str());
	
		m_FramesSinceLastHUDUpdate = 0;
	}
}