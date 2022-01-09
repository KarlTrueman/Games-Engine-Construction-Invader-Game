#pragma once
#include "Entity.h"
class Simulation;
class Bullet :
    public Entity
{
public:
    Bullet();
    bool IsBullet = true;
    std::string m_spriteName = "Bullet";
    void Update(Visulisation& Viz, Simulation& Sim) override final;
    Side GetSide() const override { return Side::ePlayer; }
    void setup() override final;
private:
    
    //bool IsAlive = false;
    //int EposX;
    //int EposY;
};

