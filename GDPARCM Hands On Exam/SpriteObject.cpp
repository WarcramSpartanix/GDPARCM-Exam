#include "SpriteObject.h"

SpriteObject::SpriteObject(String name) : AGameObject(name)
{
	this->sprite = new sf::Sprite();
}

void SpriteObject::initialize()
{
	
}

void SpriteObject::processInput(sf::Event event)
{
}

void SpriteObject::update(sf::Time deltaTime)
{
}
