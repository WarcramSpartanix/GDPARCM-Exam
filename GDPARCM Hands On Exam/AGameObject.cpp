#include "AGameObject.h"
#include "Utils.h"

AGameObject::AGameObject(String name)
{
	this->name = name;
}

AGameObject::~AGameObject() {
	delete this->sprite;
	delete this->texture;
}

AGameObject::String AGameObject::getName() {
	return this->name;
}

void AGameObject::draw(sf::RenderWindow* targetWindow) {
	if (this->sprite != NULL) {
		this->sprite->setPosition(this->posX, this->posY);
		this->sprite->setScale(this->scaleX, this->scaleY);
		targetWindow->draw(*this->sprite);
	}
}

//must be called after being registered to the game object manager or one of the parent game objects
void AGameObject::setPosition(float x, float y)
{
	this->posX = x;
	this->posY = y;

	if(this->sprite != nullptr)
	{
		this->sprite->setPosition(this->posX, this->posY);
	}
}

void AGameObject::setScale(float x, float y)
{
	this->scaleX = x;
	this->scaleY = y;

	if (this->sprite != nullptr)
	{
		this->sprite->setScale(this->scaleX, this->scaleY);
	}
}

sf::Vector2f AGameObject::getPosition()
{
	return this->sprite->getPosition();
}

sf::Vector2f AGameObject::getScale()
{
	return this->sprite->getScale();
}

void AGameObject::setTexture(sf::Texture* newTexture)
{
	this->sprite->setTexture(*newTexture);
}

void AGameObject::scaleTo(float width, float height)
{
	FloatRect bounds = getLocalBounds();
	Vector2f scaleTo = Utils::ScaleTo(Vector2f(bounds.width, bounds.height), Vector2f(width, height));
	this->setScale(scaleTo.x, scaleTo.y);
}

sf::FloatRect AGameObject::getLocalBounds()
{
	return this->sprite->getLocalBounds();
}
