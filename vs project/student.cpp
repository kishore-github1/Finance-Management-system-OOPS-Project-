#include "student.h"
#include<iostream>
using namespace std;

void student::create_student() {
	cout << "Enter Id of student:" << endl;
	cin >> id;
	cout << "Enter Name of student:" << endl;
	cin >> name;
	cout << "Enter Tution fee of student:" << endl;
	cin >> tution_fee;
	cout << "Enter Hostel fee of student:" << endl;
	cin >> hostel_fee;
	cout << "Enter Caution deposit of student:" << endl;
	cin >> caution_deposit;
	cout << "Fee paid?\nEnter '0' or '1'" << endl;
	cin >> paid_fee;

}
