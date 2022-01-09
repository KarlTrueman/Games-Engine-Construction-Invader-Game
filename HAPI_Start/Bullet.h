#pragma once
#include "Entity.h"
class Simulation;
class Bullet :
    public Entity
{
public:
    Bullet();
    void Update(Visulisation& Viz, Simulation& Sim) override final;
    Side GetSide() const override { return Side::eEnemy; }
private:
    //bool IsAlive = false;
    //int EposX;
    //int EposY;
};

