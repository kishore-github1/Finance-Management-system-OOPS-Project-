#include<mysql.h>
#include<iostream>
#include<sstream>

using namespace std;

void login(MYSQL* con) {
    string usname;
    string psswd;
    cout << "Enter Login Credentials" << endl;
    cout << "Enter Username: " << endl;
    cin >> usname;
    cout << "Enter Password: " << endl;
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
            }
            else {
                cout << "Credentials are wrong" << endl;
            }
        }
    }



}
