#include "Game.h"
#include "GameObjectManager.h"
#include "TextureManager.h"
#include "IconManager.h"
#include "Threads/ThreadManager.h"

const float FRAME_RATE = 60.0f;
const sf::Time Game::TIME_PER_FRAME = sf::seconds(1.f / 60.f);
Game* Game::sharedInstance = NULL;
const int FISH_COUNT = 10;

Game::Game(): window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "GDPARCM: Hands On Exam", sf::Style::Close)
{
	sharedInstance = this;
	this->window.setFramerateLimit(int(FRAME_RATE));

}

Game::~Game()
{

}

void Game::processEvents()
{
	sf::Event event;
	

	if (this->window.pollEvent(event)) {
		switch (event.type) {

		case sf::Event::KeyPressed:
			break;

		default: GameObjectManager::getInstance()->processInput(event); break;
		case sf::Event::Closed:
			this->window.close();
			break;
		}
	}
}

void Game::update(Time elapsedTime)
{
	GameObjectManager::getInstance()->update(elapsedTime);
}

void Game::render()
{
	this->window.clear();
	GameObjectManager::getInstance()->draw(&this->window);
	this->window.display();
}



void Game::run()
{
	sf::Clock clock;
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;


	bool finished = false;
	float elapsedTime = 0.0f;

	IconManager::getInstance();
	ThreadManager::getInstance()->Start();

	while (this->window.isOpen())
	{
		currentTime = clock.getElapsedTime();
		float deltaTime = currentTime.asSeconds() - previousTime.asSeconds();
		this->fps = floor(1.0f / deltaTime);
		processEvents();
		update(sf::seconds(1.0f / this->fps));
		render();

		previousTime = currentTime;


	}

	ThreadManager::getInstance()->isRunning = false;
}

Game* Game::getInstance()
{
    return sharedInstance;
}

RenderWindow* Game::getWindow()
{
	return &this->window;
}

float Game::getFPS()
{
	return this->fps;
}
