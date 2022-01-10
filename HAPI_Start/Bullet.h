#pragma once
#include "Entity.h"
class Simulation;
class Bullet :
    public Entity
{
public:
    Bullet();
    void Update(Visulisation& Viz, Simulation& Sim) override final;
    Side GetSide() const override { return Side::ePlayer; }
    std::string GetSpriteName() override final;
    std::string SpriteName;
    void Setup() override final;
private:
    //bool IsAlive = false;
    //int EposX;
    //int EposY;
};

