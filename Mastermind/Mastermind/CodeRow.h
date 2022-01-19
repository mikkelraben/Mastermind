#include "pch.h"

class CodeRow
{
	enum result {None,Color,Position}; 
	int Code[4];
	result Result[4];
	void UpdateResult();
};
