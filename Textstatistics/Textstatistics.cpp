///////////////////////////////////////////////////////////////////////////
// Workfile : Matrix.cpp
// Author : Leander Kieweg
// Date : 21. 11. 2025
// Description : Matrix module with general matrix utility functions
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include "Textstatistics.h"
#include "FileOps.h"
#include <iostream>
#include <locale>

using namespace std;

const unsigned int TEXT_SIZE = 100;
const unsigned int charOcorencyCounter_SIZE = 29;

void analyse(std::string const& fileName)
{
	char text[TEXT_SIZE];
	size_t textLen = 0;
	bool retFlag;
	ReadFile(fileName, text, textLen, retFlag);
	if (retFlag) return;


	unsigned int charOcorencyCounter[charOcorencyCounter_SIZE] = { 0 };

	for (size_t i = 0; i < textLen; i++)
	{
		if (toupper(text[i])-'A' >= 0 && toupper(text[i]) - 'A' <= 26)
		{
			charOcorencyCounter[toupper(text[i])-'A']++;
		}
		else // edge case for non A-Z characters
		{
			switch (text[i])
			{
			case ' ':
				charOcorencyCounter[26]++;
				break;
			case '.':
			case ',':
			case ';':
			case ':':
			case '?':
			case '!':
				charOcorencyCounter[27]++;
				break;
			default:
				charOcorencyCounter[28]++;
				break;
			}
		}
	}

	PrintAnalyticsResult(charOcorencyCounter);

}

void ReadFile(const std::string& fileName, char  text[100], size_t& textLen, bool& retFlag)
{
	retFlag = true;
	if (!ReadData(fileName, text, TEXT_SIZE, textLen))
	{
		cout << "Error reading file '" << fileName << "'." << endl;
		return;
	}

	cout << "Text from file '" << fileName << "' with size: " << textLen << " text: " << endl << text << endl;
	retFlag = false;
}

void PrintAnalyticsResult(unsigned int  charOcorencyCounter[29])
{
	for (size_t i = 0; i < charOcorencyCounter_SIZE; i++)
	{
		if (i == 26)
			cout << "Character ' ' (space) occurred " << charOcorencyCounter[i] << " times." << endl;
		else if (i == 27)
			cout << "Punctuation characters occurred " << charOcorencyCounter[i] << " times." << endl;
		else if (i == 28)
			cout << "Other characters occurred " << charOcorencyCounter[i] << " times." << endl;
		else
			cout << "Character '" << static_cast<char>(i + 'A') << "' occurred " << charOcorencyCounter[i] << " times." << endl;
	}
}
