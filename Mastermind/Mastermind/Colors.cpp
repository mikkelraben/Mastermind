#include "pch.h"
#include "Colors.h"

masterColors::masterColors()
{
	GenerateColors();
}

void masterColors::GenerateColors()
{
	for (int i = 0; i < numColors; i++)
	{
		float progress = (i + 1) / numColors;
		int hue = (progress * 720);
		hue = hue % 360;
		float lightness = progress * 0.8 + 0.1;
		m_Color::HSL hsl = m_Color::HSL::HSL(hue, 1, lightness);
		Colors[i] = hsl.ToRGB();
	}
}
