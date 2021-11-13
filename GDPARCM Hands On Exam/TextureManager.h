#pragma once
#include <unordered_map>
#include "SFML/Graphics.hpp"
#include <mutex>

using namespace std;
using namespace sf;

class TextureManager
{
public:
	typedef std::vector<sf::Texture*> TextureList;
	typedef std::unordered_map<string, TextureList> HashTable;
	
public:
	static TextureManager* getInstance();

	void instantiateAsTexture(String path, String assetName, bool isStreaming);
	Texture* getFromTextureMap(const string assetName, int frameIndex);
private:
	const string PRELOAD_PATH = "Textures/";

private:
	TextureManager();
	~TextureManager();
	TextureManager(TextureManager const&) {};             // copy constructor is private
	TextureManager& operator=(TextureManager const&) {};  // assignment operator is private
	static TextureManager* sharedInstance;
	

	void initializePreLoad();
	void loadPreLoad();

	HashTable textureMap;
	TextureList baseTextureList;
	TextureList streamTextureList;

	vector<std::string> preload;


	std::mutex mtx;
};