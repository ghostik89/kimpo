#pragma once
#include <map>
#include <string>
#include <vector>
using namespace std;

const vector<pair<string, char>> Dictionary = {
	{".-", '�'}, {"-...", '�'}, {".--", '�'},
	{"--.",'�'}, {"-..",'�'}, {".",'�'},
	{"...-",'�'}, {"--..",'�'}, {"..",'�'},
	{".---",'�'}, {"-.-",'�'}, {".-..",'�'},
	{"--",'�'}, {"-.",'�'}, {"---",'�'},
	{".--.",'�'}, {".-.",'�'}, {"...",'�'},
	{"-",'�'}, {"..-",'�'}, {"..-.",'�'},
	{"....",'�'}, {"-.-.",'�'}, {"---.",'�'},
	{"----",'�'}, {"--.-",'�'}, {".--.-.",'�'},
	{"-.--",'�'}, {"-..-",'�'}, {"...-..." , '�'},
	{"..--" , '�'}, {".-.-" , '�'}, {"-----" , '0'},
	{".----" , '1'}, {"..---" , '2'}, {"...--" , '3'},
	{"....-" , '4'}, {"....." , '5'}, {"-...." , '6'},
	{"--..." , '7'}, {"---.." , '8'}, {"----." , '9'},
};

const int MAX_SIZE = 256;

/*!	����� ��������� ��������� �������� � ������ ����� �� �������
	param[in]: DecodeString - �������� ������, ������������� � ������ �����
	param[in|out]: DecodedVariants - ������ �������������� ���������
	param[in]: BuildString - ������ ��� ���������� �������� ������������� ������ �����������
*/
void DecodeMorze(const string& DecodeString, vector<string>& DecodedVariants, const string& BuildString);

/*! �������� �� ����������� ������� � ��������� �� ������ �����
	param[in]: CheckedString - ������, ������� ����������� �� ������� ����������� ��������
	return: ����� �� ������ ������������ �������(true - �����, false - �� �����)
*/
bool CheckStringForInvalidChar(const string& CheckedString);
