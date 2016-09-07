#include "stdafx.h"
#include "SquarePainter.h"
#include "Square.h"

SquarePainter::SquarePainter()
{

}
SquarePainter::~SquarePainter()
{

}
void SquarePainter::drawing(sf::Vector2i point)
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

void SquarePainter::paint()
{
	sf::Vector2f point1, point3;
	point1.x = Startpoint.x;
	point1.y = EndPoint.y;
	point3.y = Startpoint.y;
	point3.x = EndPoint.x;
	sf::VertexArray square(sf::LinesStrip, 5);
		square[0].position = Startpoint;
		square[1].position = point1;
		square[2].position = EndPoint;
		square[3].position = point3;
		square[4].position = Startpoint;
	Painter::window.draw(square);
}

void SquarePainter::ExitDraw(sf::Vector2i point)
{
	if (isDrawing)
	{
		isDrawing = false;
		sf::Vector2f *data=new sf::Vector2f[4];
		sf::Vector2f point1, point3;
		point1.x = Startpoint.x;
		point1.y = EndPoint.y;
		point3.y = Startpoint.y;
		point3.x = EndPoint.x;
		data[0] = Startpoint;
		data[1] = point1;
		data[2] = EndPoint;
		data[3] = point3;
		Graph *square = new Square(data);
		Painter::container.add(square);
	}
}
void SquarePainter::drawGraph(sf::Vector2f *data)
{
	sf::VertexArray square(sf::LinesStrip, 5);
	square[0].position = data[0];
	square[1].position = data[1];
	square[2].position = data[2];
	square[3].position = data[3];
	square[4].position = data[0];
	Painter::window.draw(square);
}

