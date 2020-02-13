#include "Mario.h"

Mario::Mario()
{
	// Setup walk anim
	for (int i = 0; i < 4; i++)
		walk.addFrame(sf::IntRect(i * 15, 0, 15, 21));

	walk.setFrameSpeed(1.f / 3.f);

	// Setup swim anim
	for (int i = 0; i < 3; i++)
		swim.addFrame(sf::IntRect(i * 16, 21, 16, 20));

	swim.setFrameSpeed(1.f / 4.f);

	// Setup duck anim
	for (int i = 0; i < 2; i++)
		duck.addFrame(sf::IntRect(i * 16, 41, 16, 20));

	duck.setFrameSpeed(1.f / 2.f);

	currentAnim = &walk;
	setTextureRect(currentAnim->getCurrentFrame());
}

Mario::~Mario()
{

}

void Mario::update(float dt)
{
	currentAnim->animate(dt);
	setTextureRect(currentAnim->getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::Up))
	{
		//input->setKeyUp(sf::Keyboard::Up);
		setSize(sf::Vector2f(16, 20));
		currentAnim = &swim;
		
	}
	else if (input->isKeyDown(sf::Keyboard::Down))
	{
		//input->setKeyUp(sf::Keyboard::Down);
		setSize(sf::Vector2f(16, 20));
		currentAnim = &duck;
	}
	else
	{
		currentAnim = &walk;
		setSize(sf::Vector2f(15, 21));
	} 
	
	currentAnim->reset();
	setTextureRect(currentAnim->getCurrentFrame());
}