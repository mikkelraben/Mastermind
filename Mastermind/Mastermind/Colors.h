#pragma once
#include "Color.h"

class masterColors {
public:
	masterColors();
	masterColors(int numColors);
	m_Color::Color* Colors;
private:
	void GenerateColors();
	int numColors = 6;
};
