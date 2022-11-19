#pragma warning(disable : 4996)

#include <iostream>  
#include <ctime>  

using namespace std;

void time(int* y, int* m, int* d)
{
        time_t ttime = time(0);
        tm* local_time = localtime(&ttime);

        *y = 1900 + local_time->tm_year;
        *m = 1 + local_time->tm_mon;
        *d = local_time->tm_mday;
        


        /*
        cout << "Year: " << year << endl;
        cout << "Month: " << month << endl;
        cout << "Day: " << day << endl;
       */


      /*  Hours
      
      cout << "Time: " << 1 + local_time->tm_hour << ":";
      cout << 1 + local_time->tm_min << ":";
       cout << 1 + local_time->tm_sec << endl;

        */
    

}