#pragma once
#include "Code.h"
class CodeRow
{
public:
	CodeRow(int Length);
	enum class Result {None, Color, Position};
	int size;
	Code* Row;
	Result* ResultGrid;
	void calculateResult();
};

