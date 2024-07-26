#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main() {
	map<string, string> names;

	names["Name1 Surname1"] = "123456";
	names["Name2 Surname2"] = " 987655";
        names["Name3 Surname3"] = "765379";
	
cout << "Names " << setw(13) << "&" << setw(14) << "Numbers" << endl;
	
	map <string, string>::iterator i;
	for (i = names.begin(); i != names.end(); i++) {  
		cout << setw(12) << (*i).first << "  " << setw(16) << (*i).second << "\n";
	}	


	return 0;
}

/*for, for(auto element: names) {cout << element.first << element.second;} */
