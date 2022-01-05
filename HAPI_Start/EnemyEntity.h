#pragma once
#include "Entity.h"
class EnemyEntity :
    public Entity
{
public:
    EnemyEntity(int EnemyX, int EnemyY);
    void Update(Visulisation& Viz, Simulation& Sim) override final;


private:
    bool initalSpawn = true;
    int EposX;
    int EposY;
};

