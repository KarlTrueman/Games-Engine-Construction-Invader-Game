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
protected:

public:

	std::string m_spriteName;
	bool IsBullet = false;
	bool GetIsBullet() { return IsBullet; }
	bool CheckCollision(Visulisation &Viz, Entity*One, Entity*Two);
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
	virtual void setup() = 0;

	virtual std::string GetSpriteName();


private:
	Side M_side;

};