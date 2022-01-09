#include "EnemyEntity.h"
#include "Visulisation.h"
#include "Simulation.h"

EnemyEntity::EnemyEntity(float EnemyX, float EnemyY)
{
	PosX = EnemyX;
	PosY = EnemyY;
}

void EnemyEntity::Update(Visulisation& Viz,Simulation& Sim)
{
	Viz.RenderClippedSprite("Rock", PosX, PosY);
	if (Toggle == false)
	{
		
		if (PosX < 1000)
		{
			PosX = PosX + 0.5f * Sim.GetDeltaTime();
		}
		else
		{
			PosY = PosY + 32;
			Toggle = true;
		}
	}
	else if (Toggle == true)
	{
		if (PosX > 0)
		{
			PosX = PosX - 0.5f * Sim.GetDeltaTime();
		}
		else
		{
			PosY = PosY + 32;
			Toggle = false;
		}
	}
}