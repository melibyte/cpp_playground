#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std; 

int main(int argc, char *argv[])
{
	if (argc < 2) {
		cout << "usage : " << argv[0] << " [text file]" << "\n";
		return 0;
	}

	cout << "Opening " << argv[1] << "\n";
	ifstream file(argv[1]);

	if (file.is_open()) {
		string line;
		int words = 0;

		while (getline(file, line)) {
			stringstream ss(line);
			string word;

			while (ss >> word) {
				words++; 
			}
		}
		file.close();
		cout << "Total Words: " << words << endl;
	} else {
		cout << "Could not open file.\n";
	}

	return 0;
}
