#include "student.h"
#include "member.h"
#include<iostream>
#include<sstream>
#include<Windows.h>
#include<iomanip>

using namespace std;

stringstream student::create_student() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	cout <<endl<< setw(30) <<" " << "FILL DETAILS" << endl;
	cout << setw(30) <<" " << "____________";
	SetConsoleTextAttribute(hConsole, 13);
	cout <<endl<<endl<< setw(20)<<" " << "Enter Id of student: ";
	SetConsoleTextAttribute(hConsole, 15);
	cin >> id;
	SetConsoleTextAttribute(hConsole, 13);
	cout << endl << setw(20) << " " << "Enter Name of student: ";
	SetConsoleTextAttribute(hConsole, 15);
	cin.ignore();
	getline(cin, name);
	SetConsoleTextAttribute(hConsole, 13);
	cout <<endl << setw(20) << " " << "Enter Tution fee of student: "  ;
	SetConsoleTextAttribute(hConsole, 15);
	cin >> tution_fee;
	SetConsoleTextAttribute(hConsole, 13);
	cout << endl << setw(20) << " " << "Enter Hostel fee of student: "  ;
	SetConsoleTextAttribute(hConsole, 15);
	cin >> hostel_fee;
	SetConsoleTextAttribute(hConsole, 13);
	cout << endl << setw(20) << " " << "Enter Caution deposit of student: "  ;
	SetConsoleTextAttribute(hConsole, 15);
	cin >> caution_deposit;
	SetConsoleTextAttribute(hConsole, 13);
	cout << endl << setw(20) << " " << "Fee paid?\t\tEnter 'Y' or 'N': "  ;
	SetConsoleTextAttribute(hConsole, 15);
	char fee;
	cin >> fee;
	cout << endl;
	if (fee == 'y' || fee == 'Y') paid_fee = 1;
	else paid_fee = 0;


	stringstream ss;
	ss << "INSERT INTO student (Id,Name,Tution_fee,Hostel_fee,Caution_deposit,paid_fee) VALUES ('" << id << "','" << name << "'," << tution_fee << "," << hostel_fee << "," <<caution_deposit << "," << paid_fee << ")";

	return ss;
}

