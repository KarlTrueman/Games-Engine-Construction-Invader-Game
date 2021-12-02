#include "EnemyEntity.h"
#include "Visulisation.h"

EnemyEntity::EnemyEntity(int EnemyX, int EnemyY)
{
	EposX = EnemyX;
	EposY = EnemyY;
}

void EnemyEntity::Update(Visulisation& Viz)
{

	Viz.RenderClippedSprite("Alpha", EposX, EposY);

}