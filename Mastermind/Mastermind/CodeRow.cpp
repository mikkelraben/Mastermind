#include "pch.h"
#include "CodeRow.h"

//default to a size of 4
CodeRow::CodeRow(int length = 4)
{
	size = length;
	Row = new Code[size];
	ResultGrid = new Result[size];
}

void CodeRow::calculateResult()
{

}
