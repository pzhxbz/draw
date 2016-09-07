#include "stdafx.h"
#include "sfmlmath.h"


sfmlmath::sfmlmath()
{
}


sfmlmath::~sfmlmath()
{
}

float sfmlmath::point_distance(sf::Vector2f a, sf::Vector2f b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

sf::Vector2f sfmlmath::centerPoint(sf::Vector2f a, sf::Vector2f b)
{
	sf::Vector2f center;
	center.x = (a.x + b.x) / 2;
	center.y = (a.y + b.y) / 2;
	return center;
}

bool sfmlmath::isInCenterH(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c)
{
	if (b.x >= a.x&&b.x <= c.x)
	{
		return true;
	}
	if (b.x <= a.x&&b.x >= c.x)
	{
		return true;
	}
	return false;
}

bool sfmlmath::isInCenterV(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c)
{
	if (b.y >= a.y&&b.y <= c.y)
	{
		return true;
	}
	if (b.y <= a.y&&b.y >= c.y)
	{
		return true;
	}
	return false;
}
