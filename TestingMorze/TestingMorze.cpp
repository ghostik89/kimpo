#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>
#include "../Morze/morze.cpp"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



bool CompareVectors(const vector<string>& Checked, const vector<string>& Correct)
{
	bool Mark = true;
	if (Checked.size() != Correct.size()) {
		Logger::WriteMessage("Different length of vectors!");
		Mark = false;
	}

	for(int i = 0; i < Correct.size() && Mark; i++)
		if (Checked[i] != Correct[i]) {
			Logger::WriteMessage("Not equal!");
			Mark = false;
		}

	return Mark;
}

namespace TestingMorze
{
	TEST_CLASS(TestingMorze)
	{
	public:
		
		TEST_METHOD(OneDigitTest)
		{
			const string InputString = "...--";//3
			vector<string> InputVector;
			string BiuldString;
			DecodeMorze(InputString, InputVector, BiuldString);

			const vector<string> WaitingResult = {
				"≈≈¿“", "≈≈¬", "≈≈≈Ã", "≈≈≈““",
				"≈»Ã", "≈»““", "≈”“",
				"≈ﬁ", "∆“", "»¿“", "»¬",
				"»≈Ã", "»≈““", "—Ã", "—““",
				"3"
			};
			Assert::IsTrue(CompareVectors(InputVector, WaitingResult));
		}

		TEST_METHOD(OneDoteTest)
		{
			const string InputString = ".";//E
			vector<string> InputVector;
			string BiuldString;
			DecodeMorze(InputString, InputVector, BiuldString);

			vector<string> WaitingResult = {"≈"};
			Assert::IsTrue(CompareVectors(InputVector, WaitingResult));
		}

		TEST_METHOD(OneDashTest)
		{
			const string InputString = "-";//T
			vector<string> InputVector;
			string BiuldString;
			DecodeMorze(InputString, InputVector, BiuldString);

			vector<string> WaitingResult = {"“"};
			Assert::IsTrue(CompareVectors(InputVector, WaitingResult));
		}

		TEST_METHOD(OneLetterTest)
		{
			const string InputString = ".-";//A
			vector<string> InputVector;
			string BiuldString;
			DecodeMorze(InputString, InputVector, BiuldString);

			vector<string> WaitingResult = {"¿", "≈“"};
			Assert::IsTrue(CompareVectors(InputVector, WaitingResult));
		}

		TEST_METHOD(EmptyStringTest)
		{
			const string InputString = "";
			vector<string> InputVector;
			string BiuldString;
			DecodeMorze(InputString, InputVector, BiuldString);

			vector<string> WaitingResult = {""};
			Assert::IsTrue(CompareVectors(InputVector, WaitingResult));
		}

		TEST_METHOD(OneWordTest)
		{
			const string InputString = "---..-.---";//◊¿…
			vector<string> InputVector;
			string BiuldString;
			DecodeMorze(InputString, InputVector, BiuldString);

			string MustBeString = "◊¿…";
			Assert::IsTrue(find(InputVector.begin(), InputVector.end(), MustBeString) != InputVector.end());
		}

		TEST_METHOD(OneNumberTest)
		{
			const string InputString = ".---------";//10
			vector<string> InputVector;
			string BiuldString;
			DecodeMorze(InputString, InputVector, BiuldString);

			string MustBeString = "10";
			Assert::IsTrue(find(InputVector.begin(), InputVector.end(), MustBeString) != InputVector.end());
		}

		TEST_METHOD(NumbersAndLetterTest)
		{
			const string InputString = ".-....-";//¿4
			vector<string> InputVector;
			string BiuldString;
			DecodeMorze(InputString, InputVector, BiuldString);

			string MustBeString = "¿4";
			Assert::IsTrue(find(InputVector.begin(), InputVector.end(), MustBeString) != InputVector.end());
		}

		TEST_METHOD(NumbersAndWordTest)
		{
			const string InputString = "---..-.---.---------";//◊¿…10
			vector<string> InputVector;
			string BiuldString;
			DecodeMorze(InputString, InputVector, BiuldString);

			string MustBeString = "◊¿…10";
			Assert::IsTrue(find(InputVector.begin(), InputVector.end(), MustBeString) != InputVector.end());
		}
	};
}
