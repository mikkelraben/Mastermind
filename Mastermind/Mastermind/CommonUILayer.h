#pragma once
#include "Board.h"
class CommonUILayer
{
	CommonUILayer(Board* board);
	void initialize();
	void reset();
	void setResult();

	Board* board;
};

