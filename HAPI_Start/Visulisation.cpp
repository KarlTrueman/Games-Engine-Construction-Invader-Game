#include "Visulisation.h"
#include "Sprite.h"
#include "Rectangle.h"

Visulisation::~Visulisation()
{
	for (auto& p : m_spriteMap)
		delete p.second;
}

bool Visulisation::Initialise()
{
	if (!HAPI.Initialise(m_screenWidth, m_screenHeight))
		return false;

	m_screen = { HAPI.GetScreenPointer() };
	HAPI.SetShowFPS(true);
	return true;
}

bool Visulisation::CreateSprite(const std::string& spriteName, const std::string& filename)
{
	Sprite* newSprite = new Sprite;
	if (!newSprite->Load(filename))
	{
		delete newSprite;
		return false;
	}

	m_spriteMap[spriteName] = newSprite;

	return true;
}

void Visulisation::RenderClippedSprite(const std::string& spriteName, int posX, int posY)
{
	if (m_spriteMap.find(spriteName) == m_spriteMap.end())
	{
		return;
	}
	Rectangle screenRect(0, m_screenWidth, 0, m_screenHeight);
	m_spriteMap[spriteName]->ClippedRender(m_screen, screenRect, posX, posY);

}

void Visulisation::RenderBackgroundSprite(const std::string& spriteName, int posX, int posY)
{
	if (m_spriteMap.find(spriteName) == m_spriteMap.end())
	{
		return;
	}
	Rectangle screenRect(0, m_screenWidth, 0, m_screenHeight);
	m_spriteMap[spriteName]->BackgroundRender(m_screen, screenRect, posX, posY);
}

	void Visulisation::ClearScreen()
{
	memset(m_screen, 0, m_screenWidth * m_screenHeight * 4);
}

	Rectangle Visulisation::GetRectangle(std::string& name)
	{
		Rectangle Rec;
		Rec = m_spriteMap[name]->GetSpriteRectangle();

		return Rec;
	}
