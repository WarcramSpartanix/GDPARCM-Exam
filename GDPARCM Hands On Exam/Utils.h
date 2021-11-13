#pragma once
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Utils
{
public:
	static Vector2f ScaleTo(Vector2f currentSize, Vector2f preferredSize)
	{
		float x = preferredSize.x / currentSize.x;
		float y = preferredSize.y / currentSize.y;

		return Vector2f(x, y);
	}
	
	static bool Contains(Vector2f position, Vector2f size, Vector2f pointPosition)
	{
		if (pointPosition.x > position.x && pointPosition.x < position.x + size.x)
		{
			if (pointPosition.y > position.y && pointPosition.y < position.y + size.y)
				return true;
		}
		return false;
	}
};