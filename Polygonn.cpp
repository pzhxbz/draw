#include "stdafx.h"
#include "Polygonn.h"
#include "PolygonnPainter.h"
#include "sfmlmath.h"
Polygonn::Polygonn()
{
}

Polygonn::Polygonn(sf::Vector2f * pointinfo,int pointNum)
{
	point = new sf::Vector2f[pointNum];
	this->pointnum = pointNum;
	for (int i = 0; i < pointNum; i++)
	{
		point[i] = pointinfo[i];
	}
}


Polygonn::~Polygonn()
{
}

void Polygonn::draw()
{
	PolygonnPainter painter;
	sf::Vector2f * data = new sf::Vector2f[pointnum + 1];
	data[0].x = data[0].y = pointnum;
	for (int i = 0; i < pointnum; i++)
	{
		data[i + 1] = point[i];
	}
	painter.drawGraph(data);
}

bool Polygonn::isIn(sf::Vector2f point)
{
	float left = 9999999, right = 0, high = 999999, low = 0;//把多边形变成一个正方形，取最边上点的坐标
	for (int i = 0; i < pointnum; i++)
	{
		if (this->point[i].x < left)
		{
			left = this->point[i].x;
		}
		if (this->point[i].x > right)
		{
			right = this->point[i].x;
		}
		if (this->point[i].y < high)
		{
			high = this->point[i].y;
		}
		if (this->point[i].y > low)
		{
			low = this->point[i].y;
		}
	}
	sf::Vector2f point1(left, high);
	sf::Vector2f point2(right, low);
	if(sfmlmath::isInCenterH(point1,point,point2)&& sfmlmath::isInCenterV(point1, point, point2))
	{
		return  true;
	}
	return false;
}

void Polygonn::move(sf::Vector2f distance)
{
	for (int i = 0; i < pointnum; i++)
	{
		point[i] += distance;
	}
}
