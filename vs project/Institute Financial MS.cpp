#include <iostream>
#include <conio.h>
#include<windows.h>
#include<mysql.h>
#include<sstream>
#include "connection.h"
#include "login.h"
#include"insert.h"


using namespace std;



int main()
		{
				MYSQL* con = nullptr;
				MYSQL* connected;
				connected = connect(con);
			//	staff_insert(connected);
				student_insert(connected);
			//	login(connected);



	return 0;
}
