#pragma once
class Airport {
	string name;
public:
	Airport(string name= "Islamabad InterNational AirLines") {
		this->name =name;
	}
	string getAirportName() {
		return name;
	}
};
class Flight: public Airport{
	string destination;
	string arivalTime;
	string departureTime;
	string route;
	string flightType;
	char* seatsInLC;
	char* seatsInBC;
	int duration;
	int availSInLC;
	int availSInBC;
	int lSeats;
	int bSeats;
	long double seatBPrice;
	long double seatLPrice;
public:
	Flight() {
		this->route = "";
		this->destination = "";
		this->arivalTime = "";
		this->departureTime = "";
		flightType = "";
		seatBPrice = 0;
		this->duration = 0;
		 availSInLC = 50;
		 availSInBC = 10;
		 for (int i = 0; i < lSeats; i++) {
			 seatsInLC[i] = 'A';
		 }
		 for (int i = 0; i < bSeats; i++) {
			seatsInBC[i] = 'A';
		 }
		 lSeats = 0;
		 bSeats = 0;
		seatsInLC = new char[lSeats];
		seatsInBC = new char[bSeats];
		seatBPrice = duration*20000;
		seatLPrice = duration * 10000;
	}
	Flight(string route, string destination, string arivalTime,int dur, string dTime, string flightType,int localSeats, int bSeats,string airpName= "Islamabad InterNational AirLines"):Airport(airpName) {
		this->destination = destination;
		this->arivalTime = arivalTime;
		this->departureTime = dTime;
		this->route = route;
		this->flightType = flightType;
		this->duration = dur;
		availSInLC = 50;
		availSInBC = 10;
		lSeats = localSeats;
		this->bSeats = bSeats;
		seatsInLC = new char[lSeats];
		seatsInBC = new char[bSeats];
		for (int i = 0; i < lSeats; i++) {
			seatsInLC[i] = 'A';
		}
		for (int i = 0; i < bSeats; i++) {
			seatsInBC[i] = 'A';
		}
		seatBPrice = duration * 20000;
		seatLPrice = duration * 10000;
	}
	void setArrivalTime(int arrivalTime) {
		this->arivalTime = arrivalTime;
	}
	void setDepartureTime(int dTime) {
		this->departureTime = dTime;
	}
	
	void setRoute(string route) {
		this->route = route;
	}

	void setFlightType(int flightType) {
		this->flightType = flightType;
	}

	string getDestination() const {
		return destination;
	}

	string getArivalTime() const {
		return arivalTime;
	}

	string getDepartureTime() const {
		return departureTime;
	}
	string getRoute() const {
		return route;
	}
	int getDuration() const {
		return duration;
	}

	string getFlightType() const {
		return flightType;
	}
	char* getSeatsInLC() const {
		return seatsInLC;
	}
	char* getSeatsInBC() const {
		return seatsInBC;
	}
	void setSeatsInLC(int index){
		seatsInLC[index] = 'N';
	}
	void setSeatsInBC(int index) {
		seatsInBC[index] = 'N';
	}
	void resetSeatsInLC(int index) {
		seatsInLC[index] = 'A';
	}
	void resetSeatsInBC(int index) {
		seatsInBC[index] = 'A';
	}
	int getAvailSInLC() const {
		return availSInLC;
	}
	int getAvailSInBC() const {
		return availSInBC;
	}
	void setAvailSInLC(int localC) {
		this->availSInLC -= localC;
	}
	void setAvailSInBC(int busiC) {
		this->availSInBC-=busiC;
	}
	void showSeatsInLC() {
		int count = 0;
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 5; j++) {
				cout <<seatsInLC[count]<<" ";
				count++;
				if (count == 50) {
					break;
				}
			}
			cout <<endl;
			if (count == 50) {
				break;
			}
		}
		cout << endl;
	}
	void showSeatsInBC() {
		for (int i = 0; i < bSeats; i++) {
			cout << seatsInBC[i] << "  ";
			if (i == 4) {
				cout << "   ";
			}
		}
		cout << endl;
	}
	long double getSeatPriceInLC() {
		return seatLPrice;
	}
	long double getSeatPriceInBC() {
		return seatBPrice;
	}
	int getLSeats() {
		return lSeats;
	}
	int getBSeats() {
		return bSeats;
	}
	void setLSeats(int seat) {
		lSeats = seat;
	}
	void setBSeats(int seat) {
		bSeats = seat;
	}
};
class Plane {
	Flight* flight;
	int noOfFlights;
	static int nextId;
	int id;
public:
	Plane() {
		id = nextId++;
		noOfFlights = 0;
		flight = new Flight[noOfFlights];
	}
	Plane(Flight* flight, int noOfF) {
		id = nextId++;
		this->noOfFlights = noOfF;
		this->flight = flight;
		int flag = false;
		for (int i = 0; i < noOfFlights; i++) {
			for (int j = 0; j < noOfFlights; j++) {
				if (flight[i].getAirportName() != flight[j].getAirportName()) {
					flag = true;
					}
			}
			
		}
		if (flag) {
			cout << "Flights must be from same city Airport no two flights with different airoplane airport can takeoff!" << endl;
			cout << "As it is an error due to which we can't proceed further Please check Your objects of plane class and set the airport Name" << endl;
			exit(0);
		}
	}
	void showFlightDetails() {
		cout << "Airport Name " << flight->getAirportName() << endl;
		for (int i = 0; i < noOfFlights; i++)
		{
			cout <<"The id of this plane is AKPLANE"<< id<<"P" << endl;
			cout << "-----------Flight Details:----------------" << endl;
    cout << "Destination: " <<flight[i].getDestination() << endl;
    cout << "Route: " << flight[i].getRoute() << endl;
    cout << "Departure Time: " << flight[i].getDepartureTime() << endl;
    cout << "Arrival Time: " << flight[i].getArivalTime() << endl;
    cout << "Duration: " << flight[i].getDuration() << endl;
    cout << "Seats Available in Local Class: " << flight[i].getAvailSInLC() << endl;
    cout << "Seats Available in Business Class: " << flight[i].getAvailSInBC() << endl;
    cout << "Flight Type : " << flight[i].getFlightType() << endl;
	cout << "Astimated Ticket Price For Local Class: " << flight[i].getSeatPriceInLC() << endl;
	cout << "Astimated Ticket Price For Bussiness Class: " << flight[i].getSeatPriceInBC() << endl;

		}
	}
	Flight* getFlight() {
		return flight;
	}
};
int Plane :: nextId = 1;