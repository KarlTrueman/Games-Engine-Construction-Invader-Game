#pragma once
#include "Entity.h"
class EnemyEntity :
    public Entity
{
public:
    EnemyEntity(int EnemyX, int EnemyY);
    void Update(Visulisation& Viz) override final;

    int EposX;
    int EposY;
private:
    bool initalSpawn = true;
};

