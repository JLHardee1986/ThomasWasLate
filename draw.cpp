#include "Engine.h"

void Engine::draw()
{
	m_window.clear(sf::Color::White);

	if (!m_splitScreen)
	{
		// switch to background view
		m_window.setView(m_bgMainView);
		// draw the background
		m_window.draw(m_backgroundSprite);
		// switch to main view
		m_window.setView(m_mainView);

		// Draw Thomas
		m_window.draw(m_thomas.getSprite());

		// Draw Bob
		m_window.draw(m_bob.getSprite());
	}
	else
	{
		// SPLIT SCREEN VIEW ACTIVATED
		// First draw Thomas side of the screen

		// Switch to background view
		m_window.setView(m_bgLeftView);
		// draw the background
		m_window.draw(m_backgroundSprite);
		// switch to left view
		m_window.setView(m_leftView);


		// Draw Bob
		m_window.draw(m_bob.getSprite());	

		// Draw Thomas
		m_window.draw(m_thomas.getSprite());


		// Now draw Bob's side of the screen
		
		// Switch to background view
		m_window.setView(m_bgRightView);
		// draw the background
		m_window.draw(m_backgroundSprite);
		// switch to left view
		m_window.setView(m_rightView);

		// Draw Thomas
		m_window.draw(m_thomas.getSprite());

		// Draw Bob
		m_window.draw(m_bob.getSprite());
	}

	// Draw the HUD
	// switch to m_hudView;
	m_window.setView(m_hudView);

	// show everything we have just drawn.


	m_window.display();
}