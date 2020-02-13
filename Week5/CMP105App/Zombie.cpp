#include "Zombie.h"

Zombie::Zombie()
{
	// Setup walk anim
	for (int i = 0; i < 385; i += 55)
		walk.addFrame(sf::IntRect(i, 0, 55, 108));

	walk.setFrameSpeed(1.f / 10.f);
}

Zombie::~Zombie()
{
}

void Zombie::update(float dt)
{
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
}
