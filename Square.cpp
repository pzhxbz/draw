#include "stdafx.h"
#include "Square.h"
#include "sfmlmath.h"
Square::Square(sf::Vector2f *data)
{
	point[0] = data[0];
	point[1] = data[1];
	point[2] = data[2];
	point[3] = data[3];
}

Square::Square()
{
}

Square::~Square()
{
}

void Square::draw()
{
	SquarePainter painter;
	painter.drawGraph(point);
}

bool Square::isIn(sf::Vector2f point)
{
	if (sfmlmath::isInCenterH(this->point[0], point, this->point[2])&&sfmlmath::isInCenterV(this->point[0], point, this->point[2]))
	{
		return true;
	}
	return false;
}

void Square::move(sf::Vector2f distance)
{
	for (int i = 0; i < 4; i++)
	{
		point[i] += distance;
	}
}
