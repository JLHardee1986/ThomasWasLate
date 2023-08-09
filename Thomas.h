#ifndef __THOMAS__
#define __THOMAS__

#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter
{
public:
	Thomas();

	bool handleInput() override final;
};

#endif
