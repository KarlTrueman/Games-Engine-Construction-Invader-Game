#pragma once
#include "Entity.h"
class PlayerEntity :

    public Entity
{
public:
    void Update(Visulisation& Viz, Simulation& Sim) override final;
    const HAPI_TKeyboardData& KeyData = HAPI.GetKeyboardData();
    const HAPI_TControllerData& GetControllerData(unsigned int controller);
    const HAPI_TControllerData& data = HAPI.GetControllerData(0);
    float Normal = 1 / sqrt(2);
private:

};

