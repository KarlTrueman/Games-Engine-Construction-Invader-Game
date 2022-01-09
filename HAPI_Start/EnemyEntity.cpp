#include "EnemyEntity.h"
#include "Visulisation.h"
#include "Simulation.h"

void EnemyEntity::Update(Visulisation& Viz,Simulation& Sim)
{;
	Viz.RenderClippedSprite("Rock", PosX, PosY);
	if (Toggle == false)
	{
		
		if (PosX < 1000)
		{
			PosX = PosX + 0.5 * Sim.GetDeltaTime();
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
			PosX = PosX - 0.5 * Sim.GetDeltaTime();
		}
		else
		{
			PosY = PosY + 32;
			Toggle = false;
		}
	}
}

EnemyEntity::EnemyEntity()
{
	m_spriteName = "Rock";
}

void EnemyEntity::setup()
{
	IsAlive = true;
	PosX = rand() % 1000 + 10;
	PosY = -100;
}
