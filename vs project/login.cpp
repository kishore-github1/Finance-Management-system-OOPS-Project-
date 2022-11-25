
#include<mysql.h>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<Windows.h>
#include<ctime>

using namespace std;


int login(MYSQL* con) {
    string usname;
    string psswd;

 


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3);
    cout << endl << setw(30) << " " << "**************************************\n\n";
    cout << setw(35)<<" " << "CHANAKYA MANAGEMENT SYSTEM" << endl << endl;
    cout << setw(30) << " " << "**************************************\n\n\n\n";
    SetConsoleTextAttribute(hConsole, 13);
    cout << setw(40)<<" " << "***LOGIN***\n\n";
    SetConsoleTextAttribute(hConsole, 7);
    cout << setw(30) <<" "<< "Enter Login Credentials\n\n";
    cout << setw(30) << " " << "Enter Username: ";
    cin >> usname; cout << endl;
    cout << setw(30) << " " << "Enter Password: ";
    cin >> psswd;


    MYSQL_RES* res;
    MYSQL_ROW  row;
    stringstream a;
    a << "SELECT * FROM login_system WHERE Username = '" << usname << "' ";
    string b = a.str();
    const char* query = b.c_str();

    if (!(mysql_query(con, query))) {

        res = mysql_store_result(con);

        while (row = mysql_fetch_row(res))
        {

            if (psswd == row[1]) {
                system("COLOR 02");
                Sleep(100);
                system("cls");
                cout <<endl<< endl << endl << setw(35) << " ";
                for (int i = 0; i < 7; i++) {
                    cout << "* ";

                    Sleep(200);
                }              
                cout << endl<< setw(38) << " " << "WELCOME" << endl;

                cout<< setw(35) << " ";
                for (int i = 0; i < 7; i++) {
                    cout << "* ";
                    Sleep(200);
                }
                Sleep(200);
                system("cls");
                return 1;
            }
            else {
                cout << "Credentials are wrong" << endl;
            }
        }
    }
    return 0;

}
