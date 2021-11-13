#pragma once
#include "../IETThread.h"
#include "../SpriteObject.h"

class Searcher :
    public IETThread
{
public:
    Searcher(std::string name, float x, float y);

private:
    int index = 0;
    void run() override;
    SpriteObject* spriteIndicator;
    SpriteObject* spriteSearched;
};

