#pragma once
#include "stdafx.h"
#include "Graph.h"
#include "SquarePainter.h"
#include <SFML\Graphics.hpp>
class Square:public Graph
{
public:
	Square(sf::Vector2f *data);
	Square();
	virtual ~Square();
	void draw();
	bool isIn(sf::Vector2f point);
	void move(sf::Vector2f distance);
private:
	sf::Vector2f point[4];
};

