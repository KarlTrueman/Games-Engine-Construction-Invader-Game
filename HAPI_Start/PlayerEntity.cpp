#include "PlayerEntity.h"
#include "Bullet.h"
#include "Simulation.h"



void PlayerEntity::Update(Visulisation& Viz, Simulation& Sim)
{

	Viz.RenderClippedSprite("Player", PosX, PosY);

	//Input
	
	//Keyboard

	//UP LEFT
	if (KeyData.scanCode['W'] && KeyData.scanCode['A'])
	{
		PosY -= Normal;
		PosX -= Normal;
	}
	//UP RIGHT
	else if (KeyData.scanCode['W'] && KeyData.scanCode['D'])
	{
		PosY -= Normal;
		PosX += Normal;
	}
	//DOWN LEFT
	else if (KeyData.scanCode['S'] && KeyData.scanCode['A'])
	{
		PosY += Normal;
		PosX -= Normal;
	}
	//DOWN RIGHT
	else if (KeyData.scanCode['S'] && KeyData.scanCode['D'])
	{
		PosY += Normal;
		PosX += Normal;
	}
	//UP
	else if (KeyData.scanCode['W'])
	{
		PosY--;
	}
	//DOWN
	else if (KeyData.scanCode['S'])
	{
		PosY++;
	}
	//LEFT
	else if (KeyData.scanCode['A'])
	{
		PosX--;
	}
	//RIGHT
	else if (KeyData.scanCode['D'])
	{
		PosX++;
	}
	if (KeyData.scanCode[HK_SPACE])
	{
		Sim.SpawnBullet(PosX, PosY);
		//Sound
		HAPI.LoadSound("data\\laser.mp3");
		HAPI.PlaySound("data\\laser.mp3");
		
	}

	//None working edge of screen

	//PosX = std::max(0, PosX);
	//PosY = std::max(0, PosY);
	//PosX = std::min((int)(width - tw), PosX);
	//PosX = std::min((int)(height - th), PosY);


	//Controller
	{
		PosX += data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] / 10000;
		PosY -= data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] / 10000;

		//Rumble centre screen
		if (PosX > 200 && PosX < 500 && PosY > 200 && PosY < 500)
		{
			HAPI.SetControllerRumble(0, 5000, 5000);
		}
		else
			HAPI.SetControllerRumble(0, 0, 0);
	}

}
