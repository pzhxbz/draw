#pragma once
#include "Graph.h"
#include <SFML\Graphics.hpp>
struct Data
{
	Graph *data;
	Data *next;
};
class Container
{
public:
	Container();
	~Container();
	void add(Graph* data);
	void save() {};
	void move(sf::Vector2f StartPoint) ;
	void EndMove(sf::Vector2f EndPoint,bool isEnd);
	void drawGraph();
private:
	Data *head=NULL;
	Data *last=NULL;
	Graph *MoveFlag=NULL;
	int num = 0;
};

