#pragma once
#include <SFML\Graphics.hpp>
class sfmlmath
{
public:
	sfmlmath();
	~sfmlmath();
	static float point_distance(sf::Vector2f a, sf::Vector2f b);
	static sf::Vector2f centerPoint(sf::Vector2f a, sf::Vector2f b);
	static bool isInCenterH(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c);
	static bool isInCenterV(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c);
};

