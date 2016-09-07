#pragma once
#include "Graph.h"
class Polygonn :public Graph
{
public:
	Polygonn();
	Polygonn(sf::Vector2f *pointinfo,int pointNum);
	Polygonn(sf::Vector2f *pointinfo) {};
	~Polygonn();
	void draw();
	bool isIn(sf::Vector2f point);
	void move(sf::Vector2f distance);
private:
	sf::Vector2f *point;
	int pointnum;
};

