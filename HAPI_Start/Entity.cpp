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

std::string Entity::GetSpriteName()
{
	return std::string();
}

bool Entity::CheckCollision(Visulisation& Viz, Entity& other)
{
	if (PosX + Viz.GetTextureWidth(this->GetSpriteName()) < other.PosX || PosX > other.PosX + Viz.GetTextureWidth(other.GetSpriteName()) || PosY + Viz.GetTextureHeight(this->GetSpriteName()) < other.PosY || PosY > other.PosY + Viz.GetTextureHeight(other.GetSpriteName()))
	{
		return false;
	}
	else
	{
		if (other.GetSpriteName() == "Bullet")
		{
			return true;
		}
	}
}

void Entity::Setup()
{
}
