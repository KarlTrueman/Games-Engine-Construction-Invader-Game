// Include the HAPI header to get access to all of HAPIs interfaces
#include <HAPI_lib.h>
#include "Simulation.h"
// HAPI itself is wrapped in the HAPISPACE namespace
using namespace HAPISPACE;

void HAPI_Main()
{
	Simulation Sim;
	Sim.Run();

}



