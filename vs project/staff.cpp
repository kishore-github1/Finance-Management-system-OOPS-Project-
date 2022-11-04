#include<iostream> 
#include "staff.h"

using namespace std;

void staff::create_staff() {
	cout << "Enter Id of staff" << endl;
	cin >> id;
	cout << "Enter Name of staff" << endl;
	cin >> name;
	cout << "Enter Total salary of staff" << endl;
	cin >> total_salary;
	cout << "Enter Provident Fund of staff" << endl;
	cin >> provident_fund;
	cout << "Enter Health insurance of staff" << endl;
	cin >> health_insurance;
	cout << "Enter Basic salary of staff" << endl;
	cin >> basic_salary;



}