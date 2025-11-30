///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Leander Kieweg
// Date : 29. 11. 2025
// Description : Test Driver for the Textstatistics module
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Textstatistics.h"

using namespace std;

void PrintAnalyticsResult(const AnalysisResult& res)
{
	if (!res.success) {
		cout << "Error: Could not read file." << endl;
		return;
	}

	cout << "Text length: " << res.textLength << endl;

	if (res.textLength == 0) {
		return;
	}

	for (int i = 0; i < NUM_CATEGORIES; i++)
	{
		if (res.counts[i] == 0) {
			continue;
		}

		double percentage = (static_cast<double>(res.counts[i]) / res.textLength) * 100.0;

		if (i < 26) {
			cout << (char)('A' + i) << ": " << res.counts[i] << " (" << percentage << "%)" << endl;
		} else if (i == 26) {
			cout << "Spaces: " << res.counts[i] << " (" << percentage << "%)" << endl;
		} else if (i == 27) {
			cout << "Punctuation marks: " << res.counts[i] << " (" << percentage << "%)" << endl;
		} else {
			cout << "Others: " << res.counts[i] << " (" << percentage << "%)" << endl;
		}
	}
}

int main()
{
	AnalysisResult result = AnalyseText("../SampleText.txt");
	PrintAnalyticsResult(result);
	return 0;
}
