#include<mysql.h>
#include<iostream>
#include<iomanip>
#include<sstream>

using namespace std;

int login(MYSQL* con) {
    string usname;
    string psswd;
    // system("COLOR 0D");

    cout << setfill(' ') << setw(10) << endl;
    cout << "************************\n";
    cout << setfill(' ') << setw(20) << endl;
    cout << "LOGIN\n";
    cout << setfill(' ') << setw(10) << endl;
    cout << "************************\n";
    cout << endl << setfill(' ') << setw(15) << " ";
    cout << "Enter Login Credentials\n\n";
    cout << setw(15) << " " << "Enter Username: ";
    cin >> usname;
    cout << setw(15) << " " << "Enter Password: ";
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
                cout << "Welcome" << endl;
                return 1;
            }
            else {
                cout << "Credentials are wrong" << endl;
            }
        }
    }
    return 0;

}
