#ifndef __SOUNDMANAGER__
#define __SOUNDMANAGER__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

class SoundManager
{
	// The buffers
	sf::SoundBuffer m_fireBuffer;
	sf::SoundBuffer m_fallInFireBuffer;
	sf::SoundBuffer m_fallInWaterBuffer;
	sf::SoundBuffer m_jumpBuffer;
	sf::SoundBuffer m_reachGoalBuffer;

	// The sounds
	sf::Sound m_fire1Sound;
	sf::Sound m_fire2Sound;
	sf::Sound m_fire3Sound;
	sf::Sound m_fallInFireSound;

	sf::Sound m_fallInWaterSound;
	sf::Sound m_jumpSound;
	sf::Sound m_reachGoalSound;

	// Which sound should we use next, fire 1, 2, or 3
	int m_nextSound = 1;


public:

	SoundManager();

	void playFire(sf::Vector2f emitterLocation, sf::Vector2f listenerLocation);

	void playFallInFire();
	void playFallInWater();
	void playJump();
	void playReachGoal();
};

#endif