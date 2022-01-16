#pragma once
#include "Color.h"

class masterColors {
public:
	masterColors();
	static const int numColors = 6;
	m_Color::Color Colors[numColors];
private:
	void GenerateColors();
};
