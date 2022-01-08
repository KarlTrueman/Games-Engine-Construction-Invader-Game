#include "Entity.h"
#include "Sprite.h"
#include "Rectangle.h"
#include "Visulisation.h"


bool Entity::CheckCollision(Entity* One, Entity* Two)
{
	Visulisation player;
	Visulisation enemy;
	Rectangle OneSprite;
	Rectangle TwoSprite;

	OneSprite = player.GetRectangle(One->filename);
	TwoSprite = enemy.GetRectangle(Two->filename);

	OneSprite.Translate(One->PosX, One->PosY);
	TwoSprite.Translate(Two->PosX, Two->PosY);

	if (One->GetSide() != Two->GetSide())
	{
		if (One->IsAlive && Two->IsAlive)
		{
			if ((OneSprite.right < TwoSprite.left || OneSprite.left > TwoSprite.right) || (OneSprite.bottom < TwoSprite.top || OneSprite.top > TwoSprite.bottom))
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
