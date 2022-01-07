#pragma once
#include "Visulisation.h"
class Simulation;

enum class Side
{
	eNeutral,
	ePlayer,
	eEnemy
};

class Entity
{
public:
	bool CheckCollision(Entity& other);
	Entity() = default;
	virtual ~Entity() = default;
	virtual void Update(Visulisation &Viz, Simulation &Sim) = 0;
	float PosX = 500;
	float PosY = 675;
	float Health = 100;
	bool GetIsAlive() { return IsAlive; };
	void SetIsAlive(bool SetAlive);
	void SetPos(int EPosX, int EPosY);
	bool IsAlive = false;
	virtual Side GetSide() const = 0;


private:
	Side M_side;

};