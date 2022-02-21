#pragma once
#include "pch.h"
#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/Microsoft.UI.Xaml.Markup.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"


using namespace winrt;
namespace m_Color {
	struct Color
	{
		const char* name;
		Windows::UI::Color color;
		Color::Color(const char* Name, Windows::UI::Color color);
		Color::Color(Windows::UI::Color color);
		Color::Color();
		Windows::UI::Color hoverColor;
		Windows::UI::Color PressedColor;
		void CalculateOtherColors();
	};

	struct HSL {
		//h between 0-360
		//s and l between 0-1
		float h,s,l;
		HSL::HSL(Windows::UI::Color color);
		HSL::HSL(float h, float s, float l);
		Windows::UI::Color ToRGB();
		void RGBNorm(float &value);
		float ColorConvert(float temp1, float temp2, float tempColor);
	};

}
