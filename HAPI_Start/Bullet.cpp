#include "Bullet.h"
#include "Simulation.h"
Bullet::Bullet()
{
	m_spriteName = "Bullet";
}
void Bullet::Update(Visulisation& Viz, Simulation& Sim)
{
	IsBullet = true;
	if (IsAlive == true)
	{
		Viz.RenderClippedSprite("Bullet", PosX, PosY);
		PosY = PosY - 0.5 * Sim.GetDeltaTime();
	}

	if (PosY < 0)
		IsAlive = false;
	
}

void Bullet::setup()
{
}
