#pragma once
#include "Painter.h"
class PolygonnPainter :public Painter
{
public:
	PolygonnPainter();
	~PolygonnPainter();
	void drawing(sf::Vector2i point);
	void paint();
	void ExitDraw(sf::Vector2i point);
	void drawGraph(sf::Vector2f *data);
private:
	bool isDrawing = false;
	sf::Vector2f point[100];
	sf::Vector2f MovePoint;
	int PointNum = 0;
};

