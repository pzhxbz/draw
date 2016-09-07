#include "stdafx.h"
#include "Container.h"


Container::Container()
{
}


Container::~Container()
{
}

void Container::add(Graph * data)
{
	if (num == 0)
	{
		head = new Data();
		head->data = data;
		num++;
	}
	else if (num == 1)
	{
		last = new Data();
		last->data = data;
		head->next = last;
		last->next = NULL;
		num++;
	}
	else
	{
		Data *p=new Data;
		p->data = data;
		last->next = p;
		last = p;
		num++;
	}
}
void Container::move(sf::Vector2f StartPoint)
{
	if (MoveFlag == NULL)
	{
		Data *p = head;
		for (; p != NULL; p = p->next)
		{
			if (p->data->isIn(StartPoint))
			{
				MoveFlag = p->data;
				break;
			}
		}
	}
	return;
}
void Container::EndMove(sf::Vector2f distance, bool isEnd)
{
	if (MoveFlag == NULL)
	{
		return;
	}
	MoveFlag->move(distance);
	if (isEnd)
	{
		MoveFlag = NULL;
	}
	return;
}
void Container::drawGraph()
{
	Data *p = head;
	for (int i = 0; i < num; i++)
	{
		p->data->draw();
		p = p->next;
	}
}
