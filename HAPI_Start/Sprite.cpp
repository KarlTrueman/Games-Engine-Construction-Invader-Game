#include "Sprite.h"
#include "Rectangle.h"

bool Sprite::Load(const std::string& filename)
{
	if (!HAPI.LoadTexture(filename, &m_texturePointer, m_tw, m_th))
	{
		HAPI.UserMessage("Missing Background Texture", "Error");
		return false;
	}
	return true;
}

void Sprite::ClippedRender(BYTE* screen, const Rectangle& screenRect, int posX, int posY)
{
	
	Rectangle textureRect(0, m_tw, 0, m_th);
	Rectangle clippedRect(textureRect);

	clippedRect.Translate(posX, posY);

	clippedRect.ClipTo(screenRect);

	clippedRect.Translate(-posX, -posY);

	if (posX < 0)
		posX = 0;
	if (posY < 0)
		posY = 0;

	BYTE* screenpntr = screen + ((size_t)posX + posY * screenRect.width()) * 4;

	BYTE* tempTex = m_texturePointer + (clippedRect.left + clippedRect.top * textureRect.width()) * 4;




	for (int y = 0; y < clippedRect.height(); y++)
	{
		for (int x = 0; x < clippedRect.width(); x++)
		{
			if (tempTex[3] == 255)
			{
				screenpntr[0] = tempTex[0];
				screenpntr[1] = tempTex[1];
				screenpntr[2] = tempTex[2];
			}
			else if (tempTex[3] > 0)
			{
				float mod = tempTex[3] / 255.0f;
				screenpntr[0] = tempTex[0] * mod + screenpntr[0] * (1.0 - mod);
				screenpntr[1] = tempTex[1] * mod + screenpntr[1] * (1.0 - mod);
				screenpntr[2] = tempTex[2] * mod + screenpntr[2] * (1.0 - mod);
			}

			tempTex += 4;
			screenpntr += 4;

		}
		tempTex += (textureRect.width() - clippedRect.width()) * 4;
		screenpntr += (screenRect.width() - clippedRect.width()) * 4;
	}
}

void Sprite::BackgroundRender(BYTE* screen, const Rectangle& screenRect, int posX, int posY)
{

	BYTE* screenpntr{ screen + ((size_t)posX + posY * screenRect.width()) * 4 };
	BYTE* tempTex{ m_texturePointer };
	
	for (int y = 0; y < m_th; y++)
	{
		memcpy(screenpntr, tempTex, m_tw * 4);
		tempTex += m_tw * 4;
		screenpntr += screenRect.width() * 4;
	}


}
