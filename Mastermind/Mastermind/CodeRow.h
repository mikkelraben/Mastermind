#pragma once
#include "Code.h"
class CodeRow
{
	CodeRow();
	enum Result {None, Color, Position};
	Code* Row;
	Result* ResultGrid;
	void calculateResult();
};

