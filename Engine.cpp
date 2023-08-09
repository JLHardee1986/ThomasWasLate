#include "Engine.h"

using namespace sf;

Engine::Engine()
{
	// Get the screen resolution
	// and create an SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_window.create(VideoMode(resolution.x, resolution.y), "Thomas Was Late", Style::Fullscreen);

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