#include "Searcher.h"
#include <random>
#include "../GameObjectManager.h"
#include "ThreadManager.h"
#include "../IconManager.h"
#include "../TextureManager.h"

Searcher::Searcher(std::string name, float x, float y)
{
	spriteIndicator = new SpriteObject(name);
	spriteIndicator->setPosition(x, y);
	spriteIndicator->setTexture(TextureManager::getInstance()->getFromTextureMap("Searcher", 0));
	GameObjectManager::getInstance()->addObject(spriteIndicator);
}

void Searcher::run()
{
	srand(time(0) + (int)spriteIndicator->getPosition().y);
	while (ThreadManager::getInstance()->isRunning)
	{
		int temp = (rand() % 300) + 0;
		sleep(temp);

		IconSlot* iconslot = IconManager::getInstance()->GetIconSlotAtIndex(index);
		iconslot->deleterSemaphore->acquire();		// to wait if deleter is deleting
		iconslot->deleterSemaphore->release();
		iconslot->inserterSemaphore->acquire();		// to wait if inserter is inserting
		iconslot->inserterSemaphore->release();
		iconslot->searcherSemaphore->acquire();
		iconslot->emptySemaphore->acquire();		// to wait if slot is empty
		iconslot->emptySemaphore->release();
		
		// CS
		spriteSearched = IconManager::getInstance()->GetSpriteAtIndex(index);
		spriteIndicator->setPosition(spriteSearched->getPosition().x, spriteIndicator->getPosition().y);
		// CS END

		iconslot->searcherSemaphore->release();
		
		index++;
		index %= IconManager::MAX_ACTIVE_SPRITE_ICONS;
	}
}
