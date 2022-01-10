#pragma once
#include "Entity.h"
class PlayerEntity :

    public Entity
{
public:
    PlayerEntity();
    void Update(Visulisation& Viz, Simulation& Sim) override final;
    const HAPI_TKeyboardData& KeyData = HAPI.GetKeyboardData();
    const HAPI_TControllerData& GetControllerData(unsigned int controller);
    const HAPI_TControllerData& data = HAPI.GetControllerData(0);
    float Normal = 0;
    Side GetSide() const override { return Side::ePlayer; }
    std::string GetSpriteName() override final;
    std::string SpriteName;
    void Setup() override final;
private:

};
