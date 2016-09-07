#include "stdafx.h"
#include "Drager.h"
#include "Painter.h"

Drager::Drager()
{
}


Drager::~Drager()
{
}

void Drager::drawing(sf::Vector2i point)
{
	if (!isDrag)
	{
		StartPoint.x = point.x;
		StartPoint.y = point.y;
		Painter::container.move(StartPoint);
		isDrag = true;
		return;
	}
	StartPoint = EndPoint;
	EndPoint.x = point.x;
	EndPoint.y = point.y;
	Painter::container.EndMove(EndPoint-StartPoint, false);
}

void Drager::ExitDraw(sf::Vector2i point)
{
	StartPoint = EndPoint;
	EndPoint.x = point.x;
	EndPoint.y = point.y;
	isDrag = false;
	Painter::container.EndMove(EndPoint - StartPoint, true);
}

