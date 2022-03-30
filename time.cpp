#include <iostream>
#include <ctime>

using namespace std;

struct Date
{
 int day; // day of month from 1 to 31
 int month; // month of year from 0 to 11
 int year; // year since 1900
 int hrs;
 int min;
 int sec;
}

Date getCurrentDate()
{
	Date Cur;
	time_t tt;
	time(&tt);
	tm TM = *localtime(&tt);
	
	Cur.year = TM.tm_year + 1900;
	Cur.month = TM.tm_mon + 1;
	Cur.day = TM.tm_mday;
	Cur.hrs = TM.tm_hour;
	Cur.min = TM.tm_min;
	Cur.sec = TM.tm_sec;
}

void add_year(Node_year*& ph_year, string year_name, Node_year*& current_year)
{
	Date Start;
	time_t tt;
	time (&tt)
	
	tm TM = *localtime(%tt);
	
	Start.year = TM.tm_year + 1900;
	Start.month = TM.tm_mon +1;
	Start.day = TM.tm_mday;
	Start.hrs = TM.tm_hour;
	Start.min = TM.tm_min;
	Start.sec = TM.tm_sec;
}
bool compareDate(Date Start, Date *Cur)
{
	if (Cur.year != Start.year)
	   return 0;
	else (Cur.year - Start.year == 0)
	{
		if(Cur.month < Start.month)
		   return 0;
		else if (Cur.month == Start.month)
		{
			if (Cur.day - Start.day < 0)
			   return 0;
			else if (Cur.day - Start.day == 0)
			{
               	if (Cur.hrs - Start.hrs < 0)
			       return 0;
			    else if (Cur.hrs == Start.hrs)
			    {  
				   if (Cur.min - Start.min < 0)
			           return 0;
			       else if (Cur.min - Start.min == 0)
			       {
					   if (Cur.sec - Start.sec <= 0)
			               return 0;
			           else 
			               return 1;
			       }
				   else if (0 < Cur.min - Start.min < 60) 
				        return 1; 
			    }
			    else if (0 < Cur.hrs - Start.hrs < 24)
			       return 1;
			}
			else if (0 < Cur.day - Start.day < 31)
			   return 1;
		}
		else if (0 < Cur.month - Start.month < 2)
		   return 1;
	}	
}
