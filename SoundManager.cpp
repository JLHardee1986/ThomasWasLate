#include "SoundManager.h"

using namespace sf;
using namespace std;

SoundManager::SoundManager()
{
		// Load the sound in to the buffers
		m_fireBuffer.loadFromFile("sound/fire1.wav");
		m_fallInFireBuffer.loadFromFile("sound/fallinfire.wav");
		m_fallInWaterBuffer.loadFromFile("sound/fallinwater.wav");
		m_jumpBuffer.loadFromFile("sound/jump.wav");
		m_reachGoalBuffer.loadFromFile("sound/reachgoal.wav");
		// Associate the sounds with the buffers
		m_fire1Sound.setBuffer(m_fireBuffer);
		m_fire2Sound.setBuffer(m_fireBuffer);
		m_fire3Sound.setBuffer(m_fireBuffer);
		
		m_fallInFireSound.setBuffer(m_fallInFireBuffer);
		m_fallInWaterSound.setBuffer(m_fallInWaterBuffer);
		m_jumpSound.setBuffer(m_jumpBuffer);
		m_reachGoalSound.setBuffer(m_reachGoalBuffer);

		// When the player is 50 pixels away sound is full volume
		float minDistance = 150;
		// The sound reduces steadily as the player moves further away
		float attenuation = 15;
		// Set all the attenuation levels
		m_fire1Sound.setAttenuation(attenuation);
		m_fire2Sound.setAttenuation(attenuation);
		m_fire3Sound.setAttenuation(attenuation);
		// Set all the minimum distance levels
		m_fire1Sound.setMinDistance(minDistance);
		m_fire2Sound.setMinDistance(minDistance);
		m_fire3Sound.setMinDistance(minDistance);
		// Loop all the fire sounds
		// when they are played
		m_fire1Sound.setLoop(true);
		m_fire2Sound.setLoop(true);
		m_fire3Sound.setLoop(true);
	
}

void SoundManager::playFire(sf::Vector2f emitterLocation, sf::Vector2f listenerLocation)
{
	// Listener
	Listener::setPosition(listenerLocation.x, listenerLocation.y, 0.0f);

	switch (m_nextSound)
	{
	case 1:
		// Locate and move the source of the sound
		m_fire1Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);

		if (m_fire1Sound.getStatus() == Sound::Status::Stopped)
		{
			// play the sound, if its not already
			m_fire1Sound.play();
		}
		break;

	case 2:
		// Locate and move the source of the sound
		m_fire2Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);

		if (m_fire2Sound.getStatus() == Sound::Status::Stopped)
		{
			// play the sound, if its not already
			m_fire2Sound.play();
		}
		break;
	case 3:
		// Locate and move the source of the sound
		m_fire3Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);

		if (m_fire3Sound.getStatus() == Sound::Status::Stopped)
		{
			// play the sound, if its not already
			m_fire3Sound.play();
		}
		break;
	}

	// Increment to the next fire sound
	m_nextSound++;

	// go back to 1 when the third sound has been started
	if (m_nextSound > 3)
	{
		m_nextSound = 1;
	}
}

void SoundManager::playFallInFire()
{
	m_fallInFireSound.setRelativeToListener(true);
	m_fallInFireSound.play();
}

void SoundManager::playFallInWater()
{

	m_fallInWaterSound.setRelativeToListener(true);
	m_fallInWaterSound.play();
}

void SoundManager::playJump()
{

	m_jumpSound.setRelativeToListener(true);
	m_jumpSound.play();
}

void SoundManager::playReachGoal()
{

	m_reachGoalSound.setRelativeToListener(true);
	m_reachGoalSound.play();
}
