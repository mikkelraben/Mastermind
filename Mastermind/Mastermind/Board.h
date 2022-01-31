#pragma once
#include "Colors.h"
#include "CodeRow.h"
class Board
{
public:
	Board();
	CodeRow* rows;
	Code Secret;
	void AdvanceRow();
private:
	int numRows = 10;
	int numColumns = 4;
	int numColors = 6;
	int ActiveRow = 0;
};
