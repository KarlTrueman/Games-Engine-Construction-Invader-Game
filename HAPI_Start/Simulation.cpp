#include "Simulation.h"
#include "Visulisation.h"

void Simulation::Run()
{
	Visulisation Viz;

	Viz.Initialise();

	//Create Sprites
	if (!Viz.CreateSprite("Alpha", "data\\alphaThing.tga"))
		return;
	if (!Viz.CreateSprite("Background", "data\\background.tga"))
		return;
	if (!Viz.CreateSprite("Player", "data\\playerSprite.tga"))
		return;

	float PosX = 100;
	float PosY = 100;

	const HAPI_TKeyboardData& KeyData = HAPI.GetKeyboardData();
	while (HAPI.Update())
	{
		Viz.ClearScreen();

		Viz.RenderSprite("Background", 0, 0);
		Viz.RenderSprite("Alpha", PosX, PosY);

		//Testing spawning multiple of same sprite in random locations
		for (int i = 0; i < 25; i++)
			Viz.RenderSprite("Alpha", rand() % 1280, rand() % 768);

		//Input
		float Normal = 1 / sqrt(2);

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

		//None working edge of screen

		//PosX = std::max(0, PosX);
		//PosY = std::max(0, PosY);
		//PosX = std::min((int)(width - tw), PosX);
		//PosX = std::min((int)(height - th), PosY);


		//Controller
		const HAPI_TControllerData& GetControllerData(unsigned int controller);
		const HAPI_TControllerData& data = HAPI.GetControllerData(0);

		PosX += data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] / 10000;
		PosY -= data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] / 10000;
	}
}
