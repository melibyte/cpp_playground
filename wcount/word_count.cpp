#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std; 

int main() {
	ifstream file("words.txt");

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
	}
	return 0;
}
