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
	bool IsBullet = false;
	bool GetIsBullet() { return IsBullet; }

	bool GetIsAlive() { return IsAlive; };
	void SetIsAlive(bool SetAlive);

	Entity() = default;
	virtual ~Entity() = default;
	virtual void Update(Visulisation &Viz, Simulation &Sim) = 0;

	float PosX = 500;
	float PosY = 675;
	float Health = 100;

	void SetPos(int EPosX, int EPosY);
	bool IsAlive = false;
	virtual Side GetSide() const = 0;


private:
	

};