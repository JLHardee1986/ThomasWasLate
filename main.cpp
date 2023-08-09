#include <iostream>

#include <SFML/Graphics.hpp>

#include <memory>
#include <utility>

#include "Engine.h"



int main()
{
	// Declare an instance of Engine
	Engine engine;
	
	 // Start the engine
	engine.run();
	
	// quit in the usual way
	return EXIT_SUCCESS;
}