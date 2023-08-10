#include "Engine.h"
#include <iostream>

using namespace std;
using namespace sf;

bool Engine::detectCollisions(PlayableCharacter& character)
{
	bool reachedGoal = false;
	// Make a rect for all his parts
	FloatRect detectionZone = character.getPosition();

	// Make a FloatRect to test each block
	FloatRect block;

	block.width = TILE_SIZE;
	block.height = TILE_SIZE;

	// Build a zone around thomas to detect collisions
	int startX = (int)(detectionZone.left / TILE_SIZE) - 1;
	int startY = (int)(detectionZone.top / TILE_SIZE) - 1;
	int endX = (int)(detectionZone.left / TILE_SIZE) + 2;

	// Thomas is quite tall so check a few tiles vertically
	int endY = (int)(detectionZone.top / TILE_SIZE) + 3;

	// Make sure we don't test positions lower than zero
	// Or higher than the end of the array
	if (startX < 0)startX = 0;
	if (startY < 0)startY = 0;
	if (endX >= m_lMgr.getLevelSize().x)
		endX = m_lMgr.getLevelSize().x;
	if (endY >= m_lMgr.getLevelSize().y)
		endY = m_lMgr.getLevelSize().y;

	// Has the character fallen out of the map?
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!This can be part of level manager!!!!!!!!!!!!!!!!!!!!!!!!
	FloatRect level(0, 0, m_lMgr.getLevelSize().x * TILE_SIZE, m_lMgr.getLevelSize().y * TILE_SIZE);
	if (!character.getPosition().intersects(level))
	{
		// respawn the character
		character.spawn(m_lMgr.getStartPosition(), GRAVITY);
	}

	for (int x = startX; x < endX; x++)
	{
		for (int y = startY; y < endY; y++)
		{
			// Initialize the starting position of the current block
			block.left = x * TILE_SIZE;
			block.top = y * TILE_SIZE;

			// Has character been burnt or drowned?
			// Use head as this allows him to sink a bit
			if (m_arrayLevel[y][x] == 2 || m_arrayLevel[y][x] == 3)
			{
				if (character.getHead().intersects(block))
				{
					character.spawn(m_lMgr.getStartPosition(), GRAVITY);
					// Which sound should be played?
					if (m_arrayLevel[y][x] == 2)// Fire, ouch!
					{
						// Play a sound
						m_sMgr.playFallInFire();

					}
					else // Water
					{
						// Play a sound
						m_sMgr.playFallInWater();
					}
				}
			}


			// Is character colliding with a regular block
			if (m_arrayLevel[y][x] == 1)
			{

				if (character.getRight().intersects(block))
				{
					cout << "right" << endl;
					character.stopRight(block.left);
				}
				else if (character.getLeft().intersects(block))
				{
					cout << "left" << endl;
					character.stopLeft(block.left);
				}


				if (character.getFeet().intersects(block))
				{
					cout << "Feet" << endl;
					character.stopFalling(block.top);
				}
				else if (character.getHead().intersects(block))
				{
					cout << "head" << endl;
					character.stopJump();
				}
			}

			// More collision detection here once we have learned about particle effects

			// Has the character reached the goal?
			if (m_arrayLevel[y][x] == 4)
			{
				// Character has reached the goal
				reachedGoal = true;
			}

		}

	}

	// All done, return, wheteher or not a new level might be required
	return reachedGoal;
}

//bool Engine::detectCollisions(PlayableCharacter& character)
//{
//	bool reachedGoal = false;
//	// Make a rect for all his parts
//	FloatRect detectionZone = character.getPosition();
//
//	// Make a FloatRect to test each block
//	FloatRect block;
//
//	block.width = (float)TILE_SIZE;
//	block.height = (float)TILE_SIZE;
//
//	// Build a zone around Thomas to detect collisions
//	Vector2i strt, end;
//	strt.x = character.getSprite().getGlobalBounds().left;
//	strt.y = character.getSprite().getGlobalBounds().top;
//	end.x = character.getSprite().getGlobalBounds().width + strt.x;
//	end.y = character.getSprite().getGlobalBounds().height + strt.y;
//
//
//	int startX = strt.x / TILE_SIZE;
//	//(int)(detectionZone.left / (float)TILE_SIZE) - 1;
//	int startY = strt.y / TILE_SIZE;
//	//(int)(detectionZone.top / (float)TILE_SIZE) - 1;
//	int endX = (end.x / TILE_SIZE) + 2;
//		//(int)(detectionZone.left / (float)TILE_SIZE) + 2;
//	// Thomas is quite tall so check a few tiles vertically
//	int endY = (end.y / TILE_SIZE) + 3;
//	//(int)(detectionZone.top / (float)TILE_SIZE) + 3;
//
//	//Make sure we don't test positions lower than zero
//	// or higher than the end of the array
//	if (startX < 0) { startX = 0; }
//	if (startY < 0) { startY = 0; }
//	if (endX >= m_lMgr.getLevelSize().x)
//	{
//		endX = m_lMgr.getLevelSize().x - 1;
//	}
//	if (endY >= m_lMgr.getLevelSize().y)
//	{
//		endY = m_lMgr.getLevelSize().y - 1;
//	}
//
//	// Has the player palen out of the map?
//	FloatRect level(0.f, 0.f, (float)m_lMgr.getLevelSize().x * (float)TILE_SIZE, (float)m_lMgr.getLevelSize().y * (float)TILE_SIZE);
//
//	if (!character.getPosition().intersects(level))
//	{
//		// respawn the character
//		character.spawn(m_lMgr.getStartPosition(), (float)GRAVITY);
//	}
//
//	// Loop through all the local blocks
//	for (int y = startY; y < endY - 2; y++)
//	{
//		for (int x = startX; x < endX; x++)
//		{
//			// initialize the starting point of the current block
//			block.left = (float)x * (float)TILE_SIZE + m_lMgr.getStartPosition().x;
//			block.top = (float)y * (float)TILE_SIZE + m_lMgr.getStartPosition().y;
//
//			// has the character been burnt or drowned?
//			//  Use head as this allows him to sink a bit
//			if (m_arrayLevel[y][x] == 2 || m_arrayLevel[y][x] == 3)
//			{
//				if (character.getHead().intersects(block))
//				{
//					//character.spawn(m_lMgr.getStartPosition(), (float)GRAVITY);
//					// Which sound should be played?
//					if (m_arrayLevel[y][x] == 2)
//					{
//
//						// play a sound
//						m_sMgr.playFallInFire();
//					}
//					else
//					{
//						// play a sound
//						m_sMgr.playFallInWater();
//
//					}
//				}
//			}
//
//			// Is character colliding with a regular block
//			if (m_arrayLevel[y][x] == 1)
//			{
//				if (character.getRight().intersects(block))
//				{
//					character.stopRight(block.left);
//				}
//				else if (character.getLeft().intersects(block))
//				{
//					// maybe take away TILE_SIZE
//					character.stopLeft(block.left + TILE_SIZE);
//				}
//			}
//
//			if (character.getFeet().intersects(block))
//			{
//
//				character.stopFalling(block.top);
//			}
//			else if (character.getHead().intersects(block))
//			{
//				character.stopJump();
//			}
//
//			// More collision detection here once we have learned about particle effects
//
//		    // Has the character reached the goal?
//			if (m_arrayLevel[y][x] == 4)
//			{
//				// Character has reached the goal
//				reachedGoal = true;
//			}
//		}
//
//
//	}
//
//	return reachedGoal;
//
//}