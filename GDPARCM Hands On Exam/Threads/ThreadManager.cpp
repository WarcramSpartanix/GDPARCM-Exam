#include "ThreadManager.h"
#include "../IconManager.h"
#include <random>

ThreadManager* ThreadManager::sharedInstance = nullptr;

float ThreadManager::FIXED_DISTANCE_Y = 110;

ThreadManager* ThreadManager::getInstance()
{
	if (sharedInstance == nullptr) {
		//initialize
		sharedInstance = new ThreadManager();
	}

	return sharedInstance;
}

void ThreadManager::Start()
{
	for (int i = 0; i < searcherList.size(); i++)
	{
		searcherList[i]->start();
	}

	for (int i = 0; i < inserterList.size(); i++)
	{
		inserterList[i]->start();
	}

	for (int i = 0; i < deleterList.size(); i++)
	{
		deleterList[i]->start();
	}
}


ThreadManager::ThreadManager()
{
	searcherList.push_back(new Searcher("Searcher1", IconManager::FIXED_X, IconManager::FIXED_Y + FIXED_DISTANCE_Y));
	searcherList.push_back(new Searcher("Searcher2", IconManager::FIXED_X, IconManager::FIXED_Y + FIXED_DISTANCE_Y * 2));
	searcherList.push_back(new Searcher("Searcher3", IconManager::FIXED_X, IconManager::FIXED_Y + FIXED_DISTANCE_Y * 3));
	searcherList.push_back(new Searcher("Searcher4", IconManager::FIXED_X, IconManager::FIXED_Y + FIXED_DISTANCE_Y * 4));
	inserterList.push_back(new Inserter("Inserter1", IconManager::FIXED_X, IconManager::FIXED_Y + FIXED_DISTANCE_Y * 5));
	inserterList.push_back(new Inserter("Inserter2", IconManager::FIXED_X, IconManager::FIXED_Y + FIXED_DISTANCE_Y * 6));
	deleterList.push_back(new Deleter("Deleter1", IconManager::FIXED_X, IconManager::FIXED_Y + FIXED_DISTANCE_Y * 7));



	srand(time(0));
}
