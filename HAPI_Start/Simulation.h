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
	
private:
	Visulisation Viz;
	void LoadLevel();
	std::vector<Entity*> m_entityVector;
};

