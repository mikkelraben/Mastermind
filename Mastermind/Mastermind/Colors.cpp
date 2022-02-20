#include "pch.h"
#include "Colors.h"
#include <exception>

//rework to use optional variable
masterColors::masterColors()
{
	numColors = 6;
	init();
}

//int must be 1 or larger.
masterColors::masterColors(int numColors)
{
	if (numColors <= 0)
	{
		throw std::out_of_range("numColors is lower or equal to zero (0)");
	}
	this->numColors = numColors;
	init();
}


int masterColors::NumColors()
{
	return numColors;
}

void masterColors::GenerateColors()
{
	int repetitions;
	if (numColors > 16) {
		repetitions = (numColors + 15)/16;
	}
	else
	{
		repetitions = 1;
	}
	for (int i = 0; i < numColors; i++)
	{
		float progress = i / static_cast<float>(numColors);

		int hue = (progress * repetitions*360);
		hue = hue % 360;
		float lightness;
		if (numColors > 16)
		{
			lightness = progress * 0.6 + 0.1;
		}
		else
		{
			lightness = 0.5;
		}
		
		m_Color::HSL hsl = m_Color::HSL::HSL(hue, 1, lightness);
		Colors[i] = hsl.ToRGB();
	}
}

void masterColors::init()
{
	Colors = new m_Color::Color[numColors];
	GenerateColors();
}

