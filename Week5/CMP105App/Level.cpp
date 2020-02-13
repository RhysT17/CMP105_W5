#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombTexture.loadFromFile("gfx/animZombie.png");
	zombie.setSize(sf::Vector2f(55, 108));
	zombie.setPosition(100, 100);
	zombie.setTexture(&zombTexture);

	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	mario.setSize(sf::Vector2f(15, 21));
	mario.setPosition(100, 400);
	mario.setTexture(&marioTexture);
	mario.setInput(in);
	isMario = true;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		input->setKeyUp(sf::Keyboard::Right);
		if (!isMario)
		{
			zombie.setPosition(zombie.getPosition().x + 2, zombie.getPosition().y);
			if (zombie.walk.getFlipped())
			{
				zombie.walk.setFlipped(false);
			}
		}
		else
		{
			mario.setPosition(mario.getPosition().x + 2, mario.getPosition().y);
			if (mario.walk.getFlipped())
			{
				mario.walk.setFlipped(false);
			}
		}
	}

	if (input->isKeyDown(sf::Keyboard::Left))
	{
		input->setKeyUp(sf::Keyboard::Left);
		if (!isMario)
		{
			zombie.setPosition(zombie.getPosition().x - 2, zombie.getPosition().y);
			if (!zombie.walk.getFlipped())
			{
				zombie.walk.setFlipped(true);
			}
		}
		else
		{
			mario.setPosition(mario.getPosition().x - 2, mario.getPosition().y);
			if (!mario.walk.getFlipped())
			{
				mario.walk.setFlipped(true);
			}
		}
	}

	if (input->isKeyDown(sf::Keyboard::S))
	{
		input->setKeyUp(sf::Keyboard::S);
		if (isMario)
			isMario = false;
		else
			isMario = true;
	}
}

// Update game objects
void Level::update(float dt)
{
	mario.update(dt);
	zombie.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(zombie);
	window->draw(mario);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}