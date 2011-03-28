#include "cDate_t.h"
#include <time.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

/*****************
 * Static Members
 *****************/
int cDate_t::format = 1;

//Days in month i - 1 in non-Leap year
const int cDate_t::daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

const string cDate_t::dayNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const string cDate_t::months[] = { "January", "February", "March", "April", "May", "June", "July", "August",
									"September", "October", "November", "December"};


/*****************
 * CTORs and DTOR
 ****************/
cDate_t::cDate_t()
{
	time_t time_data;

	time( &time_data);
	time_info = localtime(&time_data);

	setDate_p(time_info->tm_mday, (time_info->tm_mon+1), (time_info->tm_year + 1900));
}

cDate_t::cDate_t( int day, int month, int year )
{
	setDate_p(day,month,year);
}

cDate_t::cDate_t( const cDate_t& d)
{
	setDate_p(d.getDay(),d.getMonth(),d.getYear());
}

cDate_t::~cDate_t()
{
	//TODO: do we need to release time_info?
}

/*************
 * Operators
 *************/

const cDate_t& cDate_t::operator=( const cDate_t& d)
{
	if (this != &d){
		day = d.getDay();
		month = d.getMonth();
		year = d.getYear();
	}

	return *this;
}

/****************
 * Public Methods
 ****************/

void cDate_t::setDate( int day, int month, int year)
{
	setDate_p(day,month,year);
}

void cDate_t::printDate() const
{
	printDate(format);
}

void cDate_t::printDate( int format ) const
{
	switch (format){

		case 1:
			cout << setfill('0');
			cout << setw(2) << getDay() << '/'
				 << getNameOfMonth().substr(0, 3) << '/'
				 << getYear() << endl;
			break;
		case 2: //European
			cout << setfill('0');
			cout << setw(2) << getDay() << '/'
				 << setw(2) << getMonth() << '/'
				 << getYear() << "	European"
				 << endl;
			break;

		case 3: //American
			cout << setfill('0');
			cout << setw(2) << getMonth() << '/'
				 << setw(2) << getDay() << '/'
				 << getYear() << "	American"
				 << endl;
				 
			break;
		default:
			cout << "Unknown format" << endl;

	}
}


int cDate_t::getDayOfTheYear()
{
	setTime_info();
	return (time_info->tm_yday) + 1;
}

string cDate_t::getNameOfDay()
{
	setTime_info();
	return dayNames[time_info->tm_wday];
}



/******************
 * Private Methods
 ******************/

void cDate_t::setDate_p( int d, int m, int y )
{
	if (d > 0 && m > 0 && y > 0){

		//set the year
		year = y;

		//set the month and accumulate the overflow to year		
		month = ((m % 12) == 0) ? 12 : (m % 12);
		year += int((m-1)/12);

		//set the day and accumulate the overflow to the month & year
		while(d > daysInMonth[month-1]){

			//Take care of leap years
			if (month == 2 && isYearLeap() && d == 29){
				break;
			}

			//Subtract number of days in current month from d
			d -= daysInMonth[month-1];

			//If Feburary and Year is leap subtract one more day (total 29)
			if (month == 2 && isYearLeap()){
				d--;
			}

			//Advance month
			month++;

			//Advance Year if needed
			if(month > 12){
				month = 1;
				year++;
			}

		}

		//Finnaly - set the current day

		day = d;

	//case invalid date set to 1/1/1970 by default
	}else{
		day = 1;
		month = 1;
		year = 1970;
	}
}

void cDate_t::setTime_info()
{
	time_info->tm_mday = day;
	time_info->tm_mon = month - 1;
	time_info->tm_year = year - 1900;

	mktime(time_info);

}






