#include "PlayableCharacter.h"

using namespace sf;

void PlayableCharacter::spawn(sf::Vector2f startPosition, float gravity)
{
	// Place the player at the starting point
	m_position.x = startPosition.x;
	m_position.y = startPosition.y;

	// Initialize gravity
	m_gravity = gravity;

	// Move the sprite into position
	m_sprite.setPosition(m_position);
}

sf::FloatRect PlayableCharacter::getPosition()
{
	return m_sprite.getGlobalBounds();
}

sf::FloatRect PlayableCharacter::getHead()
{
	return m_head;
}

sf::FloatRect PlayableCharacter::getFeet()
{
	return m_feet;
}

sf::FloatRect PlayableCharacter::getRight()
{
	return m_right;
}

sf::FloatRect PlayableCharacter::getLeft()
{
	return m_left;
}

sf::Sprite PlayableCharacter::getSprite()
{
	return m_sprite;
}

void PlayableCharacter::stopFalling(float position)
{
	m_position.y = position - getPosition().height;
	m_sprite.setPosition(m_position);
	m_isFalling = false;
}

void PlayableCharacter::stopRight(float position)
{

	m_position.x = position - m_sprite.getGlobalBounds().width;
	m_sprite.setPosition(m_position);
}

void PlayableCharacter::stopLeft(float position)
{
	m_position.x = position + m_sprite.getGlobalBounds().width;
	m_sprite.setPosition(m_position);
}

void PlayableCharacter::stopJump()
{
	// Stop a jump early 
	m_isJumping = false;
	m_isFalling = true;
}

Vector2f PlayableCharacter::getCenter()
{
	return Vector2f(m_position.x + m_sprite.getGlobalBounds().width / 2, m_position.y + m_sprite.getGlobalBounds().height / 2);
}

void PlayableCharacter::update(float elapsedTime)
{
	if (m_rightPressed)
	{
		m_position.x += m_speed * elapsedTime;
	}

	if (m_leftPressed)
	{
		m_position.x -= m_speed * elapsedTime;
	}

	// Handle Jumping
	if (m_isJumping)
	{
		// Update how long the jump has been going
		m_timeThisJump += elapsedTime;

		// is the jump going upwards?
		if (m_timeThisJump < m_jumpDuration)
		{
			// Move up at twice gravity
			m_position.y -= m_gravity * 2 * elapsedTime;
		}
		else
		{
			m_isJumping = false;
			m_isFalling = true;
		}
	}

	// Apply gravity
	if (m_isFalling)
	{
		m_position.y += m_gravity * elapsedTime;
	}

	// update the rect for all body parts
	FloatRect r = getPosition();

	// Feet
	m_feet.left = r.left + 3;
	m_feet.top = r.top + r.height - 30;
	m_feet.width = r.width - 6;
	m_feet.height = 10;

	// Head
	m_head.left = r.left + 2;
	m_head.top = r.top + 2;
	m_head.width = r.width - 6;
	m_head.height = r.height * 0.3f;

	// Right
	m_right.left = r.left + r.width - 10;
	m_right.top = r.top + r.height * .35f;
	m_right.width = 10;
	m_right.height = r.height * 0.3f;

	// Left
	m_left.left = r.left;
	m_left.top = r.top + r.height * 0.35f;
	m_left.width = 10;
	m_left.height = r.height * 0.3f;

	// Move the sprite into position
	m_sprite.setPosition(m_position);
}
