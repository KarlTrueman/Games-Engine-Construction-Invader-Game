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
private:
	Visulisation Viz;
	void LoadLevel();
};

