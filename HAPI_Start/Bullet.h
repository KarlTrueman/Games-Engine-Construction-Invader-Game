#pragma once
#include "Entity.h"
class Simulation;
class Bullet :
    public Entity
{
public:
    void Update(Visulisation& Viz, Simulation& Sim) override final;
private:
    //bool IsAlive = false;
    //int EposX;
    //int EposY;
};

