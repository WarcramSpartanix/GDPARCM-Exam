#pragma once
#include "AGameObject.h"

const float SPRITE_OBJECT_WIDTH = 100.0f;
const float SPRITE_OBJECT_HEIGHT = 100.0f;

class SpriteObject :
    public AGameObject
{
public:
	SpriteObject(String name);

	void initialize();
	void processInput(sf::Event event);
	void update(sf::Time deltaTime);
	
	
};

