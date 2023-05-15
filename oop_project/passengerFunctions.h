#pragma once
#include<string>
#include<iostream>
using namespace std;
#include"FlightSchedule .h"
#include"Booking.h"
// here i declare all passenger related functions
void passengerFunctions(string airportName, Plane* arr[5]) {
	cout << "Welcome to the " << airportName << " International Airport." << endl;
	int passFunChoice = 0, dep = 0, planeChoice, flightNo = 0;
	string passName, seatType, mobileNo;
	int seatNo = 0, sClassChoice;
	
	while (passFunChoice != 3) {

		cout << "Press 1 for flight reservation" << endl;
		cout << "Press 2 flight cancellation" << endl;
		cout << "Press 3 to exit" << endl;
		cout << "Enter Your Choice : ";
		cin >> passFunChoice;
		system("cls");
		if (passFunChoice == 1) {
			for (int i = 0; i < 5; i++) {
				arr[i]->showFlightDetails();
			}
			cout << setw(50) << "Which Plane You Want to go on" << endl;
			cout << setw(48) << "Press 1 for Plane id 1" << endl;
			cout << setw(48) << "Press 2 for Plane id 2" << endl;
			cout << setw(48) << "Press 3 for Plane id 3" << endl;
			cout << setw(48) << "Press 4 for Plane id 4" << endl;
			cout << setw(48) << "Press 5 for Plane id 5" << endl;
			cout << "Enter Your Choice : ";
			cin >> planeChoice;
			cin.ignore();
			system("cls");
			cout << setw(40) << "Ticket Booking Module" << endl<<endl;
			cout << "What is the Passenger Name : ";
			getline(cin, passName);
			cout << "What is the Passenger Mobile Number : ";
			getline(cin, mobileNo);
			cout << "In Which Flight You want to book the Ticket : ";
			cin >> planeChoice;
			cout << "\nWhich type of seat You want to Book\nPress 1 for business class\nPress 2 for Economic Class" << endl;
			cin >> sClassChoice;
			if (sClassChoice == 1) {
				arr[sClassChoice - 1]->getFlight()[0].showSeatsInBC();
				seatType = "business class";
			}
			else if (sClassChoice == 2) {
				arr[planeChoice - 1]->getFlight()[0].showSeatsInLC();
				seatType = "local class";
			}
			cout << "Which seat You want to Book" << endl;
			cin >> seatNo;
			Booking obj(arr[planeChoice - 1], 0, passName, seatNo-1, mobileNo, seatType);
			obj.showTicketDetails();
			arr[planeChoice - 1]->showFlightDetails();
			if (sClassChoice == 1) {
				arr[planeChoice - 1]->getFlight()[0].showSeatsInBC();
				seatType = "business class";
			}
			else if (sClassChoice == 2) {
				arr[planeChoice - 1]->getFlight()[0].showSeatsInLC();
				seatType = "local class";
			}

		}
	}
}