#include "Simulation.h"
#include "Visulisation.h"
#include "PlayerEntity.h"
#include "EnemyEntity.h"
#include "Rectangle.h"


void Simulation::LoadLevel()
{
	//Create Sprites
	if (!Viz.CreateSprite("Alpha", "data\\alphaThing.tga"))
		return;
	if (!Viz.CreateSprite("Background", "data\\background.tga"))
		return;
	if (!Viz.CreateSprite("Player", "data\\Sprite.png"))
		return;

	PlayerEntity* newPlayer = new PlayerEntity;
	m_entityVector.push_back(newPlayer);

	EnemyEntity* newEnemy = new EnemyEntity(100, 100);
	m_entityVector.push_back(newEnemy);

	EnemyEntity* newEnemy1 = new EnemyEntity(200, 200);
	m_entityVector.push_back(newEnemy1);

	EnemyEntity* newEnemy2 = new EnemyEntity(300, 300);
	m_entityVector.push_back(newEnemy2);

	EnemyEntity* newEnemy3 = new EnemyEntity(400, 400);
	m_entityVector.push_back(newEnemy3);


}

void Simulation::Run()
{
	Viz.Initialise();
	LoadLevel();
	float PosX = 100;
	float PosY = 100;

	const HAPI_TKeyboardData& KeyData = HAPI.GetKeyboardData();
	while (HAPI.Update())
	{
		Viz.ClearScreen();

		Viz.RenderClippedSprite("Background", 0, 0);

		for (Entity* p : m_entityVector)
			p->Update(Viz);
	}

}
