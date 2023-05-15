#pragma once
#include<iostream>
#include"FlightSchedule .h"
using namespace std;
#include<string>
class Booking {
	string* bCPassName;
	string* lCPassName;
	Plane* ticket;
	int seatNo;
	string seatClass;
	string mobileNo;
	static int nextId;
	int id;
public:
	Booking(Plane* obj,int whichFlight, string passName = "", int sNo = 0, string mNo = "",string seatClass="local class") {
		lCPassName = new string[50];
		bCPassName = new string[10];
		seatNo = sNo;
		mobileNo = mNo;
		id = nextId++;
		this->seatClass = seatClass;
		if (seatClass == "local class") {
			//obj.getFlight()[whichFlight].changeSeatsInLC(1);
			obj->getFlight()[whichFlight].setAvailSInLC(1);
			obj->getFlight()->setSeatsInLC(seatNo);
			lCPassName[sNo] = passName;
		}
		else {
			//obj.getFlight()[whichFlight].changeSeatsInBC(1);
			obj->getFlight()[whichFlight].setAvailSInBC(1);
			obj->getFlight()->setSeatsInBC(seatNo);
			bCPassName[sNo] = passName;
		}
		ticket = obj;
	}
	
	void showTicketDetails() {
		cout << "-----------Ticket Details :----------------" << endl;
		//cout << "PassengerName : " << passengerName << endl;
		cout << "Seat No : " << seatNo+1 << endl;
		cout << "Ticket ID : AKP" << id <<"ID" << endl;
		if (seatClass == "local class") {
		cout <<"Ticket Price : "<< ticket->getFlight()->getSeatPriceInLC();
		}
	else {
		cout << "Ticket Price : " << ticket->getFlight()->getSeatPriceInBC();
	}
		cout << endl;
		cout << "-------------------------------------------" << endl;
}

	void showTicketDetailsForPass() {
		cout << "-----------Ticket Details :----------------" << endl;
		//cout << "PassengerName : " << passengerName << endl;
		cout << "Seat No : " << seatNo + 1 << endl;
		cout << "Ticket ID : AKP" << id << "ID" << endl;
		if (seatClass == "local class") {
			cout << "Ticket Price : " << ticket->getFlight()->getSeatPriceInLC();
		}
		else {
			cout << "Ticket Price : " << ticket->getFlight()->getSeatPriceInBC();
		}
		cout << endl;
		cout << "-------------------------------------------" << endl;
	}

	string* getbPassName() {
		return bCPassName;
	}
	string* getlPassName() {
		return lCPassName;
	}
};
int Booking::nextId = 1;