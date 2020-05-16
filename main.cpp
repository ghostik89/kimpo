#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <vector>
#include "morze.h"

using namespace std;


const string ERRORS_ARRAY[3] = {
	"Can't write results to file result.txt",
	"Incorrect fileway!",
	"Incorrect Morze message!"
};

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "rus");
	ifstream in;
	ofstream out("result.txt", ios_base::out | ios_base::trunc);
	
	if (!out.is_open()) {
		cout << ERRORS_ARRAY[0];
		return 0;
	}

	string MorzeString;
	string TempPath;
	if (argc > 1) {
		TempPath = argv[1];
	}
	else {
		cout << "Enter path for message in Morze\n";
		cin >> TempPath;
	}

	in.open(TempPath);
	if (!in.is_open()) {
		out << ERRORS_ARRAY[1];
		cout << ERRORS_ARRAY[1];
		return 0;
	}
	in >> MorzeString;

	if(!CheckStringForInvalidChar(MorzeString)){
		out << ERRORS_ARRAY[2];
		cout << ERRORS_ARRAY[2];
		return 0;
	}

	vector<string> Results;
	DecodeMorze(MorzeString, Results, "");
	std::ostream_iterator<std::string> output_iterator(out, "\n");
	std::copy(Results.begin(), Results.end(), output_iterator);
	cout << "Complete translate";

	return 0;
}