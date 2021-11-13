#pragma once
#include "../IETThread.h"
#include "../SpriteObject.h"

class Deleter :
	public IETThread
{
public:
    Deleter(std::string name, float x, float y);

private:
    int index = 0;
    void run() override;
    SpriteObject* spriteIndicator;
};

