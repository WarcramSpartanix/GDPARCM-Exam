#include "Inserter.h"
#include <random>
#include "../GameObjectManager.h"
#include "ThreadManager.h"
#include "../IconManager.h"
#include "../TextureManager.h"

Inserter::Inserter(std::string name, float x, float y)
{
	spriteIndicator = new SpriteObject(name);
	spriteIndicator->setPosition(x, y);
	spriteIndicator->setTexture(TextureManager::getInstance()->getFromTextureMap("Inserter", 0));
	GameObjectManager::getInstance()->addObject(spriteIndicator);
}

void Inserter::run()
{
	srand(time(0) + (int)spriteIndicator->getPosition().y);
	while (ThreadManager::getInstance()->isRunning)
	{
		int temp = (rand() % 300) + 200;
		sleep(temp);
		
		IconSlot* iconslot = IconManager::getInstance()->GetIconSlotAtIndex(index);
		if (!iconslot->inserting)
		{
			iconslot->inserting = true;					// to tell other inserters that another inserter is here and to skip this index
			iconslot->deleterSemaphore->acquire();		// to wait if deleter is deleting
			iconslot->deleterSemaphore->release();
			iconslot->inserterSemaphore->acquire();		// to tell other threads that the inserter is performing

			//CS
			if (iconslot->GetSpriteObject() == nullptr)
			{
				IconManager::getInstance()->SetSpriteAtIndex(index);
				std::cout << spriteIndicator->getName() << " Insert At index " << index << std::endl;
			}
			SpriteObject* spriteTemp = iconslot->GetSpriteObject();
			spriteIndicator->setPosition(spriteTemp->getPosition().x, spriteIndicator->getPosition().y);
			//CS END

			iconslot->inserting = false;
			iconslot->inserterSemaphore->release();
			iconslot->emptySemaphore->release();			// to tell all the threads that this slot is no longer empty
		}
		index++;
		index %= IconManager::MAX_ACTIVE_SPRITE_ICONS;
	}

}
