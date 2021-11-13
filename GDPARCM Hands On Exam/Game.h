#pragma once
#include "SFML/Graphics.hpp"
#include "AGameObject.h"
using namespace std;
using namespace sf;

class Game
{
private:
	void processEvents();
	void update(Time elapsedTime);
	void render();
	sf::RenderWindow window;
	float fps = 60.0f;

public:
	static const sf::Time	TIME_PER_FRAME;
	static const int WINDOW_WIDTH = 1600;
	static const int WINDOW_HEIGHT = 900;

	Game();
	~Game();
	void run();
	static Game* getInstance();
	static Game* sharedInstance;
	RenderWindow* getWindow();

	float getFPS();
	
};

