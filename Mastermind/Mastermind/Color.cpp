#include "pch.h"
#include "Color.h"

namespace m_Color {
	Color::Color(const char* Name, Windows::UI::Color color)
	{
		this->name = Name;
		this->color = color;
		CalculateOtherColors();
	}
	Color::Color(Windows::UI::Color color)
	{
		this->color = color;
	}
	Color::Color()
	{

	}


	void Color::CalculateOtherColors() {
		HSL hsl = HSL(color);
		HSL hover = hsl;
		HSL pressed = hsl;
		//if color is dark
		if (hsl.l < 0.3)
		{
			hover = HSL(hsl.h, hsl.s, hsl.l + 0.02);
			//if color is very dark
			if (hsl.l > 0.02)
			{
				pressed = HSL(hsl.h, hsl.s, hsl.l - 0.02);
			}
		}
		//if color is light
		else
		{
			hover = HSL(hsl.h, hsl.s, hsl.l - 0.02);
			pressed = HSL(hsl.h, hsl.s, hsl.l - 0.04);
		}
		hoverColor = hover.ToRGB();
		PressedColor = pressed.ToRGB();
	}

	HSL::HSL(Windows::UI::Color color)
	{
		float R = color.R / 255;
		float G = color.G / 255;
		float B = color.B / 255;

		float minRGB = min(min(R, G), B);
		float maxRGB = max(max(R, G), B);

		l = (minRGB + maxRGB) / 2;
		if (minRGB == maxRGB)
		{
			h = 0;
			s = 0;
		}
		else
		{
			//calculate saturation
			if (l <= 0.5) {
				s = (maxRGB - minRGB) / (maxRGB + minRGB);
			}
			else
			{
				s = (maxRGB - minRGB) / (2 - maxRGB - minRGB);
			}

			//calculate hue
			if (R == maxRGB) {
				h = (G - B) / (maxRGB - minRGB);
			}
			else if (G == maxRGB) {
				h = 2 + (G - B) / (maxRGB - minRGB);
			}
			else
			{
				h = 4 + (G - B) / (maxRGB - minRGB);
			}
			h * 60;
			if (h < 0) {
				h = h + 360;
			}
		}
	}

	HSL::HSL(float h, float s, float l)
	{
		this->h = h;
		this->s = s;
		this->l = l;
	}

	Windows::UI::Color HSL::ToRGB()
	{
		Windows::UI::Color color = Microsoft::UI::Colors::Black();

		if (s == 0) {
			color.R = l;
			color.G = l;
			color.B = l;
		}
		else
		{
			float temp1, temp2, hNorm, tempR, tempG, tempB;

			if (l < 0.5)
			{
				temp1 = l * (1 + s);
			}
			else {
				temp1 = l + s - (l * s);
			}

			temp2 = (2 * l) - temp1;
			hNorm = h / 360;
			tempR = hNorm + 0.333;
			tempG = hNorm;
			tempB = hNorm - 0.333;

			RGBNorm(tempR);
			RGBNorm(tempG);
			RGBNorm(tempB);

			tempR = ColorConvert(temp1, temp2, tempR);
			tempG = ColorConvert(temp1, temp2, tempG);
			tempB = ColorConvert(temp1, temp2, tempB);

			color.R = tempR * 255;
			color.G = tempG * 255;
			color.B = tempB * 255;
		}

		return color;
	}

	float HSL::ColorConvert(float temp1, float temp2, float tempColor)
	{
		float Color;
		//test 1
		if (6 * tempColor < 1) {
			Color = temp2 + (temp1 - temp2) * 6 * tempColor;
		} 
		//test 2
		else if (2 * tempColor < 1) {
			Color = temp1;
		} 
		//test 3
		else if (3 * tempColor < 2) {
			Color = temp2 + (temp1 - temp2) * (0.666 - tempColor) * 6;
		}
		else
		{
			Color = temp2;
		}

		return Color;
	}

	void HSL::RGBNorm(float& value)
	{
		if (value < 0)
		{
			value = value + 1;
		}
		if (value > 1)
		{
			value = value - 1;
		}
	}
}