

#ifndef CTIMEDATE_T_H_
#define CTIMEDATE_T_H_

#include "cTime_t.h"
#include "cDate_t.h"

class cTimeDate_t {

public:

	cTimeDate_t();
	cTimeDate_t(int day, int month, int year, int hour, int minute, int second);
	cTimeDate_t(const cTime_t &t, const cDate_t &d);
	cTimeDate_t(const cTimeDate_t &t);
	~cTimeDate_t();

	const cTimeDate_t &operator+(const cTime_t &t);
	const cTimeDate_t &operator=(const cTimeDate_t &t);


	cTime_t& getTime() const;
	cDate_t& getDate() const;

	void print() const;


	cTime_t time_p;
	cDate_t date_p;


};


#endif /* CTIMEDATE_T_H_ */
