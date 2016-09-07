#include "stdafx.h"
#include "Painter.h"
#include "CirclrPainter.h"
#include "Circle.h"
#include "sfmlmath.h"
#include <cmath>
#define PI acos(-1)
CirclrPainter::CirclrPainter()
{
}

CirclrPainter::~CirclrPainter()
{
}

void CirclrPainter::drawing(sf::Vector2i point)
{
	if (!isDrawing)
	{
		Startpoint.x = point.x;
		Startpoint.y = point.y;
		isDrawing = true;
		return;
	}
	EndPoint.x = point.x;
	EndPoint.y = point.y;
	paint();
}

void CirclrPainter::paint()
{
	sf::Vector2f circle_center=sfmlmath::centerPoint(Startpoint, EndPoint);
	float r = sfmlmath::point_distance(Startpoint, EndPoint) / 2;
	sf::VertexArray circle(sf::LinesStrip, 37);
	for (int i = 0; i <= 360; i += 10)
	{
		circle[i / 10].position.x = circle_center.x + r*cos((double)i / 180 * PI);
		circle[i / 10].position.y = circle_center.y + r*sin((double)i / 180 * PI);
	}
	Painter::window.draw(circle);
}

void CirclrPainter::ExitDraw(sf::Vector2i point)
{
	if (isDrawing)
	{
		isDrawing = false;
		sf::Vector2f circle_center = sfmlmath::centerPoint(Startpoint, EndPoint);
		float r = sfmlmath::point_distance(Startpoint, EndPoint) / 2;
		Graph *circle = new Circle(circle_center,r);
		Painter::container.add(circle);
	}
}

void CirclrPainter::drawGraph(sf::Vector2f * data)
{
	Startpoint = data[0];
	EndPoint = data[1];
	paint();
}
