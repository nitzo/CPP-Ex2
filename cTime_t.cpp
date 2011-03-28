#include "cTime_t.h"
#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

/******************
 * Static Members
 ******************/
int cTime_t::format = 1;			//Default format setting

/****************
 * CTORs and DTOR
 ****************/

cTime_t::cTime_t() {

	//Get current Time zone
	time_t time_data;
	struct tm* current_time;

	time( &time_data);
	current_time = localtime(&time_data);

	setTime_p(current_time->tm_hour, current_time->tm_min, current_time->tm_sec);

}

cTime_t::cTime_t(int h, int m, int s) {
	setTime_p(h,m,s);
}

cTime_t::cTime_t(const cTime_t& t) {

	setTime_p(t.getHours(), t.getMinutes(), t.getSeconds());

}

cTime_t::~cTime_t() {
	//DTOR
}


/************
 * Operators
 ***********/

const cTime_t& cTime_t::operator=(const cTime_t &t) {

	if (this != &t){

		setTime_p(t.getHours(), t.getMinutes(), t.getSeconds());

	}

	return *this;
}

const cTime_t& cTime_t::operator+(const cTime_t &t) {

	addTime_p(t.getHours(), t.getMinutes(), t.getSeconds());

	return *this;
}

/******************
 * Public Methods
 ****************/

void cTime_t::setTime(int h, int m, int s) {
	setTime_p(h,m,s);
}

void cTime_t::printTime() const{

	printTime(this->format);

}

void cTime_t::printTime(int f) const{

	switch (f){

		case 1:
			cout << setfill('0');
			cout << setw(2) << getHours() << ':'
				 << setw(2)	<< getMinutes() << ':'
				 << setw(2) << getSeconds() << endl;
			break;
		case 2:
			if (getHours() > 12)
				cout << (getHours() - 12);
			else
				cout << getHours();

			cout << ":";

			cout << setfill('0');
			cout << setw(2)	<< getMinutes() << ':'
				 << setw(2) << getSeconds() << ' ';

			if (getHours() > 12)
				cout << "PM";
			else
				cout << "AM";


			cout << endl;

			break;

		default: //Unknown format...

			cout << "Unknown format!" << endl;

			break;

	}

}


/******************
 * Private Methods
 ******************/

/*
 * Add h, m, s to current time
 * Take care of overflows (s < 60, m < 60, h < 24)
 */
void cTime_t::addTime_p(int h, int m, int s) {
	
	//Set seconds
	s += seconds;
	seconds = s % 60;
	m += int(s/60);

	//Set minutes
	m += minutes;
	minutes = m % 60;
	h += int(m/60);

	//Set hours
	h += hours;
	hours = h % 24;
}

/*
 * Set time as 0:0:0
 */
void cTime_t::zeroTime(){
	hours = 0;
	minutes = 0;
	seconds = 0;
}

/**
 * Set current time as h:m:s . (Takes care of overflows)
 */
void cTime_t::setTime_p(int h, int m, int s){

	zeroTime();
	//case value invalid set to default value 00:00:00
	if (s < 0 || m < 0 || h < 0){
		return;
	}

	addTime_p(h,m,s);
}

