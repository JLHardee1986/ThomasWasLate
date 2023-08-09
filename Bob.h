#ifndef __BOB__
#define __BOB__

#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{
public:
	Bob();

	bool handleInput() override final;
};

#endif