#pragma once
#include <vector>
#include "SpriteObject.h"
#include "IconSlot.h"

class IconManager
{
public:
	static IconManager* getInstance();

	void AddInactiveSprite(SpriteObject*);
	void SetSpriteAtIndex(int index);
	SpriteObject* GetSpriteAtIndex(int index);

	IconSlot* GetIconSlotAtIndex(int index);
	

	static int MAX_BANK_ICONS;
	static int MAX_ACTIVE_SPRITE_ICONS;
	static float FIXED_DISTANCE_X;
	static float FIXED_X;
	static float FIXED_Y;
private:
	IconManager();
	IconManager(IconManager const&) {};             // copy constructor is private
	IconManager& operator=(IconManager const&) {};  // assignment operator is private
	static IconManager* sharedInstance;

private:
	std::vector<IconSlot*> iconSlotList;
	std::vector<SpriteObject*> inactiveSpriteObjectList;

	
};

