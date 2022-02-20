#pragma once
#include "Color.h"

class masterColors {
public:
	masterColors();
	masterColors(int numColors);
	m_Color::Color* Colors;
	int NumColors();
private:
	void GenerateColors();
	void init();
	int numColors = 6;
};
