#include "Bullet.h"
#include "Simulation.h"

Bullet::Bullet()
{
	IsBullet = true;
}

void Bullet::Update(Visulisation& Viz, Simulation& Sim)
{
	if (IsAlive == true)
	{
		Viz.RenderClippedSprite("Bullet", PosX, PosY);
		PosY = PosY - 0.5 * Sim.GetDeltaTime();
	}

	if (PosY < 0)
		IsAlive = false;
	
}
