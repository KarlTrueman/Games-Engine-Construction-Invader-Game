#pragma once
#include "HAPI_lib.h"
using namespace HAPISPACE;
#include <unordered_map>

class Sprite;

class Visulisation
{
	private:
		int m_screenWidth = 1024;
		int m_screenHeight = 768;
		BYTE* m_screen{ nullptr };
		std::unordered_map<std::string, Sprite*> m_spriteMap;
	public:
		~Visulisation();

		bool Initialise();

		bool CreateSprite(const std::string& spriteName, const std::string& filename);

		void RenderSprite(const std::string& spriteName, int posX, int posY);
		Visulisation() = default;

		void ClearScreen();
};

