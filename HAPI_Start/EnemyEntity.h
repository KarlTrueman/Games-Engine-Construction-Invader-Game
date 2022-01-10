#pragma once
#include "Entity.h"
class EnemyEntity :
    public Entity
{
public:
    void Update(Visulisation& Viz, Simulation& Sim) override final;
    EnemyEntity();
    Side GetSide() const override { return Side::eEnemy; }
    std::string GetSpriteName() override final;
    std::string SpriteName;
    void Setup() override final;


private:
    bool InitalSpawn = true;
    bool Toggle = false;
};

