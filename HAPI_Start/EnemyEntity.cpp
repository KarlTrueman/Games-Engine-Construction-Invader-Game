#include "EnemyEntity.h"
#include "Visulisation.h"
#include "Simulation.h"

EnemyEntity::EnemyEntity(std::string Type)
{
	SpriteName = Type;
}

std::string EnemyEntity::GetSpriteName()
{
	return SpriteName;
}

void EnemyEntity::Setup()
{
	IsAlive = true;
	PosX = float (rand() % 1000 + 10.0);
	PosY = -100;
}

void EnemyEntity::SetupBoss()
{
	IsAlive = true;
	IsBoss = true;
	PosX = 500;
	PosY = 200;
}

void EnemyEntity::Update(Visulisation& Viz,Simulation& Sim)
{
	Viz.RenderClippedSprite(SpriteName, PosX, PosY);
	if (IsBoss == false)
	{
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
	if(IsBoss == true)
	{
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
				PosY = PosY - 32;
				Toggle = false;
			}
		}
	}
}