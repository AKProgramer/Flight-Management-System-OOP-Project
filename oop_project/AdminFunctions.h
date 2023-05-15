#pragma once
void adminFunRouteChange(string airportName, Flight& f1, Flight& f2, Flight& f3, Flight& f4, Flight& f5) {
	string changeRoute;
	int  routeCChoice = 0;
	while (routeCChoice != 6) {
		cout << "There are 5 Flights in " << airportName << " Airport." << endl;
		cout << "1 - The current route of Flight 1 is " << f1.getRoute() << endl;
		cout << "2 - The current route of Flight 2 is " << f2.getRoute() << endl;
		cout << "3 - The current route of Flight 3 is " << f3.getRoute() << endl;
		cout << "4 - The current route of Flight 4 is " << f4.getRoute() << endl;
		cout << "5 - The current route of Flight 5 is " << f5.getRoute() << endl;
		cout << "Press 6 to exit" << endl;
		cout << "Route of which Flight do You want to change" << endl;
		cin >> routeCChoice;
		cin.ignore();
		if (routeCChoice == 1) {
			cout << "What You want to Set in the route of flight 1" << endl;
			getline(cin, changeRoute);
			f1.setRoute(changeRoute);
		}
		else if (routeCChoice == 2) {
			cout << "What You want to Set in the route of flight 2" << endl;
			getline(cin, changeRoute);
			f2.setRoute(changeRoute);
		}
		else if (routeCChoice == 3) {
			cout << "What You want to Set in the route of flight 3" << endl;
			getline(cin, changeRoute);
			f3.setRoute(changeRoute);
		}
		else if (routeCChoice == 4) {
			cout << "What You want to Set in the route of flight 4" << endl;
			getline(cin, changeRoute);
			f4.setRoute(changeRoute);
		}
		else if (routeCChoice == 5) {
			cout << "What You want to Set in the route of flight 5" << endl;
			getline(cin, changeRoute);
			f5.setRoute(changeRoute);
		}
		else if (routeCChoice == 6) {
			cout << "Exit..." << endl;
			break;
		}
	}
}
void adminFunPassengerRestrict(string airportName, Flight& f1, Flight& f2, Flight& f3, Flight& f4, Flight& f5) {
	int seatCChoice = 0, seatTChoice = 0, changeS = 0;
	while (seatCChoice != 6) {
		cout << "There are 5 Flights in " << airportName << " Airport." << endl;
		cout << "For Flight 1\nEconomic Class Seat : " << f1.getLSeats() << "\nBussiness Class Seat : " << f1.getBSeats() << "\n";
		cout << "For Flight 2\nEconomic Class Seat : " << f2.getLSeats() << "\nBussiness Class Seat : " << f2.getBSeats() << "\n";
		cout << "For Flight 3\nEconomic Class Seat : " << f3.getLSeats() << "\nBussiness Class Seat : " << f3.getBSeats() << "\n";
		cout << "For Flight 4\nEconomic Class Seat : " << f4.getLSeats() << "\nBussiness Class Seat : " << f4.getBSeats() << "\n";
		cout << "For Flight 5\nEconomic Class Seat : " << f5.getLSeats() << "\nBussiness Class Seat : " << f5.getBSeats() << "\n";
		cout << "Press 1 to Change Seats in Flight 1" << endl;
		cout << "Press 2 to Change Seats in Flight 2" << endl;
		cout << "Press 3 to Change Seats in Flight 3" << endl;
		cout << "Press 4 to Change Seats in Flight 4" << endl;
		cout << "Press 5 to Change Seats in Flight 5" << endl;
		cout << "Press 6 to exit" << endl;
		cin >> seatCChoice;
		if (seatCChoice == 1) {
			while (seatTChoice != 3) {
				cout << "Press 1 to change Seats in Economic Class" << endl;
				cout << "Press 2 to change Seats in Business Class" << endl;
				cout << "Press 3 to exit" << endl;
				cin >> seatTChoice;

				if (seatTChoice == 1) {
					cout << "How many Seats do you want to set in Economic Class" << endl;
					cin >> changeS;
					f1.setLSeats(changeS);
				}
				else if (seatTChoice == 2) {
					cout << "How many Seats do you want to set in Bussiness Class" << endl;
					cin >> changeS;
					f1.setBSeats(changeS);
				}
				else if (seatTChoice == 3) {
					cout << "Exit..." << endl;
					break;
				}
			}
		}
		else if (seatCChoice == 2) {
			while (seatTChoice != 3) {
				cout << "Press 1 to change Seats in Economic Class" << endl;
				cout << "Press 2 to change Seats in Business Class" << endl;
				cout << "Press 3 to exit" << endl;
				cin >> seatTChoice;

				if (seatTChoice == 1) {
					cout << "How many Seats do you want to set in Economic Class" << endl;
					cin >> changeS;
					f2.setLSeats(changeS);
				}
				else if (seatTChoice == 2) {
					cout << "How many Seats do you want to set in Bussiness Class" << endl;
					cin >> changeS;
					f2.setBSeats(changeS);
				}
				else if (seatTChoice == 3) {
					cout << "Exit..." << endl;
					break;
				}
			}
		}
		else if (seatCChoice == 3) {
			while (seatTChoice != 3) {
				cout << "Press 1 to change Seats in Economic Class" << endl;
				cout << "Press 2 to change Seats in Business Class" << endl;
				cout << "Press 3 to exit" << endl;
				cin >> seatTChoice;

				if (seatTChoice == 1) {
					cout << "How many Seats do you want to set in Economic Class" << endl;
					cin >> changeS;
					f3.setLSeats(changeS);
				}
				else if (seatTChoice == 2) {
					cout << "How many Seats do you want to set in Bussiness Class" << endl;
					cin >> changeS;
					f3.setBSeats(changeS);
				}
				else if (seatTChoice == 3) {
					cout << "Exit..." << endl;
					break;
				}
			}
		}
		else if (seatCChoice == 4) {
			while (seatTChoice != 3) {
				cout << "Press 1 to change Seats in Economic Class" << endl;
				cout << "Press 2 to change Seats in Business Class" << endl;
				cout << "Press 3 to exit" << endl;
				cin >> seatTChoice;

				if (seatTChoice == 1) {
					cout << "How many Seats do you want to set in Economic Class" << endl;
					cin >> changeS;
					f4.setLSeats(changeS);
				}
				else if (seatTChoice == 2) {
					cout << "How many Seats do you want to set in Bussiness Class" << endl;
					cin >> changeS;
					f4.setBSeats(changeS);
				}
				else if (seatTChoice == 3) {
					cout << "Exit..." << endl;
					break;
				}
			}
		}
		else if (seatCChoice == 5) {
			while (seatTChoice != 3) {
				cout << "Press 1 to change Seats in Economic Class" << endl;
				cout << "Press 2 to change Seats in Business Class" << endl;
				cout << "Press 3 to exit" << endl;
				cin >> seatTChoice;

				if (seatTChoice == 1) {
					cout << "How many Seats do you want to set in Economic Class" << endl;
					cin >> changeS;
					f5.setLSeats(changeS);
				}
				else if (seatTChoice == 2) {
					cout << "How many Seats do you want to set in Bussiness Class" << endl;
					cin >> changeS;
					f5.setBSeats(changeS);
				}
				else if (seatTChoice == 3) {
					cout << "Exit..." << endl;
					break;
				}
			}
		}
		else if (seatCChoice == 6) {
			cout << "Exit..." << endl;
			break;
		}
	}
}
void adminFunFlightSchedule(string airportName, Flight& f1, Flight& f2, Flight& f3, Flight& f4, Flight& f5) {
	int setArrTime = 0, setDepTime = 0, fSCChoice = 0;
	while (fSCChoice != 6) {
		cout << "There are 5 Flights in this airport" << endl;
		cout << "For Flight 1\nDeparture Time : " << f1.getDepartureTime() << "\nArrival Time : " << f1.getArivalTime() << "\n";
		cout << "For Flight 2\n Departure Time : " << f2.getDepartureTime() << "\nArrival Time : " << f2.getArivalTime() << "\n";
		cout << "For Flight 3\nDeparture Time : " << f3.getDepartureTime() << "\nArrival Time : " << f3.getArivalTime() << "\n";
		cout << "For Flight 4\nDeparture Time : " << f4.getDepartureTime() << "\nArrival Time : " << f4.getArivalTime() << "\n";
		cout << "For Flight 5\nDeparture Time : " << f5.getDepartureTime() << "\nArrival Time : " << f5.getArivalTime() << "\n";
		cout << "Press 1 to Change Flight Schedule of Flight 1" << endl;
		cout << "Press 2 to Change Flight Schedule of Flight 2" << endl;
		cout << "Press 3 to Change Flight Schedule of Flight 3" << endl;
		cout << "Press 4 to Change Flight Schedule of Flight 4" << endl;
		cout << "Press 5 to Change Flight Schedule of Flight 5" << endl;
		cout << "Press 6 to exit" << endl;
		cout << "Enter Your Choice : ";
		cin >> fSCChoice;
		if (fSCChoice == 1) {
			cout << "What is Arrival time of Flight 1" << endl;
			cin >> setArrTime;
			cout << "What is the Departure time of Flight 1" << endl;
			cin >> setDepTime;
			f1.setArrivalTime(setArrTime);
			f1.setDepartureTime(setDepTime);

		}
		else if (fSCChoice == 2) {
			cout << "What is Arrival time of Flight 1" << endl;
			cin >> setArrTime;
			cout << "What is the Departure time of Flight 1" << endl;
			cin >> setDepTime;
			f2.setArrivalTime(setArrTime);
			f2.setDepartureTime(setDepTime);
		}
		else if (fSCChoice == 3) {
			cout << "What is Arrival time of Flight 1" << endl;
			cin >> setArrTime;
			cout << "What is the Departure time of Flight 1" << endl;
			cin >> setDepTime;
			f3.setArrivalTime(setArrTime);
			f3.setDepartureTime(setDepTime);
		}
		else if (fSCChoice == 4) {
			cout << "What is Arrival time of Flight 1" << endl;
			cin >> setArrTime;
			cout << "What is the Departure time of Flight 1" << endl;
			cin >> setDepTime;
			f4.setArrivalTime(setArrTime);
			f4.setDepartureTime(setDepTime);
		}
		else if (fSCChoice == 5) {
			cout << "What is Arrival time of Flight 1" << endl;
			cin >> setArrTime;
			cout << "What is the Departure time of Flight 1" << endl;
			cin >> setDepTime;
			f5.setArrivalTime(setArrTime);
			f5.setDepartureTime(setDepTime);
		}
		else if (fSCChoice == 6) {
			cout << "Exit..." << endl;
			break;
		}
	}
}
void adminFunctions(string airportName, Flight& f1, Flight& f2, Flight& f3, Flight& f4, Flight& f5,
	Flight& f6, Flight& f7, Flight& f8, Flight& f9, Flight& f10, Flight& f11, Flight& f12, Flight& f13, Flight& f14, Flight& f15
) {
	int adminFunChoice = 0;
	while (adminFunChoice != 4) {
		cout << "Press 1 to Add new routes for local and international flights" << endl;
		cout << "Press 2 to Restrict the number of passengers in a plane" << endl;
		cout << "Press 3 to change the schedule of time" << endl;
		cout << "Press 4 to exit" << endl;
		cout << "Enter Your Choice : ";
		cin >> adminFunChoice;
		if (adminFunChoice == 1) {
			if (airportName == "islamabad") {
				adminFunRouteChange(airportName, f1, f2, f3, f4, f5);
			}

			else if (airportName == "karachi") {
				adminFunRouteChange(airportName, f6, f7, f8, f9, f10);
			}
			else if (airportName == "lahore") {
				adminFunRouteChange(airportName, f11, f12, f13, f14, f15);
			}
		}
		else if (adminFunChoice == 2) {
			if (airportName == "islamabad") {
				adminFunPassengerRestrict(airportName, f1, f2, f3, f4, f5);
			}

			else if (airportName == "karachi") {
				adminFunPassengerRestrict(airportName, f6, f7, f8, f9, f10);
			}
			else if (airportName == "lahore") {
				adminFunPassengerRestrict(airportName, f11, f12, f13, f14, f15);
			}
		}
		// Admin 3rd Function which is admin can change the flight schedule
		else if (adminFunChoice == 3) {
			if (airportName == "islamabad") {
				adminFunFlightSchedule(airportName, f1, f2, f3, f4, f5);
			}

			else if (airportName == "karachi") {
				adminFunFlightSchedule(airportName, f6, f7, f8, f9, f10);
			}
			else if (airportName == "lahore") {
				adminFunFlightSchedule(airportName, f11, f12, f13, f14, f15);
			}
		}

	}
}