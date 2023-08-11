#include "Engine.h"

using namespace sf;

Engine::Engine()
{
	
	m_rs.setFillColor(Color(0, 0, 0, 0));
	m_rs.setOutlineColor(Color(255, 255, 255, 255));
	m_rs.setOutlineThickness(2.f);
	m_rs.setSize(Vector2f(m_thomas.getSprite().getGlobalBounds().getSize()));
	m_rs.setPosition({ m_thomas.getPosition().left, m_thomas.getPosition().top });

	m_rsBob.setFillColor(Color(0, 0, 0, 0));
	m_rsBob.setOutlineColor(Color(255, 255, 255, 255));
	m_rsBob.setOutlineThickness(2.f);
	m_rsBob.setSize(Vector2f(m_bob.getSprite().getGlobalBounds().getSize()));
	m_rsBob.setPosition({ m_bob.getPosition().left, m_bob.getPosition().top });

	// Get the screen resolution
	// and create an SFML window and View
	Vector2f resolution;
	resolution.x = (float)VideoMode::getDesktopMode().width;
	resolution.y = (float)VideoMode::getDesktopMode().height;

	if (m_fullscreen)
	{
		m_window.create(VideoMode({ (unsigned int)resolution.x, (unsigned int)resolution.y }), "Thomas Was Late", Style::Fullscreen);
	}
	else
	{
		m_window.create(VideoMode({ (unsigned int)1280, (unsigned int)720 }), "Thomas Was Late", Style::Default);
	}

	//m_window.setFramerateLimit(60);
	// Initialize the fullscreen view
	m_mainView.setSize(resolution);
	m_hudView.reset(FloatRect(0, 0, resolution.x, resolution.y));

	// Initialize the splt-screen views
	m_leftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

	m_rightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_bgLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

	m_bgRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_backgroundTexture = TextureHolder::getTexture("graphics/background.png");

	// associate the sprite with the texture
	m_backgroundSprite.setTexture(m_backgroundTexture);


	// Load the texture for the background vertex array
	m_textureTiles = TextureHolder::getTexture("graphics/tiles_sheet.png");

	m_PS.init(1000);

}

void Engine::run()
{
	Clock clock;

	while (m_window.isOpen())
	{
		Time dt = clock.restart();

		// update the total game time
		m_gameTimeTotal += dt;

		// make a decimal fraction form the delta time
		float dtAsSeconds = dt.asSeconds();

		// call each part of the game loop in turn
		input();

		update(dtAsSeconds);

		draw();

		

		

	}
}