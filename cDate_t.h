
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
	cDate_t(const cDate_t& cDate_t);						//copy CTOR
	~cDate_t();												//DTOR

	const cDate_t& operator=(const cDate_t& t);				//assignment operator overload
	const cDate_t& operator+(const cDate_t& t);				//adding operator

	void setDate(int hours, int minutes, int seconds);		//set a new date

	//TODO: understand how this format thing work?	
	void printDate() const;										//print the date in the current default format
	void printDate(int format) const;							//print the date & set the default format:
																//dd:2, mon:3, year:4 - 22/Jan/2001
																//dd:2, mon:2, year:4 - 22/01/2001
																//dd:2, mon:2, year:4 - 22/Jan/2001
	
	int getDay()const;										//retrieve the day
	int getMonth()const;									//retrieve the month
	int getYear()const;										//retrieve the year
	int getDayOfTheYear()const;								//retrieve the day of the year(1-365)
	bool isYearLeap()const;									//Is year leap or not (return true iff ((year % 4) == 0))
	string getNameOfDay()const;								//retrieve the name of the day
	string getNameOfMonth()const;							//retrieve the name of the month

private:

	int day;
	int month;
	int year;

	static const int daysInMonth[];							//Num of days in standard (non-Leap) Yearm
	static const string cDate_t::dayNames[];
	static const string cDate_t::months[];


	void setCurrentDate();									//set the current date according to struct tm class
	void setDate_p(int d, int m, int y);

};


/*******************
 * Inline functions
 *******************/
inline int cDate_t::getDay() const
{
	return day;
}

inline int cDate_t::getMonth() const
{
	return month;
}

inline int cDate_t::getYear() const
{
	return year;
}

inline string cDate_t::getNameOfMonth() const
{
	return months[month - 1];
}

inline bool cDate_t::isYearLeap() const
{
	return (year % 4) == 0;
}


#endif
