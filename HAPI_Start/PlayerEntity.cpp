#include "PlayerEntity.h"
#include "Bullet.h"
#include "Simulation.h"

PlayerEntity::PlayerEntity()
{
	SpriteName = "Player";
}

void PlayerEntity::Update(Visulisation& Viz, Simulation& Sim)
{
	if (Health <= 0)
	{
		IsAlive = false;
		Sim.RestartGame();
	}

	if (Health > 100)
		Health = 100;
	if (Score <= 0)
		Score = 0;


	if (IsAlive == true)
	{
		Viz.RenderClippedSprite("Player", PosX, PosY);



		//Input

		//LEFT
		if (KeyData.scanCode['A'])
		{
			PosX -= 0.5f * float(Sim.GetDeltaTime());
		}
		//RIGHT
		else if (KeyData.scanCode['D'])
		{
			PosX += 0.5f * float(Sim.GetDeltaTime());
		}
		if (KeyData.scanCode[HK_SPACE] || data.analogueButtons[HK_ANALOGUE_RIGHT_TRIGGER])
		{
			Sim.SpawnBullet(PosX, PosY);
		}
		if (KeyData.scanCode['R'] || data.digitalButtons[HK_DIGITAL_Y])
		{
			Sim.RestartGame();
		}
		if (KeyData.scanCode[HK_RIGHT])
		{
			AddHealth(1);
		}
		if (KeyData.scanCode[HK_LEFT])
		{
			TakeHealth(1);
		}
		if (KeyData.scanCode[HK_UP])
		{
			AddScore(1);
		}
		if (KeyData.scanCode[HK_DOWN])
		{
			TakeScore(1);
		}
		//Controller - Untested since adding delta time as no controller available to test
		{
			PosY -= data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] * float(Sim.GetDeltaTime());
		}
	}

	// unused Keyboard (Left for debugging)
	//UP LEFT
	//if (KeyData.scanCode['W'] && KeyData.scanCode['A'])
	//{
	//	PosY -= 0.5 * float (Sim.GetDeltaTime());
	//	PosX -= 0.5 * float (Sim.GetDeltaTime());
	//}
	////UP RIGHT
	//else if (KeyData.scanCode['W'] && KeyData.scanCode['D'])
	//{
	//	PosY -= 0.5 * float (Sim.GetDeltaTime());
	//	PosX += 0.5 * float (Sim.GetDeltaTime());
	//}
	////DOWN LEFT
	//else if (KeyData.scanCode['S'] && KeyData.scanCode['A'])
	//{
	//	PosY += 0.5 * float (Sim.GetDeltaTime());
	//	PosX -= 0.5 * float (Sim.GetDeltaTime());
	//}
	////DOWN RIGHT
	//else if (KeyData.scanCode['S'] && KeyData.scanCode['D'])
	//{
	//	PosY += 0.5 * float (Sim.GetDeltaTime());
	//	PosX += 0.5 * float (Sim.GetDeltaTime());
	//}
	////UP
	//else if (KeyData.scanCode['W'])
	//{
	//	PosY-= 0.5 * float (Sim.GetDeltaTime());
	//}
	////DOWN
	//else if (KeyData.scanCode['S'])
	//{
	//	PosY+= 0.5 * float (Sim.GetDeltaTime());
	//}
	
}

std::string PlayerEntity::GetSpriteName()
{
	return SpriteName;
}

void PlayerEntity::Setup()
{
	IsAlive = true;
	PosX = 500;
	PosY = 600;
}
