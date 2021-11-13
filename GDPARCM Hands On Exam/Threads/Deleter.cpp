#include "Deleter.h"
#include <random>
#include "../GameObjectManager.h"
#include "ThreadManager.h"
#include "../IconManager.h"
#include "../TextureManager.h"

Deleter::Deleter(std::string name, float x, float y)
{
	spriteIndicator = new SpriteObject(name);
	spriteIndicator->setPosition(x, y);
	spriteIndicator->setTexture(TextureManager::getInstance()->getFromTextureMap("Deleter", 0));
	GameObjectManager::getInstance()->addObject(spriteIndicator);
}

void Deleter::run()
{
	srand(time(0) + (int)spriteIndicator->getPosition().y);
	while (ThreadManager::getInstance()->isRunning)
	{
		sleep(500);		// delete an icon every 500ms
		index = rand() % IconManager::MAX_ACTIVE_SPRITE_ICONS;

		IconSlot* iconslot = IconManager::getInstance()->GetIconSlotAtIndex(index);
		for (int i = 0; i < 4; i++)
		{
			iconslot->searcherSemaphore->acquire();		// Make sure no searhers are currently looking at the slot
		}

		iconslot->inserterSemaphore->acquire();		// to wait if inserter is inserting
		iconslot->inserterSemaphore->release();
		iconslot->emptySemaphore->acquire();		// To wait if empty &&
													// To tell all searchers that this slot is empty and they must wait
		// CS
		SpriteObject* spriteTemp = iconslot->GetSpriteObject();
		std::cout << "Delete " << spriteTemp->getName() << " At index " << index << std::endl;
		spriteIndicator->setPosition(spriteTemp->getPosition().x, spriteIndicator->getPosition().y);
		IconManager::getInstance()->AddInactiveSprite(spriteTemp);
		iconslot->SetSpriteObject(nullptr);
		// CS END


		iconslot->deleterSemaphore->acquire();		// to make sure no other thread can enter

		iconslot->deleterSemaphore->release();		// to tell all the threads that the deleter is not in this slot
		for (int i = 0; i < 4; i++)
		{
			iconslot->searcherSemaphore->release();
		}
	}
}
