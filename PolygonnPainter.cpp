#include "stdafx.h"
#include "PolygonnPainter.h"
#include "Polygonn.h"
#include <cmath>

PolygonnPainter::PolygonnPainter()
{
}


PolygonnPainter::~PolygonnPainter()
{
}

void PolygonnPainter::drawing(sf::Vector2i point)
{
	MovePoint.x = point.x;
	MovePoint.y = point.y;
	isDrawing = true;
	paint();
}

void PolygonnPainter::paint()
{
	if (PointNum == 0)
	{
		return;
	}
	sf::VertexArray Polygonn(sf::LinesStrip, PointNum);
	for (int i = 0; i < PointNum; i++)
	{
		Polygonn[i].position = point[i];
	}
	Painter::window.draw(Polygonn);
}

void PolygonnPainter::ExitDraw(sf::Vector2i Lastpoint)
{
	paint();
	if (!isDrawing)
	{
		return;
	}
	if (PointNum == 0)
	{
		point[0] = MovePoint;
		PointNum++;
		isDrawing = false;
		return;
	}
	float startPoint_x = point[0].x;
	float startPoint_y = point[0].y;
	float endPoint_x = MovePoint.x;
	float endPoint_y = MovePoint.y;
	point[PointNum] = MovePoint;
	float distance = sqrt((endPoint_x - startPoint_x)*(endPoint_x - startPoint_x) + (endPoint_y - startPoint_y)*(endPoint_y - startPoint_y));
	if (distance <= 10)
	{
		Graph* graph = new Polygonn(point,PointNum);
		Painter::container.add(graph);
		PointNum = 0;
	}
	else{
		PointNum++;
	}
	isDrawing = false;
	paint();
}

void PolygonnPainter::drawGraph(sf::Vector2f * data)
{
	int num = data->x;
	sf::VertexArray Polygonn(sf::LinesStrip, num+1);
	for (int i = 0; i <num; i++)
	{
		Polygonn[i].position = data[1+i];
	}
	Polygonn[num] = data[1];
	Painter::window.draw(Polygonn);
}
