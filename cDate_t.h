//
// cDate_t.h
//
// assumption from HW & VirtualTau Forum:
// ***********************************
// 1. accumulate the day/month if exceeding 7/12
// 2. CTOR gets only valid values
// 3. year > 1900
// 4. day of the week can be calculate only to value after 1/1/1970
//
#ifndef CDATE_T_H_
#define CDATE_T_H_

#include <string>
#include <sstream>

using namespace std;

class cDate_t {

public:

	static int format;										//Format of printing

	cDate_t();												//default CTOR from current date
	cDate_t(int day, int month, int year);					//CTOR from day, month and year
	cDate_t(const cDate_t& d);								//copy CTOR
	~cDate_t();												//DTOR

	const cDate_t& operator=(const cDate_t& d);				//assignment operator overload

	void setDate(int day, int month, int year);				//set a new date

	void printDate() const;									//print the date in the current default format
	void printDate(int format) const;						//print the date & set the default format:
															//dd:2, mon:3, year:4 - 22/Jan/2001
															//dd:2, mon:2, year:4 - 22/01/2001
															//dd:2, mon:2, year:4 - 22/Jan/2001
	
	int getDay()const;										//retrieve the day
	int getMonth()const;									//retrieve the month
	int getYear()const;										//retrieve the year
	int getDayOfTheYear();									//retrieve the day of the year(1-365)

	bool isYearLeap()const;									//Is year leap or not (return true iff ((year % 4) == 0))
	string getNameOfDay();									//retrieve the name of the day
	string getNameOfMonth() const;								//retrieve the name of the month

private:

	int day;
	int month;
	int year;

	struct tm* time_info;

	static const int daysInMonth[];							//Number of days in standard (non-Leap) Year
	static const string cDate_t::dayNames[];
	static const string cDate_t::months[];

	void setDate_p( int d, int m, int y );
	void setTime_info();

//	void setDate_p(int d, int m, int y,int dayOfYear);

};


/********************
 * Inline functions
 ********************/

/********************
 * Getters
 ********************/
inline int cDate_t::getDay() const{
	return this->day;
}

inline int cDate_t::getMonth() const{
	return this->month;
}

inline int cDate_t::getYear() const{
	return this->year;
}

inline string cDate_t::getNameOfMonth() const
{
	return months[month-1];
}

inline bool cDate_t::isYearLeap() const
{
	return ((year % 4) == 0);
}

#endif
