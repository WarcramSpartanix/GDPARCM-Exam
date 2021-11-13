#include <fstream>
#include <iostream>
#include <filesystem>
#include "TextureManager.h"
#include "StringUtils.h"

//a singleton class
TextureManager* TextureManager::sharedInstance = NULL;


TextureManager* TextureManager::getInstance() {
	if (sharedInstance == NULL) {
		//initialize
		sharedInstance = new TextureManager();
	}
	
	return sharedInstance;
}

TextureManager::TextureManager()
{
	this->initializePreLoad();
	this->loadPreLoad();
}

TextureManager::~TextureManager()
{
}

void TextureManager::initializePreLoad()
{
	for (int i = 0; i < 20; i++)
	{
		this->preload.push_back(PRELOAD_PATH + "tile" + std::to_string(i) + ".png");
	}
	this->preload.push_back(PRELOAD_PATH + "Searcher.png");
	this->preload.push_back(PRELOAD_PATH + "Deleter.png");
	this->preload.push_back(PRELOAD_PATH + "Inserter.png");
}

void TextureManager::loadPreLoad()
{
	for (int i = 0; i < this->preload.size(); i++)
	{
		std::vector<string> tokens = StringUtils::split(preload[i], '/');
		string assetName = StringUtils::split(tokens[tokens.size() - 1], '.')[0];
		instantiateAsTexture(this->preload[i], assetName, false);
		//cout << "Loading at Path " << this->preload[i] << endl;
	}
}

Texture* TextureManager::getFromTextureMap(const string assetName, int frameIndex)
{
	if (!this->textureMap[assetName].empty()) {
		return this->textureMap[assetName][frameIndex];
	}
	else {
		std::cout << "[TextureManager] No texture found for " << assetName << std::endl;
		return NULL;
	}
}


void TextureManager::instantiateAsTexture(String path, String assetName, bool isStreaming)
{
	sf::Texture* texture = new sf::Texture();
	texture->loadFromFile(path);
	this->textureMap[assetName].push_back(texture);

	if (isStreaming)
	{
		this->streamTextureList.push_back(texture);
	}
	else
	{
		this->baseTextureList.push_back(texture);
	}

}

