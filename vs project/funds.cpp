#include<iostream>
#include<sstream>
#include<string>
#include"fixedAssets.h"
#include"expFunds.h"
#include"funds.h"

using namespace std;

stringstream funds::createFund(int choice,string month) {

	stringstream ss;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);

	cout << "\nEnter Fund Value: ";
	SetConsoleTextAttribute(hConsole, 15);
	if (choice == 1) {		
		cin >> staff_pay;
		ss << "UPDATE expenditure_funds  SET staff_payments = " << staff_pay << "   WHERE Month= '" << month << "' ";
		return ss;
	}
	else if (choice == 2) {
		cin >> exp_on_projects;
		ss << "UPDATE expenditure_funds  SET expenditure_on_projects = " << exp_on_projects << "   WHERE Month= '" << month << "' ";
		return ss;
	}
	else if (choice == 3) {
		cin >> maintenance;
		ss << "UPDATE expenditure_funds  SET repairs_maintenance = " << maintenance << "   WHERE Month= '" << month << "' ";
		return ss;
	}
	else if (choice == 4) {
		cin >> other_expenses;
		ss << "UPDATE expenditure_funds  SET  other_expenses= " << other_expenses << "   WHERE Month= '" << month << "' ";
		return ss;
	}


	//*******FIXED ASSETS**********

	else if (choice == 5) {
		cin >> office_equipment;
		ss << "UPDATE fixed_assets SET office_equipment = " << office_equipment<<" WHERE Month = '" << month << "' ";
		return ss;
	}
	else if (choice == 6) {
		cin >> library;
		ss << "UPDATE fixed_assets SET library_books = " << library << "   WHERE Month= '" << month << "' ";
		return ss;
	}
	else if (choice == 7){
		cin >> sports;
		ss << "UPDATE fixed_assets SET sports_equipment = " << sports << "   WHERE Month= '" << month << "' ";
		return ss;
	}
	else if (choice == 8) {
		cin >> buildings;
		ss << "UPDATE fixed_assets SET buildings = " << buildings << "   WHERE Month= '" << month << "' ";
		return ss;
	}
	else cout<<"Wrong choice"<<endl;

}