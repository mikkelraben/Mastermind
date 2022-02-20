#include "pch.h"
#include "Result.h"

Result::ResultType* Result::getResult(uint8_t* guess, int32_t* secret, uint8_t size)
{
    ResultType* result = new ResultType[size];
    for (int i = 0; i < size; i++)
    {
        result[i] = ResultType::None;
        for (int j = 0; j < size; j++)
        {
            if (guess[i] == secret[j])
            {
                if (i == j)
                {
                    result[i] = ResultType::Black;
                }
                else
                {
                    result[i] = ResultType::White;
                }
            }
        }
    }
    //sort result
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (result[i] < result[j])
            {
                ResultType temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }
    return result;
}
