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
	//TODO: implement
}

cDate_t::cDate_t( int day, int month, int year )
{
	//TODO: Change (Only for tests...)
	this->day = day;
	this->month = month;
	this->year = year;
}

cDate_t::cDate_t( const cDate_t& cDate_t )
{
	//TODO: implement
}

cDate_t::~cDate_t()
{
	//TODO: implement
}


/*************
 * Operators
 *************/

const cDate_t& cDate_t::operator=( const cDate_t& t )
{
	if (this != &t){
		day = t.getDay();
		month = t.getMonth();
		year = t.getYear();
	}

	return *this;
}

const cDate_t& cDate_t::operator+( const cDate_t& cDate_t )
{
	//TODO: Do we need??? (Not in HW spec...)
	//TODO: implement
}

/****************
 * Public Methods
 ****************/

void cDate_t::setDate( int hours, int minutes, int seconds )
{
	//TODO: implement
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
				 << getYear() << endl;
			break;

		case 3: //American
			cout << setfill('0');
			cout << setw(2) << getMonth() << '/'
				 << setw(2) << getDay() << '/'
				 << getYear() << endl;
			break;
		default:
			cout << "Unknown format" << endl;

	}
}


int cDate_t::getDayOfTheYear() const
{
	int count = 0;

	//Add days of previous months
	for (int i = 0; i < month - 1; i++){
		count += daysInMonth[i];
	}

	//Add days of current month
	count += day;

	//If year is a leap year & after February add one more day
	if (isYearLeap() && month > 2){
		count++;
	}

	return count;
}


string cDate_t::getNameOfDay() const
{
	//TODO: implement
}



/******************
 * Private Methods
 ******************/

void cDate_t::setCurrentDate(){
	//TODO: implement
}


void cDate_t::setDate_p(int d, int m, int y)
{
	if (d < 0 || m < 0 || y < 0){
		//TODO: What to do??
	}

	//TODO: Set date
}



