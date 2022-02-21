#pragma once

class Result
{

public:
    enum class ResultType
    {
        None,
        White,
        Black
    }; 
    ResultType* getResult(unsigned char* guess, int* secret, unsigned char size);
private:
    ResultType* m_result;
    unsigned char m_size;
    unsigned char* guess;
};

