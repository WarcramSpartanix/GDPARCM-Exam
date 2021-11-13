#pragma once
#include <vector>
#include "Searcher.h"
#include "Inserter.h"
#include "Deleter.h"

class ThreadManager
{
public:
	static ThreadManager* getInstance();

	void Start();

	static float FIXED_DISTANCE_Y;
	bool isRunning = true;
private:
	ThreadManager();
	ThreadManager(ThreadManager const&) {};             // copy constructor is private
	ThreadManager& operator=(ThreadManager const&) {};  // assignment operator is private
	static ThreadManager* sharedInstance;

private:
	std::vector<Searcher*> searcherList;
	std::vector<Inserter*> inserterList;
	std::vector<Deleter*> deleterList;
};

