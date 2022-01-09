#pragma once
#include "Entity.h"
class EnemyEntity :
    public Entity
{
public:
    void Update(Visulisation& Viz, Simulation& Sim) override final;
    EnemyEntity(float EnemyX, float EnemyY);
    Side GetSide() const override { return Side::eEnemy; }
    


private:
    bool InitalSpawn = true;
    bool Toggle = false;
};

