#include "Entity.h"

void Entity::SetIsAlive(bool SetAlive)
{
	IsAlive = SetAlive;
	SetAlive = true;
}

void Entity::SetPos(int EPosX, int EPosY)
{
	PosX = EPosX;
	PosY = EPosY;
}
