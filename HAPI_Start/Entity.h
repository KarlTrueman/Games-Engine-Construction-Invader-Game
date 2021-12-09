#pragma once
#include "Visulisation.h"
class Entity
{
public:

	Entity() = default;
	virtual ~Entity() = default;
	virtual void Update(Visulisation &Viz) = 0;
	float PosX = 50;
	float PosY = 50;


private:

};