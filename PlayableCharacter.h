#ifndef __PLAYABLECHARACTER__
#define __PLAYABLECHARACTER__

#include <SFML/Graphics.hpp>

class PlayableCharacter
{

	float m_gravity;

	float m_speed = 400;

	sf::Vector2f m_position;

	// Character's body parts
	sf::FloatRect m_feet;
	sf::FloatRect m_head;
	sf::FloatRect m_right;
	sf::FloatRect m_left;
	
	sf::Texture m_texture;


protected:
	// of course we will need a sprite
	sf::Sprite m_sprite;

	// how long does a jump last
	float m_jumpDuration;

	// Is character currently jumping or falling
	bool m_isJumping;
	bool m_isFalling;

	// WHich directions is the character currently moving in
	bool m_leftPressed;
	bool m_rightPressed;

	// how long has this jump lasted so far
	float m_timeThisJump;

	// Has the player initiated a jump
	bool m_justJumped = false;

public:
	void spawn(sf::Vector2f startPosition, float gravity);

	// pure virtual func
	bool virtual handleInput() = 0;

	sf::FloatRect getPosition();

	sf::FloatRect getHead();
	sf::FloatRect getFeet();
	sf::FloatRect getRight();
	sf::FloatRect getLeft();

	sf::Sprite getSprite();

	// make the character stand firm
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	sf::Vector2f getCenter();

	void update(float elapsedTime);

};  // END of class
#endif
