#include "morze.h"

void DecodeMorze(const string& DecodeString, vector<string>& DecodedVariants, const string& BuildString)
{
	string CopyBuildString = BuildString;
	if (DecodeString.empty() || DecodeString.length() == 0) {
		DecodedVariants.push_back(CopyBuildString);
		CopyBuildString = "";
	}
	else {
		for (auto& elem : Dictionary) {
			if (DecodeString.find(elem.first) == 0) {
				CopyBuildString.push_back(elem.second);
				string TempStrig = DecodeString.substr(elem.first.length());
				DecodeMorze(TempStrig, DecodedVariants, CopyBuildString);
				CopyBuildString.pop_back();
			}
		}
	}
}

