#pragma once

#include "HAPI_lib.h"
using namespace HAPISPACE;
#include "Rectangle.h"



class Sprite
{
	private:
		BYTE* m_texturePointer{ nullptr };
		int m_tw{ 0 };
		int	m_th{ 0 };

	public:
		bool Load(const std::string& filename);
		void Render(BYTE* screen, const Rectangle& screenRect, int posX, int posY);
};

