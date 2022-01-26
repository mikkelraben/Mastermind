#pragma once
#include "Colors.h"
#include "CodeRow.h"
class Board
{
public:
	Board();
	CodeRow* rows;
	Code Secret;
private:
	int numRows = 10;
	int numColumns = 4;
	int numColors = 6;

};
