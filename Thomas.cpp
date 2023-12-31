#include "Thomas.h"
#include "TextureHolder.h"

using namespace sf;

Thomas::Thomas()
{
	m_sprite = Sprite(TextureHolder::getTexture("graphics/thomas.png"));

	m_jumpDuration = 0.45f;
	
}

bool Thomas::handleInput()
{
	if (m_justJumped)
	{
		dontJumpAgain = true;
	}

	m_justJumped = false;

		if (Keyboard::isKeyPressed(Keyboard::W))
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
	

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_leftPressed = true;
	}
	else
	{
		m_leftPressed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		m_rightPressed = true;
	}
	else
	{
		m_rightPressed = false;
	}

	return m_justJumped;
}
