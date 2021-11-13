#include "IconSlot.h"

IconSlot::IconSlot(float x, float y)
{
    this->x = x;
    this->y = y;

    this->deleterSemaphore = new std::binary_semaphore(1);
    this->inserterSemaphore = new std::binary_semaphore(1);
    this->searcherSemaphore = new std::counting_semaphore<4>(4);
    this->emptySemaphore = new std::binary_semaphore(1);
}

IconSlot::~IconSlot()
{
}

void IconSlot::SetSpriteObject(SpriteObject* spriteObject)
{
    this->spriteObject = spriteObject;
    if(spriteObject != nullptr)
        this->spriteObject->setPosition(x, y);
}

SpriteObject* IconSlot::GetSpriteObject()
{
    return spriteObject;
}
