#pragma once
#include <semaphore>
#include "SpriteObject.h"
#include "SFML/Graphics.hpp"

class IconSlot
{
public:
	IconSlot(float x, float y);
	~IconSlot();

	void SetSpriteObject(SpriteObject* spriteObject);
	SpriteObject* GetSpriteObject();

	bool inserting = false;

	std::binary_semaphore* deleterSemaphore;
	std::binary_semaphore* inserterSemaphore;
	std::counting_semaphore<4>* searcherSemaphore;
	std::binary_semaphore* emptySemaphore;
private:
	float x;
	float y;
	SpriteObject* spriteObject;

	
};

