#include "EnemyEntity.h"
#include "Visulisation.h"
#include "Simulation.h"

EnemyEntity::EnemyEntity()
{
	SpriteName = "Rock";
}

std::string EnemyEntity::GetSpriteName()
{
	return SpriteName;
}

void EnemyEntity::Setup()
{
	IsAlive = true;
	PosX = rand() % 1000 + 10;
	PosY = -100;
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