#include "cTime_t.h"
#include <time.h>

cTime_t::cTime_t() {

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
	//Copy CTOR
}

cTime_t::~cTime_t() {
	//DTOR
}

const cTime_t& cTime_t::operator=(const cTime_t &t) {
	return *this;
}

const cTime_t& cTime_t::operator+(const cTime_t &t) {
	return *this;
}

void cTime_t::setTime(int h, int m, int s) {

}

void cTime_t::printTime(int f) {

//	int tmp = seconds;
//
//	int s = seconds % 3600;
//	int m =
//
//	if (f == 1){
//
//		cout <<
//	}

	//Print time. f = 1 --> hh:mm:ss (24 hour format)
}
//			  f = 2 --> h:mm:ss PM/AM

int cTime_t::getHours() {
	return 0;

}

int cTime_t::getMintues() {
	return 0;
}

int cTime_t::getSeconds() {
	return 0;
}

void cTime_t::setTime_p(int h, int m, int s) {

	seconds = h * 3600 + m * 60 + s;

	if (seconds >= 60 * 60 * 24) { //TODO: Return Error?
		seconds = 0;
	}
}
