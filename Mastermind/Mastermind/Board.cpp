#include "pch.h"
#include "Board.h"

Board::Board()
{
	Code secret;
	rows = (CodeRow*)malloc(sizeof(CodeRow)*numRows);

	for (int i = 0; i < numRows; i++)
	{
		rows[i] = CodeRow(numColumns);
	}
}
