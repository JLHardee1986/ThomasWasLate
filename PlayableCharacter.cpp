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
	// stop a jump early
	m_isJumping = false;
	m_isFalling = true;
}

sf::Vector2f PlayableCharacter::getCenter()
{
	return sf::Vector2f();
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
	m_feet.top = r.top + r.height - 1;
	m_feet.width = r.width - 6;
	m_feet.height = 1;

	// Head
	m_head.left = r.left;
	m_head.top = r.top + (r.height * .3f);
	m_head.width = r.width;
	m_head.height = 1;

	// Right
	m_right.left = r.left + r.width - 2;
	m_right.top = r.top + r.height * .35f;
	m_right.width = 1;
	m_right.height = r.height * 0.3f;

	// Left
	m_left.left = r.left;
	m_left.top = r.top + r.height * 0.5f;
	m_left.width = 1;
	m_left.height = r.height * 0.3f;

	// Move the sprite into position
	m_sprite.setPosition(m_position);
}
