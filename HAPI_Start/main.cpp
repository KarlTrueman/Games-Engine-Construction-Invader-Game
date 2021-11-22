/*
	HAPI Start
	----------
	This solution contains an already set up HAPI project and this main file

	The directory structure and main files are:

	HAPI_Start - contains the Visual Studio solution file (.sln)
		HAPI_Start - contains the Visual Studio HAPI_APP project file (.vcxproj) and source code
			HAPI - the directory with all the HAPI library files
			Data - a place to put your data files with a few sample ones provided

	Additionally in the top directory there is a batch file for creating a redistributable Demo folder

	For help using HAPI please see the Reference folder in the HAPI sub-directory
*/

// Include the HAPI header to get access to all of HAPIs interfaces
#include <HAPI_lib.h>
#include "Rectangle.h"
#include "visulisation.h"
#include <algorithm>
#include <map>
#include "Simulation.h"


// HAPI itself is wrapped in the HAPISPACE namespace
using namespace HAPISPACE;

// Every HAPI program has a HAPI_Main as an entry point
// When this function exits the program will close down


void BlitBG(BYTE* screen, int width, BYTE* backgroundtexture, int btw, int bth, int posX, int posY)
{
	BYTE* screenpntr{ screen + ((size_t)posX + posY * width) * 4 };
	BYTE* tempTex{ backgroundtexture };

	for (int y = 0; y < bth; y++)
	{
		memcpy(screenpntr, tempTex, btw * 4);
		tempTex += btw * 4;
		screenpntr += width * 4;
	}
}

void BlitTexture(BYTE* screen, int width, BYTE* texture, int tw, int th, int posX, int posY )
{
	BYTE* screenpntr{ screen + (posX + posY * width) * 4 };
	BYTE* tempTex{ texture };
	for (int y = 0; y < th; y++)
	{
		for (int x = 0; x < tw; x++)
		{
			if (tempTex[3] == 255)
			{
				screenpntr[0] = tempTex[0];
				screenpntr[1] = tempTex[1];
				screenpntr[2] = tempTex[2];
			}
			else if (tempTex[3] > 0 )
			{
				float mod = tempTex[3] / 255.0f;
				screenpntr[0] = tempTex[0] * mod + screenpntr[0] * (1.0 - mod);
				screenpntr[1] = tempTex[1] * mod + screenpntr[1] * (1.0 - mod);
				screenpntr[2] = tempTex[2] * mod + screenpntr[2] * (1.0 - mod);
			}

			tempTex += 4;
			screenpntr += 4;
		}
		screenpntr += (width - tw) * 4;
	}
}

void HAPI_Main()
{
	Simulation Sim;
	Sim.Run();

}



