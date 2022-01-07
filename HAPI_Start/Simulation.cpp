#include "Simulation.h"
#include "Visulisation.h"
#include "PlayerEntity.h"
#include "EnemyEntity.h"
#include "Rectangle.h"
#include "Bullet.h"
#include <time.h>

float volume = 0.1;
void Simulation::LoadLevel()
{

	//HAPI.PlaySound("Data\\macky.wav", volume);
	//Create Sprites
	if (!Viz.CreateSprite("Background", "data\\background.tga"))
		return;
	if (!Viz.CreateSprite("Player", "data\\playerSprite.tga"))
		return;
	if (!Viz.CreateSprite("Bullet", "data\\Bullet.png"))
		return;
	if (!Viz.CreateSprite("Rock", "data\\Rock.png"))
		return;
	if (!Viz.CreateSprite("Stars", "data\\stars.jpg"))
		return;
	//Create Player 1 Entity
	PlayerEntity* newPlayer = new PlayerEntity("Player");
	m_entityVector.push_back(newPlayer);
	newPlayer->setup();
	
	StartOfBullets = m_entityVector.size() + 1;
	//Create all bullets
	int TotalBullets = 25;
	for (int x = 0; x <= TotalBullets; x++)
	{
		Bullet* newBullet = new Bullet("Bullet");
		m_entityVector.push_back(newBullet);
	}
	int EndOfBullets = m_entityVector.size();

	//Create all enemies
	int TotalEnemies = 5;
	for (int x = 0; x <= TotalEnemies; x++)
	{
		EnemyEntity* newEnemy = new EnemyEntity("Rock");
		m_entityVector.push_back(newEnemy);
		newEnemy->setup();
	}

}

float FireDelayTick = 120;

void Simulation::SpawnBullet(int PlayerX, int PlayerY)
{
	for (int z = StartOfBullets; z < m_entityVector.size(); z++)
	{
		if (m_entityVector[z]->GetIsAlive() == false && m_entityVector[z]->GetIsBullet() == true && FireDelayTick >= 50 )
		{
		m_entityVector[z]->SetIsAlive(true);
		m_entityVector[z]->SetPos(PlayerX + 28, PlayerY);
		m_entityVector[z]->Update(Viz, *this);
		HAPI.PlaySound("Data\\laser.wav", volume);
		FireDelayTick = 0;
		//break;
		
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
		//DeltaTime
		float time = clock();
		DeltaTime = time - OldTime;
		OldTime = time;
		FireDelayTick += (1 * DeltaTime);

		Viz.ClearScreen();
		//Scrolling Background
		//Viz.RenderClippedSprite("Stars", 0, BGy);
		//Viz.RenderClippedSprite("Stars", 0, BG2y);

		BGy = BGy + (0.5* DeltaTime);
		BG2y = BG2y + (0.5 * DeltaTime);
		if (BGy >= 768)
			BGy = 0;
		if (BG2y >= 0)
			BG2y = -768;
		//Update all entitys
		for (Entity* p : m_entityVector)
			p->Update(Viz,*this);


		size_t i = 0;
		for (Entity* p : m_entityVector)
		{
			if (p->GetIsAlive() == true)
			{
				if (p->GetSide() != Side::eNeutral)
				{
					for (size_t j = i + 1; j < m_entityVector.size(); j++)
					{
						if (p->CheckCollision(m_entityVector[i], m_entityVector[j]))
						{

						}
					}
				}
			}
			i++;
		}
	}

}

Simulation::~Simulation()
{
	for (auto& p : m_entityVector)
		delete p;
}
