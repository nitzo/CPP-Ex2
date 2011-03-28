#include "cTimeDate_t.h"
#include "cTime_t.h"
#include "cDate_t.h"

using namespace std;

cTimeDate_t::cTimeDate_t(){

}

cTimeDate_t::cTimeDate_t(int day, int month, int year, int hour, int minute, int second){
	time_p.setTime(hour, minute, second);
	date_p.setDate(day, month, year);
}

cTimeDate_t::cTimeDate_t(const cTime_t &t, const cDate_t &d){

	time_p = t;
	date_p = d;

}

cTimeDate_t::cTimeDate_t(const cTimeDate_t &t): time_p(t.time_p), date_p(t.date_p){

}


cTimeDate_t::~cTimeDate_t(){

}

const cTimeDate_t &cTimeDate_t::operator+(const cTime_t &t){

	//If time addition overflows 24 hours --> add 1 date to date_p
	if (time_p.getHours() + t.getHours() >= 24){
		date_p.setDate(date_p.getDay() + 1, date_p.getMonth(), date_p.getYear());
	}

	time_p = time_p + t;

	return *this;
}

const cTimeDate_t &cTimeDate_t::operator=(const cTimeDate_t &t){

	if (this != &t){
		time_p = t.time_p;
		date_p = t.date_p;
	}

	return *this;

}

void cTimeDate_t::print() const{

	time_p.printTime();
	date_p.printDate();

}

