#include "PlayerEntity.h"
#include "Bullet.h"
#include "Simulation.h"

PlayerEntity::PlayerEntity()
{
	SpriteName = "Player";
}

void PlayerEntity::Update(Visulisation& Viz, Simulation& Sim)
{
	Normal = Sim.GetDeltaTime();
	Viz.RenderClippedSprite("Player", PosX, PosY);


	//Input
	
	//Keyboard
	//UP LEFT
	if (KeyData.scanCode['W'] && KeyData.scanCode['A'])
	{
		PosY -= 0.5 * Normal;
		PosX -= 0.5 * Normal;
	}
	//UP RIGHT
	else if (KeyData.scanCode['W'] && KeyData.scanCode['D'])
	{
		PosY -= 0.5 * Normal;
		PosX += 0.5 * Normal;
	}
	//DOWN LEFT
	else if (KeyData.scanCode['S'] && KeyData.scanCode['A'])
	{
		PosY += 0.5 * Normal;
		PosX -= 0.5 * Normal;
	}
	//DOWN RIGHT
	else if (KeyData.scanCode['S'] && KeyData.scanCode['D'])
	{
		PosY += 0.5 * Normal;
		PosX += 0.5 * Normal;
	}
	//UP
	else if (KeyData.scanCode['W'])
	{
		PosY-= 0.5 * Normal;
	}
	//DOWN
	else if (KeyData.scanCode['S'])
	{
		PosY+= 0.5 * Normal;
	}
	//LEFT
	if (KeyData.scanCode['A'])
	{
		PosX-= 0.5 * Normal;
	}
	//RIGHT
	else if (KeyData.scanCode['D'])
	{
		PosX+= 0.5 * Normal;
	}
	if (KeyData.scanCode[HK_SPACE]||data.analogueButtons[HK_ANALOGUE_RIGHT_TRIGGER])
	{
		Sim.SpawnBullet(PosX, PosY);
	}


	//Controller
	{
		//PosX += data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] / 10000;
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

std::string PlayerEntity::GetSpriteName()
{
	return SpriteName;
}

void PlayerEntity::Setup()
{
	PosX = 500;
	PosY = 600;
}
