#include "Simulation.h"
#include "Visulisation.h"
#include "PlayerEntity.h"
#include "EnemyEntity.h"
#include "Rectangle.h"
#include "Bullet.h"


int BGy = 0;
int BG2y = -768;
int FireDelay = 60; // tick between bullets can be fired
int FireDelayTick = FireDelay; // current tick of when a bullet may be fired. defaulted to the FireDelay so there is no delay for the first bullet when launching the game

void Simulation::LoadLevel()
{
	//Create Sprites
	if (!Viz.CreateSprite("Alpha", "data\\alphaThing.tga"))
		return;
	if (!Viz.CreateSprite("Background", "data\\background.tga"))
		return;
	if (!Viz.CreateSprite("Player", "data\\playerSprite.tga"))
		return;
	if (!Viz.CreateSprite("Bullet", "data\\Bullet.png"))
		return;
	if (!Viz.CreateSprite("Stars", "data\\stars.jpg"))
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

	int StartOfBullets = m_entityVector.size() + 1;
	

	int TotalBullets = 200;
	for (int x = 0; x <= TotalBullets; x++)
	{
		Bullet* newBullet = new Bullet;
		m_entityVector.push_back(newBullet);
	}
	int EndOfBullets = m_entityVector.size();
}

void Simulation::SpawnBullet(int PlayerX, int PlayerY)
{
	for (int z = 0; z < m_entityVector.size(); z++)
	{
		if (m_entityVector[z]->GetIsAlive() == false && FireDelayTick > FireDelay )
		{
		m_entityVector[z]->SetIsAlive(true);
		m_entityVector[z]->SetPos(PlayerX + 28, PlayerY);
		m_entityVector[z]->Update(Viz, *this);
		FireDelayTick = 0;
		break;
		}
	}
}



void Simulation::Run()
{
	Viz.Initialise();
	LoadLevel();

	const HAPI_TKeyboardData& KeyData = HAPI.GetKeyboardData();
	while (HAPI.Update())
	{
		Viz.ClearScreen();

		Viz.RenderClippedSprite("Stars", 0, BGy);
		Viz.RenderClippedSprite("Stars", 0, BG2y);

		BGy = BGy + 1;
		BG2y = BG2y + 1;
		if (BGy >= 768)
			BGy = 0;
		if (BG2y >= 0)
			BG2y = -768;

		for (Entity* p : m_entityVector)
			p->Update(Viz,*this);
		FireDelayTick++;
	}

}

Simulation::~Simulation()
{
	for (auto& p : m_entityVector)
		delete p;
}


