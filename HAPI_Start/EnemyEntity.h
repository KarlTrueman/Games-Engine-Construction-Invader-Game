#pragma once
#include "Entity.h"
class EnemyEntity :
    public Entity
{
public:
    void Update(Visulisation& Viz, Simulation& Sim) override final;
    EnemyEntity(std::string filename) : Entity(filename) {};
    Side GetSide() const override { return Side::eEnemy; }
    void setup() override final;

    


private:
    bool InitalSpawn = true;
    bool Toggle = false;
};

