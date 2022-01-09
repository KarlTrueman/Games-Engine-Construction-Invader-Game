#pragma once
#include "Entity.h"
class PlayerEntity :

    public Entity
{
public:
    PlayerEntity(std::string filename) : Entity(filename) {};
    void Update(Visulisation& Viz, Simulation& Sim) override final;
    const HAPI_TKeyboardData& KeyData = HAPI.GetKeyboardData();
   // const HAPI_TControllerData& GetControllerData(unsigned int controller);
    //const HAPI_TControllerData& data = HAPI.GetControllerData(0);
    float Normal = 0;
    Side GetSide() const override { return Side::ePlayer; }
    void setup() override final;
private:

};
