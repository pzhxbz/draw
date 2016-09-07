#pragma once
#include "Graph.h"
#include <SFML\Graphics.hpp>
class Circle :
	public Graph
{
public:
	Circle(sf::Vector2f circle_center,float r);
	Circle();
	~Circle();
	void draw();
	bool isIn(sf::Vector2f point);
	void move(sf::Vector2f distance);
private:
	sf::Vector2f circle_center;
	float r;
};

