#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>
class Graph
{
public:
	Graph(sf::Vector2f *data);
	Graph();
	virtual ~Graph();
	virtual void draw() = 0;
	virtual bool isIn(sf::Vector2f point)=0;
	virtual void move(sf::Vector2f distance) = 0;
};

