#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include "Painter.h"
#include "SquarePainter.h"
#include "PolygonnPainter.h"
#include "CirclrPainter.h"
#include "Container.h"
#include "Drager.h"
sf::RenderWindow Painter::window(sf::VideoMode(1200, 800), "SFML works!");
Container Painter::container;
Painter *draw=new PolygonnPainter();
void drawing();
void modechoose();
int main()
{
	Painter::window.setFramerateLimit(60);
	while (Painter::window.isOpen())
	{
		Painter::window.clear();
		sf::Event event;
		while (Painter::window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Painter::window.close();
		}
		Painter::container.drawGraph();
		modechoose();
		drawing();
		Painter::window.display();
	}
	return 0;
}
void modechoose()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
	{
		delete(draw);
		draw = NULL;
		draw = new SquarePainter();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))
	{
		delete(draw);
		draw = NULL;
		draw = new PolygonnPainter();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
	{
		delete(draw);
		draw = NULL;
		draw = new CirclrPainter();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
	{
		delete(draw);
		draw = NULL;
		draw = new Drager();
	}
	return;
}
void drawing()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		draw->drawing(sf::Mouse::getPosition(Painter::window));
	}
	else
	{
		draw->ExitDraw(sf::Mouse::getPosition(Painter::window));
	}
	return;
}