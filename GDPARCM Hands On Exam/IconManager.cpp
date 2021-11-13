#include "IconManager.h"
#include "TextureManager.h"
#include "GameObjectManager.h"


int IconManager::MAX_ACTIVE_SPRITE_ICONS = 10;
int IconManager:: MAX_BANK_ICONS = 10;
float IconManager::FIXED_DISTANCE_X = 100;
float IconManager::FIXED_X = 50;
float IconManager::FIXED_Y = 50;

IconManager* IconManager::sharedInstance = nullptr;

IconManager* IconManager::getInstance()
{
	if (sharedInstance == nullptr) {
		//initialize
		sharedInstance = new IconManager();
	}

	return sharedInstance;
}

IconManager::IconManager()
{
	for (int i = 0; i < MAX_ACTIVE_SPRITE_ICONS; i++)
	{
		iconSlotList.push_back(new IconSlot(FIXED_X + FIXED_DISTANCE_X * i, FIXED_Y));
		SpriteObject* spriteTemp = new SpriteObject("Sprite" + std::to_string(i));
		spriteTemp->setTexture(TextureManager::getInstance()->getFromTextureMap("tile" + std::to_string(i), 0));
		iconSlotList[i]->SetSpriteObject(spriteTemp);

		GameObjectManager::getInstance()->addObject(spriteTemp);
	}
	for (int i = MAX_ACTIVE_SPRITE_ICONS; i < MAX_ACTIVE_SPRITE_ICONS + MAX_BANK_ICONS; i++)
	{
		SpriteObject* spriteTemp = new SpriteObject("Sprite" + std::to_string(i));
		spriteTemp->setTexture(TextureManager::getInstance()->getFromTextureMap("tile" + std::to_string(i), 0));
		AddInactiveSprite(spriteTemp);

		GameObjectManager::getInstance()->addObject(spriteTemp);
	}
}

void IconManager::AddInactiveSprite(SpriteObject* spriteObject)
{
	spriteObject->setPosition(-1000, -1000);
	inactiveSpriteObjectList.push_back(spriteObject);
}

void IconManager::SetSpriteAtIndex(int index)
{
	SpriteObject* spriteObject = inactiveSpriteObjectList[0];
	inactiveSpriteObjectList.erase(inactiveSpriteObjectList.begin());

	iconSlotList[index]->SetSpriteObject(spriteObject);

}

SpriteObject* IconManager::GetSpriteAtIndex(int index)
{
	return iconSlotList[index]->GetSpriteObject();
}

IconSlot* IconManager::GetIconSlotAtIndex(int index)
{
	return iconSlotList[index];
}


