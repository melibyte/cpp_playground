#include <iostream>
#include <string>
#include <math.h>

using namespace std;

float calc_hypotenuse() {
	double hypotenuse;
	double height;
	double width;

	cout << "Please enter the side lengths of triangle: ";
	cin >> height;
	cin >> width;
	hypotenuse = hypot(height, width);
	cout << "Hypotenuse of triangle: " << hypotenuse << endl << endl;

	for (int i=0; i< height ; ++i) {
		for (int k=0; k < width; ++k) {
			if (k <= (i * width) / height) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}

	return hypotenuse;
}

int main() {
	calc_hypotenuse();
	cout << endl;
	return 0;
}
