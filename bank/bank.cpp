#include <iostream>

using namespace std;

class Client {
public:
	double arrears;
	double balance;
	double howmuch;
	double deposit;
	double payadept;
	double totaldept;
	
	void processors();
};

void Client::processors() {
	cout << "Action List: " << endl << "1)Withdraw Money" << endl << "2)Deposit Money" << endl << "3)Pay a Dept" << endl;
	cout << "Please select 1, 2 or 3." << endl << endl;

	string command;
	cout << "What do you want to do? ";
	cin >> command;

	int result;
	cout << "How much money do you have? ";
	cin >> result;

	if (command == "1"){
		cout << "How much money do you want do withdraw from the bank? ";
		cin >> howmuch;
		if (howmuch >= 0){
			if (howmuch <= result) {
				result = result-howmuch;
				cout << "Your remaining balance: " << result << std::endl ; 
			}
			else {
				cout << "There is not enough money in your ban account." << endl;
			} 
		}
		else {
			cout << "The process is invalid. Please try again.";
		}
	}
	else if (command == "2"){
		cout << "How much money do you want to deposit to the bank? ";
		cin >> deposit;
		 if (deposit > 0){
			result = result + deposit;
			cout << "Your sum of balance: "<< result <<endl;
		 }
		 else {
		 	cout << "The process is invalid. Please try again.";
		 }
	}

	else if (command == "3"){
		cout << "How much do you owe to the bank? ";
		cin >> totaldept;
		cout << "How much money do you want do pay a dept to the bank: ";
		cin >> payadept;
		if (payadept > 0){
			result = result-payadept;
			cout << "Money remaining in your bank account: "<< result << endl; 
			totaldept -= payadept;
			cout << "Money remaining debt to the bank: " << totaldept << endl;
		}
		else {
			cout << "The process s invalid. Please try again.";	
		}
	}

}

int main(void) {
	Client kisi;
	kisi.processors();
	
	return 0;
}
