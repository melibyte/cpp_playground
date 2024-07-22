#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int max_tickets = 50; 

struct Ticket {
	string departure;
	string arrival;
	string date;
	string time;
	int ticket_number;
	float price;
	bool cancel;
	string passenger_name;
} newTicket;

void get_info(Ticket tickets[], int &sayac) {
	ifstream file("tickets.txt");

	if (!file.is_open()) {
		cout << "File could not be opened." << endl;
		return;
	}

	while (sayac < max_tickets && !file.eof()) {
		file >> tickets[sayac].ticket_number;
		file >> tickets[sayac].departure;
		file >> tickets[sayac].arrival;
		file >> tickets[sayac].date;
		file >> tickets[sayac].time;
		file >> tickets[sayac].price;
		getline(file, tickets[sayac].passenger_name);
		tickets[sayac].cancel = false;
		sayac++;
	}

	file.close();
}

void list_tickets(Ticket tickets[], int sayac) {
	cout << endl << "---Ticket List---" <<endl << setfill('-') << "Ticket no:   " 
		<< "Departure:   " << "Arrival   " << "Date:   " 
		<< "Time:   " << "Passenger name:   " 
		<< "State:   " << endl << setfill(' ') << endl;

	for (int i=0 ; i < sayac ; i++) {
		cout << setw(5) << tickets[i].ticket_number << setw(15) 
		<< setw(15) <<  tickets[i].departure << setw(13) << tickets[i].arrival 
		<< setw(13) <<  tickets[i].date << setw(13) << tickets[i].time
		<< setw(11) << tickets[i].price << setw(15) << tickets[i].passenger_name;

		if (tickets[i].cancel) {
			cout << "It is cancelled." << endl;  
	       	}
		else {
			cout << "It is not cancelled." << endl;   
		}
	}
}

void get_ticket(Ticket tickets[], int &sayac) {

	if (sayac >= max_tickets) {
		cout << "Tickets are sold out." << endl;
		return;   
	}
	cout << "Passenger's name: ";
	getline(cin >> ws, newTicket.passenger_name);
	cout << "The place of departure: ";
	getline(cin >>ws, newTicket.departure);
	cout << "The place of arrival: ";
        getline(cin >>ws, newTicket.arrival);	
	cout << "Date: ";
	getline(cin >> ws, newTicket.date);
	cout << "Time: ";
	getline(cin >> ws, newTicket.time);

	newTicket.ticket_number = sayac+1;
	newTicket.cancel = false;

	tickets[sayac] = newTicket;
	sayac++;

	cout << "Ticket purchased. Have a good journey." << endl;


}

void cancel_ticket(Ticket tickets[], int sayac , int ticket_number) {
	for  (int i=0; i < sayac; ++i){
		if (tickets[i].ticket_number == ticket_number) {
			if (!tickets[i].cancel) {
				tickets[i].cancel = true;
				cout << "Ticket is cancelled." << endl;
				return;
			}
			else {
				cout << "The ticket is already had cancelled." << endl;
				return;
			}
		}
	}
	cout << "There is no ticket in this number." << endl;
}


int main() {
	Ticket tickets[max_tickets];
	int ticket_num = 0;
	get_info(tickets, ticket_num);

	int option;
	do {
		cout << endl << "Bus Ticket Application" << endl;
		cout << "1. List Tickts " << endl;
		cout << "2. Get Ticket " << endl;
		cout << "3. Cancel Ticket " << endl << endl;
		cout << "What do you want to do? Please write the number (1,2,3) of the transaction you want to perform: "; 
		cin >> option;

		switch (option) {
			case 1:
				list_tickets(tickets, ticket_num);
				break;
			case 2:
				cin.ignore();
				get_ticket(tickets, ticket_num);
				break;
			case 3:
				int cancel_tickett;
				cout << "Enter the ticket number to be cancelled: ";
				cancel_ticket(tickets, ticket_num, cancel_tickett);
				break;
			default:
				cout << "Invalid Selection" << endl;
				break;
		}
	} 
	while(option < 4 && option > 0);

	return 0;
}
