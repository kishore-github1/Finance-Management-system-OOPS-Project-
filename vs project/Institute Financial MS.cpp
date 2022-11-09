#include <iostream>
#include <conio.h>
#include<windows.h>
#include<mysql.h>
#include<sstream>
#include "connection.h"
#include "login.h"
#include"insert.h"
#include"search.h"
#include"update.h"


using namespace std;



int main()
		{
				MYSQL* con = nullptr;
				MYSQL* connected;
				connected = connect(con);
			//	staff_insert(connected);
			//	student_insert(connected);
			//	login(connected);
			//	search(connected);
				update(connected);


	return 0;
}
