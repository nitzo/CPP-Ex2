

#ifndef CDateTime_t_H_
#define CDateTime_t_H_

#include "cTime_t.h"
#include "cDate_t.h"

class cDateTime_t {

public:

	cDateTime_t();																	//CTOR from current date & time
	cDateTime_t(int day, int month, int year, int hour, int minute, int second);	//CTOR from given date & time
	cDateTime_t(const cTime_t &t, const cDate_t &d);								//CTOR from cDate_t & cTime_t objects
	cDateTime_t(const cDateTime_t &t);												//Copy CTOR
	~cDateTime_t();																	//DTOR

	const cDateTime_t &operator+(const cTime_t &t);									//Add cTime_t object to cDateTime object
	const cDateTime_t &operator=(const cDateTime_t &t);								//Assigment Operator


	void print() const;																//Print object


	cTime_t time_p;
	cDate_t date_p;


};


#endif /* CDateTime_t_H_ */
