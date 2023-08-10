#include "Bob.h"
#include "TextureHolder.h"


using namespace sf;

Bob::Bob()
{
	m_sprite = Sprite(TextureHolder::getTexture("graphics/bob.png"));

	m_jumpDuration = 0.25f;
}

bool Bob::handleInput()
{
	this->m_justJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		// Start a jump if not already jumping
		// but only if standing on a block (not falling)
		if (!m_isJumping && !m_isFalling)
		{
			m_isJumping = true;
			m_timeThisJump = 0;
			m_justJumped = true;
		}

	}
	else
	{
		//m_isJumping = false;
		//m_isFalling = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_leftPressed = true;
	}
	else
	{
		m_leftPressed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_rightPressed = true;
	}
	else
	{
		m_rightPressed = false;
	}

	return m_justJumped;
}
