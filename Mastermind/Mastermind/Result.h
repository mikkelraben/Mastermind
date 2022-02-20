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
    ResultType* getResult(uint8_t* guess, int32_t* secret, uint8_t size);
private:
    ResultType* m_result;
    uint8_t m_size;
    uint8_t secret;
    uint8_t* guess;
};

