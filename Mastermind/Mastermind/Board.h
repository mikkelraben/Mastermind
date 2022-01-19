#pragma once
#include "Colors.h"
#include "CodeRow.h"
class Board
{
public:
	Board();
	CodeRow* rows;
private:
	int numRows = 10;

};
