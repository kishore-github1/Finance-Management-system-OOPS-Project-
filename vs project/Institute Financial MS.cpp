
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
#include"PayStudentFee.h"
#include"ManageFunds.h"


using namespace std;


void showMenu() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
	SetConsoleTextAttribute(hConsole, 3);
	cout << endl << setw(30) << " " << "**************************************\n\n";
	cout << setw(35) << " " << "CHANAKYA MANAGEMENT SYSTEM" << endl << endl;
	cout << setw(30) << " " << "**************************************\n\n\n\n";

	SetConsoleTextAttribute(hConsole, 4);
	cout << setw(35) << " " << "MAIN MENU\n" << endl;

	SetConsoleTextAttribute(hConsole, 14);

	cout << setw(30) << " " << "1. Insert Student\n" << endl;
	cout << setw(30) << " " << "2. Insert Staff\n" << endl;
	cout << setw(30) << " " << "3. Search\n" << endl;
	cout << setw(30) << " "<< "4. Update\n" << endl;
	cout << setw(30) << " " << "5. Pay Student Fee\n" << endl;
	cout << setw(30) << " " << "6. Modify Funds\n" << endl;
	cout << setw(30) << " " << "7. Exit\n" << endl;
	cout << setw(30) << " " << "Enter here:";

}

int main()
		{
			

				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

				MYSQL* con = nullptr;
				MYSQL* connected;
				
				connected = connect(con);
		


				int choice,status=0;
				status=login(connected); 


				
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
							system("cls");
							ManageFunds(connected);
							Sleep(3000);
							showMenu();
							break;
						case 7:
							return 0;
						}


					}
				}
				else cout << "Login Credentials are Wrong" << endl;

				
	return 0;
}
