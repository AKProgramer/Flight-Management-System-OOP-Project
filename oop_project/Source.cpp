#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<iomanip>
#include"LoginAndRegistration.h"
#include"FlightSchedule .h"
#include"Booking.h"
#include"AdminFunctions.h"
#include"passengerFunctions.h"
using namespace std;
bool isValidPassword(const string& password) {
	// Check if password is at least 8 characters long
	int len = password.length();
	if (len < 8) {
		return false;
	}

	bool has_uppercase = false;
	bool has_lowercase = false;
	bool has_digit = false;
	bool has_special = false;
	for (int i = 0; i < len; i++) {
		// Check if character is an uppercase letter
		if (password[i] >= 'A' && password[i] <= 'Z') {
			has_uppercase = true;
		}
		// Check if character is a lowercase letter
		else if (password[i] >= 'a' && password[i] <= 'z') {
			has_lowercase = true;
		}
		// Check if character is a digit
		else if (password[i] >= '0' && password[i] <= '9') {
			has_digit = true;
		}
		// Check if character is a special character
		else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '_' || password[i] == '+' || password[i] == '=' || password[i] == '[' || password[i] == ']' || password[i] == '{' || password[i] == '}' || password[i] == ';' || password[i] == ':' || password[i] == '"' || password[i] == '\'' || password[i] == '\\' || password[i] == '|' || password[i] == ',' || password[i] == '.' || password[i] == '<' || password[i] == '>' || password[i] == '/' || password[i] == '?') {
			has_special = true;
		}
	}

	// Check if password contains at least one uppercase letter, one lowercase letter, one digit, and one special character
	if (!has_uppercase || !has_lowercase || !has_digit || !has_special) {
		return false;
	}

	return true;
}
int main() {
	//For Login And Registration
	string userName, password, cnic, firstName, lastName, emailAdress;
	int age = 0, menuChoice = 0, noOfDep = 0;
	char hidePass = '\0';
	//For Admin Functions
	string changeRoute;
	int adminFunChoice = 0, cityAdminChoice = 0, routeCChoice = 0, seatCChoice = 0, seatTChoice = 0, changeS = 0;
	int setArrTime = 0, setDepTime = 0, fSCChoice = 0;
	//For Flight Schedule
	string airPName, destination, arivTime, deptTime, route, fType, duration;
	int localS = 0, businessS = 0;
	// Passenger Functions
	int passFunChoice=0,dep=0, planeChoice=0,flightNo=0, details=0;
	//FLight Booking
	int airChoice;
	string passName,seatType,mobileNo;
	int seatNo = 0, sClassChoice=0;
	// password
	int attempts = 3;
	string validPass;
	// All Flights are declared here
// Islamabad Flights
	Flight f1("ISB-DXB", "Dubai", "1:00 AM", 3, "10:00 AM", "Economy", 50, 10);
	Flight f2("LHE-LHR", "London", "8:00 AM", 9, "3:00 PM", "Business", 50, 10);
	Flight f3("KHI-IST", "Istanbul", "9:00 AM", 5, "5:00 PM", "Economy", 50, 10);
	Flight f4("Islamabad to Dubai", "SoudiArabia", "10:00 PM", 4, "8:00 PM", "International", 50, 10);
	Flight f5("Islamabad to Peshawar", "Peshawar", "3:00 PM", 1, "2:00 PM", "Domestic", 50, 10);
	// Karachi Flights
	Flight f6("JFK-LAX", "Los Angeles", "10:00 AM", 5, "8:00 AM", "First", 50, 10, "Karachi International Airport");
	Flight f7("HND-PEK", "Beijing", "10:00 AM", 4, "6:00 AM", "Economy", 50, 10, "Karachi International Airport");
	Flight f8("Faisalabad to Karachi", "Karachi", "4:00 PM", 2, "2:00 PM", "Domestic", 50, 10, "Karachi International Airlines");
	Flight f9("Karachi to Lahore", "Lahore", "6:00 PM", 3, "3:00 PM", "Domestic", 50, 10, "Karachi International Airlines");
	Flight f10("Quetta to Lahore", "Lahore", "3:00 PM", 2, "1:00 PM", "Domestic", 50, 10, "Karachi International Airlines");
	// Lahore Flights
	Flight f11("Lahore to Islamabad", "Islamabad", "1:00 PM", 2, "10:00 AM", "Domestic", 50, 10, "Lahore International Airlines");
	Flight f12("Lahore to Karachi", "Karachi", "5:00 PM", 3, "2:00 PM", "Domestic", 50, 10, "Lahore International Airlines");
	Flight f13("Lahore to London", "London", "10:00 PM", 9, "6:00 PM", "International", 50, 10, "Lahore International Airlines");
	Flight f14("Peshawar to Dubai", "Dubai", "8:00 PM", 5, "5:00 PM", "International", 50, 10, "Lahore International Airlines");
	Flight f15("Multan to Islamabad", "Islamabad", "11:00 AM", 1, "10:00 AM", "Domestic", 50, 10, "Lahore International Airlines");
	// Islamabad Planes
	Plane plane1(&f1, 1);
	Plane plane2(&f2, 1);
	Plane plane3(&f3, 1);
	Plane plane4(&f4, 1);
	Plane plane5(&f5, 1);
	// Karachi Planes
	Plane plane6(&f6, 1);
	Plane plane7(&f7, 1);
	Plane plane8(&f8, 1);
	Plane plane9(&f9, 1);
	Plane plane10(&f10, 1);
	// Lahore Planes
	Plane plane11(&f6, 1);
	Plane plane12(&f7, 1);
	Plane plane13(&f8, 1);
	Plane plane14(&f9, 1);
	Plane plane15(&f10, 1);
	Plane* isbPlanes[5] = { &plane1,&plane2,&plane3,&plane4,&plane5 };
	Plane* kriPlanes[5] = { &plane6,&plane7,&plane8,&plane9,&plane10 };
	Plane* lhrPlanes[5] = { &plane11,&plane12, &plane13, &plane14, &plane15 };
	cout <<setw(295)<< "Welcome to the NUCES Airline Flight System (NAFS), a comprehensive flight reservation"<<endl;
	cout<<setw(295)<<" system for the newly established airline operating in five major cities of Pakistan, "<<endl;
	cout<<setw(250)<<"including Islamabad, Lahore and Karachi." << endl;
	cout << setw(296) << "Our menu provides easy navigation to the full system, and after each step, users are \n";
	cout <<setw(280)<< " provided with a menu for the next process and a link to the main menu." << endl;
	while (menuChoice != 4) {
		cout << setw(280) << "/////////////////////////////////////////////////////////////" << endl;
		cout << setw(247) << "Press 1 for login" << endl;
		cout << setw(260) << "Press 2 for Admin Registration" << endl;
		cout << setw(265) << "Press 3 for Passenger Registration." << endl;
		cout << setw(257) << "Press 4 for flight details." << endl;
		cout << setw(247) << "Press 5 for exit." << endl;
		cout << setw(280) << "/////////////////////////////////////////////////////////////" << endl;
		cout << "Enter Your Choice : ";
		cin >> menuChoice;
		cin.ignore();
		system("cls");
		if (menuChoice==1) {
			cout << "---------------------Login--------------------------" << endl;
			char pass='\0';
			cout << "Enter User Name : ";
			getline(cin, userName);
			/*cout << "Enter Password : ";
			while ((pass = _getch()) != 13) {
				password.push_back(pass);
				cout << '*';
			}*/
			
			
    while (attempts > 0) {
        string password;
        cout << "Enter Password : ";
			while ((pass = _getch()) != 13) {
				password.push_back(pass);
				cout << '*';
			}
        if (isValidPassword(password)) {
            cout << "\nValid password!" << endl;
            break;
        } else {
            attempts--;
            cout << "\nInvalid password. Password must be 8 characters long and use at least one special character, uppercase letter, lowercase letter, and numeric digit." << endl;
            if (attempts > 0) {
                cout << "You have " << attempts << " attempts remaining." << endl;
            }
        }
    }

    if (attempts == 0) {
        cout << "You have exceeded the maximum number of attempts. Please try again later." << endl;
    }
			cout << endl;
			Login obj(userName, password);
			cout<<"---------------------------------------------" << endl;
			system("cls");
			if (obj.checkExistingUser()==1) {
				cout << "Welcome Ms Admin" << endl;
				adminFunctions(airPName, f1, f2, f3, f4, f5,f6, f7, f8, f9, f10, f11, f12, f13, f14, f15);
			}
			else if (obj.checkExistingUser() == 0) {
				cout <<setw(100)<< "You does not exist in our Record" << endl;
			}
			else if (obj.checkExistingUser() == 2) {
				cout << "Welcome Ms Passenger" << endl;
				cout << "Press 1 For Islamabad Passenger Registration\nPress 2 For Karachi Passenger Registration\nPress 3 For Lahore Passenger Registration" << endl;
				cout << "Enter Your Choice : ";
				cin >> airChoice;
				if (airChoice == 1) {
					passengerFunctions("Islamabad", isbPlanes);

				}
				else if (airChoice == 2) {

					passengerFunctions("Karachi", kriPlanes);
				}
				else if (airChoice == 3) {
					passengerFunctions("Lahore", lhrPlanes);
				}
			}
		}
		 if (menuChoice == 2) {
			cout << "------------Admin Registration Process-------------" << endl;
			cout << "Press 1 For Islamabad Admin Reiestration\nPress 2 For Karachi Admin Reiestration\nPress 3 For Lahore Admin Reiestration" << endl;
			cin >> cityAdminChoice;
			if (cityAdminChoice == 1) {
				airPName = "islamabad";
			}
			else if (cityAdminChoice == 2) {
				airPName = "karachi";
			}
			else {
				airPName = "lahore";
			}
			cin.ignore();
			cout << "Enter Admin User Name : ";
			getline(cin, userName);
			cout << endl;
			while (attempts > 0) {
				string password;
				cout << "Enter Password : ";
				while ((hidePass = _getch()) != 13) {
					password.push_back(hidePass);
					cout << '*';
				}
				if (isValidPassword(password)) {
					validPass = password;
					cout << "\nValid password!" << endl;
					break;
				}
				else {
					attempts--;
					cout << "\nInvalid password. Password must be 8 characters long and use at least one special character, uppercase letter, lowercase letter, and numeric digit." << endl;
					if (attempts > 0) {
						cout << "You have " << attempts << " attempts remaining." << endl;
					}
				}
			}

			if (attempts == 0) {
				cout << "You have exceeded the maximum number of attempts. Please try again later." << endl;
			}
			cout << endl;
			cout << "Enter Admin EmailAdress : ";
			getline(cin, emailAdress);
			cout << endl;
			cout << "Enter Admin CNIC : ";
			getline(cin, cnic);
			cout << endl;
			cout << "Enter First Name : ";
			getline(cin, firstName);
			cout << endl;
			cout << "Enter Last Name : ";
			getline(cin, lastName);
			cout << endl;
			cout << "Enter Admin Age : ";
			cin >> age;
			cout << endl;
			cout << validPass << endl;
			AdminRegistration registerAdmin(airPName, userName, validPass, firstName, lastName, emailAdress, cnic, age);
			adminFunctions(airPName, f1, f2, f3, f4, f5,
				f6, f7, f8, f9, f10, f11, f12, f13, f14, f15);
			cout << endl;
			cout << "-----------------------------------------------" << endl;
		}
		 else if (menuChoice == 3) {
			 cout << "------------Passenger Registration Process-------------" << endl;
			 cout << "Enter Passenger User Name : ";
			 getline(cin, userName);
			 cout << endl;
			 cout << "Enter Passenger Password : ";
			 while (attempts > 0) {
				 string password;
				 cout << "Enter Password : ";
				 while ((hidePass = _getch()) != 13) {
					 password.push_back(hidePass);
					 cout << '*';
				 }
				 if (isValidPassword(password)) {
					 validPass = password;
					 cout << "\nValid password!" << endl;
					 break;
				 }
				 else {
					 attempts--;
					 cout << "\nInvalid password. Password must be 8 characters long and use at least one special character, uppercase letter, lowercase letter, and numeric digit." << endl;
					 if (attempts > 0) {
						 cout << "You have " << attempts << " attempts remaining." << endl;
					 }
				 }
			 }

			 if (attempts == 0) {
				 cout << "You have exceeded the maximum number of attempts. Please try again later." << endl;
			 }
			 cout << endl;
			 cout << "Enter Passenger EmailAdress : ";
			 getline(cin, emailAdress);
			 cout << endl;
			 cout << "EnterPassenger CNIC : ";
			 getline(cin, cnic);
			 cout << endl;
			 cout << "Enter First Name : ";
			 getline(cin, firstName);
			 cout << endl;
			 cout << "Enter Last Name : ";
			 getline(cin, lastName);
			 cout << endl;
			 cout << "Enter Passenger Age : ";
			 cin >> age;
			 cout << endl;
			 cout << "Passenger have any dependents\npress 1 if have and press 2 if have not : ";
			 cin >> dep;
			 PassDependents* obj = nullptr;
			 if (dep == 1) {
				 cout << "How many Dependents are with You" << endl;
				 cin >> noOfDep;
				 cin.ignore();
				 obj = new PassDependents[noOfDep];
				 if (dep == 1) {
					 for (int i = 0; i < noOfDep; i++) {
						 cout << "Enter Dependent First Name : ";
						 getline(cin, obj[i].firstName);
						 cout << "Enter Dependent Last Name : ";
						 getline(cin, obj[i].lastName);
						 cout << "Enter Dependent Age : ";
						 cin >> obj[i].age;

					 }
				 }
			 }
			 else {
				 cout << "That's OK\n" << endl;
			 }
			 //cout << "Passenger Bank Account Information" << endl;
			
			 PassengerRegistration regPassenger(userName, validPass, firstName, lastName, emailAdress, cnic, age, obj, noOfDep);
			 cout << "Press 1 For Islamabad Passenger Registration\nPress 2 For Karachi Passenger Registration\nPress 3 For Lahore Passenger Registration" << endl;
			 cin >> airChoice;
			 if (airChoice == 1) {
				 passengerFunctions("Islamabad", isbPlanes);

			 }
			 else if (airChoice == 2) {

				 passengerFunctions("Karachi", kriPlanes);
			 }
			 else if (airChoice == 3) {
				 passengerFunctions("Lahore", lhrPlanes);
			 }
		 }
		 else if(menuChoice==4){
			 while (details != 4) {
				 cout << "Press 1 for Islamabad International Airlines" << endl;
				 cout << "Press 2 for Lahore International Airlines" << endl;
				 cout << "Press 3 for Karachi International Airlines" << endl;
				 cout << "Press 4 for exit" << endl;
				 cout << "Enter Your Choice : ";
				 cin >> details;
				 if (details == 1) {
					 for (int i = 0; i < 5; i++) {
						 isbPlanes[i]->showFlightDetails();
					 }
				 }
				 else if (details == 2) {
					 for (int i = 0; i < 5; i++) {
						 lhrPlanes[i]->showFlightDetails();
					 }
				 }
				 else if (details == 3) {
					 for (int i = 0; i < 5; i++) {
						 kriPlanes[i]->showFlightDetails();
					 }
				 }
			 }
		 }
		else if (menuChoice == 5) {
			cout << "Exit...";
			break;
		}
	}
	
	return 0;
}