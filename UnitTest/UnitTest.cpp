#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "../Mastermind/Mastermind/Result.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(AllBlack) {
			int length = 1;
			unsigned char* guess = new unsigned char[length];
			for (int i = 0; i < length; i++)
			{
				guess[i] = i;
			}
			int* secret = new int[length];
			Result m_result;
			Result::ResultType* result;
			
			result = m_result.getResult(guess, secret, length);
			Assert::IsTrue(result[0] == Result::ResultType::Black);
		}
	};
}
