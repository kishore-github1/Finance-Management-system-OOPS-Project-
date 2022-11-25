#include<iostream> 
#include "staff.h"
#include "member.h"
#include<sstream>
#include<iomanip>

using namespace std;

stringstream staff::create_staff() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << endl << setw(30) << " " << "FILL DETAILS" <<endl;
	cout << setw(30) << " " << "____________"<<endl;
	SetConsoleTextAttribute(hConsole, 13);

	cout <<endl << setw(25) << " "<< "Enter Id of staff: " ;
	SetConsoleTextAttribute(hConsole, 15);

	cin >> id;
	SetConsoleTextAttribute(hConsole, 15);
	SetConsoleTextAttribute(hConsole, 13);

	cout << endl << setw(25) << " " << "Enter Name of staff: " ;

	SetConsoleTextAttribute(hConsole, 15);
	cin.ignore();
	getline(cin, name);
	SetConsoleTextAttribute(hConsole, 13);
	cout << endl << setw(25) << " " << "Enter Total salary of staff: ";

	SetConsoleTextAttribute(hConsole, 15);
	cin >> total_salary;
	SetConsoleTextAttribute(hConsole, 13);
	cout << endl << setw(25) << " " << "Enter Provident Fund of staff: " ;

	SetConsoleTextAttribute(hConsole, 15);
	cin >> provident_fund;
	SetConsoleTextAttribute(hConsole, 13);

	cout << endl << setw(25) << " " << "Enter Health insurance of staff: ";


	SetConsoleTextAttribute(hConsole, 15);
	cin >> health_insurance;
	SetConsoleTextAttribute(hConsole, 13);

	/*
	cout << endl << setw(25) << " " << "Enter Basic salary of staff: ";

	SetConsoleTextAttribute(hConsole, 15);
	cin >> basic_salary;
	*/
	basic_salary = total_salary - (provident_fund + health_insurance);

	stringstream ss;
	ss << "INSERT INTO staff (Id,Name,Total_salary,Provident_fund,Health_insurance,Basic_salary) VALUES ('" << id << "','" << name << "'," << total_salary << "," << provident_fund << "," << health_insurance << "," << basic_salary << ")";

	return ss;
}