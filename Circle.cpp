#include "stdafx.h"
#include "Circle.h"
#include "CirclrPainter.h"
#include "sfmlmath.h"
Circle::Circle(sf::Vector2f circle_center, float r)
{
	this->circle_center = circle_center;
	this->r = r;
}

Circle::Circle()
{
}


Circle::~Circle()
{
}

void Circle::draw()
{
	sf::Vector2f data[2];
	data[1] = data[0] = circle_center;
	data[0].x += r;
	data[1].x -= r;
	CirclrPainter painter;
	painter.drawGraph(data);
}

bool Circle::isIn(sf::Vector2f point)
{
	if (sfmlmath::point_distance(point, circle_center) <= r)
	{
		return true;
	}
	return false;
}

void Circle::move(sf::Vector2f distance)
{
	circle_center += distance;
}
