#pragma once
#include "Painter.h"
#include <SFML\Graphics.hpp>
class Drager :
	public Painter
{
public:
	Drager();
	~Drager();
	void drawing(sf::Vector2i point);
	void paint() {};
	void ExitDraw(sf::Vector2i point);
	void drawGraph(sf::Vector2f *data) {};
private:
	bool isDrag = false;
	sf::Vector2f StartPoint, EndPoint;
};

