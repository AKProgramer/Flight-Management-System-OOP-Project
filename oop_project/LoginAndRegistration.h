#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include<string>
class Login{
protected:
	string userName;
	string password;
	string checkUserName;
	string checkPassword;
	ifstream fin;
public:
	Login() {
		userName = "";
		password = "";
		checkUserName = "";
		checkPassword = "";
	}
	Login(string userName, string password) {
		this->userName = userName;
		this->password = password;
		checkUserName = "";
		checkPassword = "";
	}
	int checkExistingUser() {
		string arr[] = { "Admin UserName And Password.txt","Passenger UserName And Password.txt" };
		for (int i = 0; i < 2; i++) {
			fin.open(arr[i]);
			if (!fin.is_open()) {
				cout << "Error in File Opening" << endl;
			}
			else {
				while (getline(fin, checkUserName) && getline(fin, checkPassword)) {
					if (checkUserName == userName && checkPassword == password) {
						fin.close();
						return i + 1; // return 1 for admin file, 2 for passenger file
					}
				}
				fin.close();
			}
		}
		return 0; // return 0 if no match found in either file
	}

	
};
class AdminRegistration : protected Login{
	string airPortName;
	string firstName;
	string lastName;
	string emailAdress;
	string cnic;
	static int nextId;
	int id;
	int age;
	ofstream foutUP;
public:
	AdminRegistration() {
		airPortName = "";
		firstName = "";
		lastName = "";
		emailAdress = "";
		cnic = "";
		id = nextId++;
		age = 0;
		foutUP.open("Admin UserName and Password.txt",ios::trunc);
	}
	AdminRegistration(string aPName,string uName, string password,string fName,string lName, string eAdress,string cnic, int age) :Login(uName, password) {
		airPortName = aPName;
		firstName = fName;
		lastName = lName;
		emailAdress = eAdress;
		this->cnic = cnic;
		this->age = age;
		id = nextId++;
		foutUP.open("Admin UserName And Password.txt", ios::trunc);
		if (foutUP.is_open()) {
			foutUP << userName << endl;
			foutUP << password<<endl;
		}
		else {
			cout << "File does not open please check it!" << endl;
		}
	}
	~AdminRegistration() {
		foutUP.close();
	}
};
int AdminRegistration::nextId = 1;
struct PassDependents {
	string firstName;
	string lastName;
	int age=0;
};
class PassengerRegistration : protected Login{
	string firstName;
	string lastName;
	string emailAdress;
	string cnic;
	static int nextId;
	int id;
	int age;
	PassDependents* dependents;
	int noOfDependents;
	ofstream foutUP;
public:
	PassengerRegistration() {
		firstName = "";
		lastName = "";
		emailAdress = "";
		cnic = "";
		id = nextId++;
		age = 0;
		noOfDependents = 0;
		dependents = new PassDependents[noOfDependents];
		dependents->firstName = "";
		dependents->lastName = "";
		dependents->age = 0;
	}
	PassengerRegistration(string uName, string password, string fName, string lName, string eAdress, string cnic, int age,PassDependents* passD,int noOfD) :Login(uName, password) {
		firstName = fName;
		lastName = lName;
		emailAdress = eAdress;
		this->cnic = cnic;
		this->age = age;
		id = nextId++;
		noOfDependents = noOfD;
		dependents = passD;
		foutUP.open("Passenger UserName And Password.txt", ios::trunc);
		if (foutUP.is_open()) {
			foutUP << userName<<endl;
			foutUP << password<<endl;
		}
		else {
			cout << "File does not open kindly check it!" << endl;
		}
		foutUP.close();
		
	}
	

};
int PassengerRegistration::nextId = 1;