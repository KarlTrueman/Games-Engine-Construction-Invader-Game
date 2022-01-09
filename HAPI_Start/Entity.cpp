#include "Entity.h"
#include "Sprite.h"
#include "Rectangle.h"
#include "Visulisation.h"


bool Entity::CheckCollision(Visulisation& Viz, Entity* One, Entity* Two)
{

	if (One->GetSide() != Two->GetSide())
	{
		if (One->IsAlive && Two->IsAlive)
		{
			if (One->PosX + Viz.GetTextureWidth(One->GetSpriteName()) < Two->PosX || One->PosX > Two->PosX + Viz.GetTextureWidth(Two->GetSpriteName()) || One->PosY + Viz.GetTextureHeght(One->GetSpriteName()) < Two->PosY|| One->PosY > Two->PosY + Viz.GetTextureHeght(Two->GetSpriteName()))
			{
				std::cout << "Test" << std::endl;
				return false;
			}
			else
			{
				std::cout << "collision" << std::endl;
				//One->health -= 10;
				//Two->health -= 10;

				return true;
			}
		}

	}
	else if (One->GetSide() == Two->GetSide())
	{
		return false;
	}
	else
		return false;
}

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
	return m_spriteName;
}
