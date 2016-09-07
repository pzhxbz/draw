#pragma once
#include "stdafx.h"
#include<SFML\Graphics.hpp>
#include "Graph.h"
#include "Container.h"
class Painter
{
public:
	static sf::RenderWindow window;
	static Container container;
	Painter();
	virtual ~Painter();
	virtual void drawing(sf::Vector2i point)=0;
	virtual void paint() = 0;
	virtual void ExitDraw(sf::Vector2i point)=0;
	virtual void drawGraph(sf::Vector2f *data)=0;
private:
	bool isDrawing = false;
};

