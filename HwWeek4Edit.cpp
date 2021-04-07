// Developer: Benjamin Foreman
// Date: 4/5/2021
// Description: Program that takes in a file from command line and counts vowel characters that it contains, then prints counts to console.
// Update: 4/6/2021: Added the counting of D, S, and T characters including lower case.

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int FORMAT_PADDING = 61;

int main(int argc, char* argv[])
{
	// The executable name and at least one argument?
	if (argc < 2)
	{
		std::cout << "Error with input agrs.." << std::endl;
		return 1;
	}

	// opening file using argument from command line with file name checking
	std::ifstream inFile;
	inFile.open(argv[1]);
	if (!inFile)
	{
		std::cout << "Error with file name.." << std::endl;
		return 1;
	}

	// top banner
	cout << setw(FORMAT_PADDING + 1) << setfill('*') << '\n'
		<< setw(49) << " Welcome to my Letter Count Program "
		<< setw(13) << '\n'
		<< setw(FORMAT_PADDING + 1) << '\n' << endl;

	// analyzing file message
	cout << "Analyzing file \'" << argv[1] << "\'..." << endl << endl;

	// loop through file and analyze each character
	char c;
	int a = 0;
	int e = 0;
	int i = 0;
	int o = 0;
	int u = 0;
	int d = 0;
	int s = 0;
	int t = 0;
	while (!inFile.eof() && inFile >> c)
	{
		switch (c)
		{
		case 'a':
		case 'A':
			a++;
			break;
		case 'e':
		case 'E':
			e++;
			break;
		case 'i':
		case 'I':
			i++;
			break;
		case 'o':
		case 'O':
			o++;
			break;
		case 'u':
		case 'U':
			u++;
			break;
		case 'd':
		case 'D':
			d++;
			break;
		case 's':
		case 'S':
			s++;
			break;
		case 't':
		case 'T':
			t++;
			break;
		default:
			break;
		}
	}

	// formatted output of vowel counts and a total of all vowels counted
	cout << left << setfill('.')
		<< setw(FORMAT_PADDING) << "The number A's: " << a << endl
		<< setw(FORMAT_PADDING) << "The number E's: " << e << endl
		<< setw(FORMAT_PADDING) << "The number I's: " << i << endl
		<< setw(FORMAT_PADDING) << "The number O's: " << o << endl
		<< setw(FORMAT_PADDING) << "The number U's: " << u << endl
		<< setw(FORMAT_PADDING) << "The number D's: " << d << endl
		<< setw(FORMAT_PADDING) << "The number S's: " << s << endl
		<< setw(FORMAT_PADDING) << "The number T's: " << t << endl
		<< setw(FORMAT_PADDING) << "The vowel count is: " << a + e + i + o + u << endl
		<< setw(FORMAT_PADDING) << "The count of letters is: " << a + e + i + o + u + d + s + t << endl;

	// close file and pause
	inFile.close();
	system("pause");
	return 0;
}