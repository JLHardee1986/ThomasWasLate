#ifndef __ENGINE__
#define __ENGINE__

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "Bob.h"
#include "Thomas.h"

class Engine
{

	bool m_fullscreen{ false };

	TextureHolder th;

	// Thomas and his friend, Bob
	Thomas m_thomas;
	Bob m_bob;

	// A class to manage all the levels
	LevelManager m_lMgr;

	// Create a sound manager
	SoundManager m_sMgr;
	
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	// Force pushing characters down
	const int GRAVITY = 300;

	// regular RenderWindow
	sf::RenderWindow  m_window;

	// The main views
	sf::View m_mainView;
	sf::View m_leftView;
	sf::View m_rightView;

	// Three views for the background
	sf::View m_bgMainView;
	sf::View m_bgLeftView;
	sf::View m_bgRightView;

	sf::View m_hudView;

	// declare a sprite and a Texture
	// for the background
	sf::Sprite m_backgroundSprite;
	sf::Texture m_backgroundTexture;
	sf::RectangleShape m_rs;
	sf::RectangleShape m_rsBob;

	// IS the game currently playing
	bool m_playing = false;

	// is character 1 of 2 the current focus?
	bool m_character1 = true;

	// Start in full screen mode (not split screen)
	bool m_splitScreen = false;

	// Time left in the current level (seconds)
	float m_timeRemaining = 10;
	sf::Time m_gameTimeTotal;

	// Is it time for a new / first level?
	bool m_newLevelRequired = true;

	// The vertex array for the level tiles
	sf::VertexArray m_vertArrLevel;

	// the 2d array with the map for the level
	// a pointer to a pointer
	int** m_arrayLevel = nullptr;

	// Texture for the level tiles
	sf::Texture m_textureTiles;

	// private functions for internal use
	void input();
	void update(float dtAsSeconds);
	void draw();

	void loadLevel();
	bool detectCollisions(PlayableCharacter& character);

	// Make a vector of the best places to emit sounds from
	void populateEmitters(std::vector<sf::Vector2f>& vSoundEmitters, int** arrayLevel);

	// A vector of Vector2ffor the fire emitter locations
	std::vector<sf::Vector2f> m_fireEmitters;
public:

	// The engine constructor
	Engine();


	//  Run will call all the private functions
	void run();

};

#endif
