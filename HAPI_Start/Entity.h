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
	std::string SpriteName;
	std::string filename;

public:


	bool IsBullet = false;
	bool GetIsBullet() { return IsBullet; }
	bool CheckCollision(Entity*One, Entity*Two);
	Entity(std::string filename) : filename(filename) {};
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


private:
	Side M_side;

};