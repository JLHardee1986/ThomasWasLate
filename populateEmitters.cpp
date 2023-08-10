#include "Engine.h"

using namespace std;
using namespace sf;

void Engine::populateEmitters(std::vector<sf::Vector2f>& vSoundEmitters, int** arrayLevel)
{
	// Make sure the vector is empty
	bool result = vSoundEmitters.empty();
	// Keep track of the previous emitter
	// so we don't make too many
	FloatRect previousEmitter;
	// Search for fire in the level
	for (int x = 0; x < (int)m_lMgr.getLevelSize().x; x++)
	{
		for (int y = 0; y < (int)m_lMgr.getLevelSize().y; y++)
		{
			if (arrayLevel[y][x] == 2)// fire is present
			{
				// Skip over any fire tiles too 
				// near a previous emitter
				if (!FloatRect((float)x * (float)TILE_SIZE, (float)y * (float)TILE_SIZE, (float)TILE_SIZE,(float)TILE_SIZE).intersects(previousEmitter))
				{
					// Add the coordinates of this water block
					vSoundEmitters.push_back(Vector2f((float)x * (float)TILE_SIZE, (float)y * (float)TILE_SIZE));
					// Make a rectangle 6 blocks x 6 blocks,
					// so we don't make any more emitters 
					// too close to this one
					previousEmitter.left = (float)x * (float)TILE_SIZE;
					previousEmitter.top = (float)y * (float)TILE_SIZE;
					previousEmitter.width = (float)TILE_SIZE * 6.f;
					previousEmitter.height = (float)TILE_SIZE * 6.f;
				}
			}
		}
	}
	return;
}