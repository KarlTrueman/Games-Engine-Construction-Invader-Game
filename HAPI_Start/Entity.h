#pragma once
#include "Visulisation.h"
class Simulation;
class Entity
{
public:

	Entity() = default;
	virtual ~Entity() = default;
	virtual void Update(Visulisation &Viz, Simulation &Sim) = 0;
	float PosX = 50;
	float PosY = 50;
	float Health = 100;
	bool GetIsAlive() { return IsAlive; };
	void SetIsAlive(bool SetAlive);
	void SetPos(int EPosX, int EPosY);
	bool IsAlive = false;


private:
	//bool IsAlive = false;

};