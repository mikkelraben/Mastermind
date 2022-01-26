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

};
