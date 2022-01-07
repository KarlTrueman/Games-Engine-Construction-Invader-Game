#pragma once
#include "HAPI_lib.h"
#include <vector>
#include "Visulisation.h"
using namespace HAPISPACE;
class Entity;
class Visulisation;

class Simulation
{
public:
	void Run();
	~Simulation();
	std::vector<Entity*> m_entityVector;
	void SpawnBullet(int PlayerX, int PlayerY);
	float GetDeltaTime() { return DeltaTime; };
private:
	int StartOfBullets = 0;
	Visulisation Viz;
	void LoadLevel();
	//Time
	float OldTime = 0;
	float DeltaTime = 0;
	//Scrolling Background
	float BGy = 0; //Background 1 start pos
	float BG2y = -768; // Background 2 start pos

};

