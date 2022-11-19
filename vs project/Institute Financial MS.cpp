#include <iostream>
#include <conio.h>
#include<windows.h>
#include<iomanip>
#include<mysql.h>
#include<sstream>
#include "connection.h"
#include "login.h"
#include"insert.h"
#include"search.h"
#include"update.h"
#include"time.h"
#include"paysalary.h"
#include"collectFee.h"
#include"PayStudentFee.h"


using namespace std;


void showMenu() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	
	cout << "\n\t\tCHANAKYA" << endl;
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\n\t\t1.Insert student\n\t\t2.Insert Staff" << endl;
	cout << "\t\t3.Search " << endl;
	cout << "\t\t4.Update " << endl;
	cout << "\t\t5.Pay Student Fee " << endl;
	cout << "\t\t6.Exit " << endl;
	cout << "Enter here:";

}

int main()
		{
				//To change colour of terminal

				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			//	SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);

				//end of code to change colour

				MYSQL* con = nullptr;
				MYSQL* connected;
				
				connected = connect(con);
			//	collectFee(connected);

			//	staff_insert(connected);
			//	student_insert(connected);
			//	login(connected);
			//	search(connected);
			//	update(connected);

			//	time();
				
			//	paysalary(connected);

				int choice,status=0;
				status=login(connected);
				cout << status<<endl; 


				
				if (status == 1) {
					showMenu();
					while (1) {


						cin >> choice;

						switch (choice) {
						case 1:
							system("cls");
							student_insert(connected);
							Sleep(3000);
							showMenu();
							break;

						case 2:
							system("cls");
							staff_insert(connected);
							Sleep(3000);
							showMenu();
							break;
						case 3:
							system("cls");
							search(connected);
							Sleep(3000);
							showMenu();
							break;

						case 4:
							system("cls");
							update(connected);
							Sleep(3000);
							showMenu();
							break;

						case 5:
							system("cls");
							PayStudentFee(connected);
							Sleep(3000);
							showMenu();
							break;

						case 6:
							return 0;
						}


					}
				}
				else cout << "Login Credentials are Wrong" << endl;

				
	return 0;
}
