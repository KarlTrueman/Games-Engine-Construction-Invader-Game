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
		~Sprite();
		bool Load(const std::string& filename);
		void ClippedRender(BYTE* screen, const Rectangle& screenRect, int posX, int posY);
		void BackgroundRender(BYTE* screen, const Rectangle& screenRect, int posX, int posY);
		int GetWidth() { return m_tw; }
		int GetHeight() { return m_th; }
};

