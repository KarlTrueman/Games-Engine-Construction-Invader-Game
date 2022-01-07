#pragma once
#include "Entity.h"
class Simulation;
class Bullet :
    public Entity
{
public:
    Bullet(std::string filename) : Entity(filename) {};
    void Update(Visulisation& Viz, Simulation& Sim) override final;
    Side GetSide() const override { return Side::ePlayer; }
    void setup() override final;
private:
    
    //bool IsAlive = false;
    //int EposX;
    //int EposY;
};

