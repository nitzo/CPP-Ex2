#include "cDateTime_t.h"
#include "cTime_t.h"
#include "cDate_t.h"
#include <iostream>

using namespace std;


/*****************
 * CTORs & DTOR
 *****************/

cDateTime_t::cDateTime_t(){

}

cDateTime_t::cDateTime_t(int day, int month, int year, int hour, int minute, int second){
	time_p.setTime(hour, minute, second);
	date_p.setDate(day, month, year);
}

cDateTime_t::cDateTime_t(const cTime_t &t, const cDate_t &d){

	time_p = t;
	date_p = d;

}

cDateTime_t::cDateTime_t(const cDateTime_t &t): time_p(t.time_p), date_p(t.date_p){

}


cDateTime_t::~cDateTime_t(){

}

/*********************
 * Operators
 ********************/

const cDateTime_t &cDateTime_t::operator+(const cTime_t &t){

	//If time addition overflows 24 hours --> add 1 date to date_p
	if (time_p.getHours() + t.getHours() >= 24){
		date_p.setDate(date_p.getDay() + 1, date_p.getMonth(), date_p.getYear());
	}

	time_p = time_p + t;

	return *this;
}

const cDateTime_t &cDateTime_t::operator=(const cDateTime_t &t){

	if (this != &t){
		time_p = t.time_p;
		date_p = t.date_p;
	}

	return *this;

}

/*******************
 * Public methods
 ******************/

void cDateTime_t::print() const{

	date_p.printDate();

	cout << ' ';

	time_p.printTime();

}

