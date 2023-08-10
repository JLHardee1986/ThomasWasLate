#include "Engine.h"

using namespace sf;

void Engine::input()
{
	Event e;
	while (m_window.pollEvent(e))
	{
		switch (e.type)
		{
			case Event::Closed:
				m_window.close();
				break;
			case Event::KeyPressed:
				if (e.key.code == Keyboard::Escape)
				{
					m_window.close();
				}
				else if (e.key.code == Keyboard::Return)
				{
					m_playing = true;
				}

				// Switch between Thomas and Bob
				if (Keyboard::isKeyPressed(Keyboard::Q))
				{
					m_character1 = !m_character1;
				}

				//switch between full and split screen
				if (Keyboard::isKeyPressed(Keyboard::E))
				{
					m_splitScreen = !m_splitScreen;
				}
				break;
			default:
				break;
		}

	}

	// handle input specific to Thomas
	if (m_thomas.handleInput())
	{
		// play a jump sound
		m_sMgr.playJump();
	}

	// Handle input specific to Bob
	if (m_bob.handleInput())
	{
		// Play a jump sound
		m_sMgr.playJump();

	}
}