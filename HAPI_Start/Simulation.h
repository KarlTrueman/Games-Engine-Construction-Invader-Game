#pragma once
#include "HAPI_lib.h"
#include <vector>
using namespace HAPISPACE;
class Entity;
class Visulisation;

class Simulation
{
public:
	void Run();
	
private:
	void LoadLevel();
	std::vector<Entity*> m_entityVector;
	
};

