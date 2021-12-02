#pragma once
#include "Visulisation.h"
class Entity
{
public:
	Entity() = default;
	virtual ~Entity() = default;
	virtual void Update(Visulisation &Viz) = 0;
	int PosX = 50;
	int PosY = 50;

private:

};