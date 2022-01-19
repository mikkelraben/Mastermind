#include "pch.h"
#include "Colors.h"
#include <exception>

masterColors::masterColors()
{
	Colors = new m_Color::Color[numColors];
	GenerateColors();
}

//int must be 1 or larger.
masterColors::masterColors(int numColors)
{
	if (numColors <= 0)
	{
		throw std::out_of_range("numColors is lower or equal to zero (0)");
	}
	this->numColors = numColors;
	masterColors();
}

void masterColors::GenerateColors()
{
	for (int i = 0; i < numColors; i++)
	{
		float progress = i / static_cast<float>((numColors-1));
		int hue = (progress * 720);
		hue = hue % 360;
		float lightness = progress * 0.8 + 0.1;
		m_Color::HSL hsl = m_Color::HSL::HSL(hue, 1, lightness);
		Colors[i] = hsl.ToRGB();
	}
}

