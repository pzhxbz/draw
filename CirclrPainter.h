#pragma once
#include<SFML\Graphics.hpp>
#include "Painter.h"
class CirclrPainter :
	public Painter
{
public:
	CirclrPainter();
	~CirclrPainter();
	void drawing(sf::Vector2i point);
	void paint();
	void ExitDraw(sf::Vector2i point);
	void drawGraph(sf::Vector2f *data);
private:
	bool isDrawing = false;
	sf::Vector2f Startpoint;
	sf::Vector2f EndPoint;
};

