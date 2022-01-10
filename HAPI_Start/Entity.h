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
	Entity() = default;

	bool GetIsBullet() { return IsBullet; }
	bool GetIsAlive() { return IsAlive; };
	void SetIsAlive(bool SetAlive);
	void SetPos(float EPosX, float EPosY);
	//Score
	int GetScore() { return Score; }
	void AddScore(int value);
	void TakeScore(int value);
	void SetScore() { Score = 0; }
	//Health
	int GetHealth() { return Health; }
	void AddHealth(int value);
	void TakeHealth(int value);
	void SetHealth() { Health = 100; }

	virtual Side GetSide() const = 0;
	virtual std::string GetSpriteName();
	virtual void Update(Visulisation &Viz, Simulation &Sim) = 0;
	bool CheckCollision(Visulisation& Viz, Entity& other);
	virtual void Setup() = 0;
	virtual ~Entity() = default;
private:

protected:
	bool IsBullet = false;
	bool IsAlive = false;
	float PosX = 0;
	float PosY = 0;
	int Health = 100;
	int Score = 0;
};