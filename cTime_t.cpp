#include "cTime_t.h"
#include <time.h>
#include <iostream>
#include <iomanip>

using namespace std;

/******************
 * Static Members
 ******************/
int cTime_t::format = 1;			//Defualt format setting

/****************
 * CTORs and DTOR
 ****************/

//TODO: Initialazation lists?

cTime_t::cTime_t() {

	//Get current Time zone
	time_t time_data;
	struct tm* current_time;

	time_data = time(0);
	current_time = localtime(&time_data);

	setTime_p(current_time->tm_hour, current_time->tm_min, current_time->tm_sec);

}

cTime_t::cTime_t(int h, int m, int s) {
	setTime_p(h,m,s);
}

cTime_t::cTime_t(cTime_t& t) {

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

const cTime_t& cTime_t::operator+(const cTime_t &t) {  //TODO: Should we change this object?

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
			cout << setw(2) << getHours() << ":"
				 << setw(2)	<< getMinutes() << ":"
				 << setw(2) << getSeconds() << endl;
			break;
		case 2:
			if (getHours() > 12)
				cout << (getHours() - 12);
			else
				cout << getHours();

			cout << ":";

			cout << setfill('0');
			cout << setw(2)	<< getMinutes() << ":"
				 << setw(2) << getSeconds() << " ";

			if (getHours() > 12)
				cout << "PM";
			else
				cout << "AM";


			cout << endl;

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


	if (s < 0 || m < 0 || h < 0){
		//TODO: Set defualt value? Throw exception?
	}

	int tmp = 0;

	//Set seconds
	while (s >= 60){
		tmp++;
		s -= 60;
	}

	this->seconds += s;

	//Set minutes
	m += tmp;
	tmp = 0;

	while (m >= 60){
		tmp++;
		m -= 60;
	}

	this->minutes += m;

	//Set hours
	h += tmp;
	this->hours += h;

	while (this->hours >= 24){ //TODO: What to do in case of over flow in days?
		this->hours -= 24;
	}
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
	addTime_p(h,m,s);
}

