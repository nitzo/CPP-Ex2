/*
 * main.cpp
 *
 */
#include "cTime_t.h"
#include "cDate_t.h"
#include "cTimeDate_t.h"
#include <iostream>

using namespace std;

cTime_t time1, time2;
cDate_t date1, date2;
cTimeDate_t dateTime1(time1, date1);
cTimeDate_t dateTime2(dateTime1);
int i,h,m,s,d,mo,y;
char c;

void setTime();
void setDate();
cTime_t& getTimeObject();
cDate_t& getDateObject();


int main (int argc, int **argv){

	cout << "do you want to set initial value? (y/n)";
	cin >> c;
	if (c == 'y')
	{
		setTime();
		setDate();
		time1.setTime(h,m,s);
		time2.setTime(h,m,s);
		date1.setDate(d,mo,y);
		date2.setDate(d,mo,y);
	}


	//TODO: add randomize initialization

	cout << "\n";

	while (1)
	{
		cout << "Time command list: \n"
			<< "****************** \n"
			<< "1 - set the time			2 - t1=t1+t2 \n" 
			<< "3 - change time printing format		4 - get the hour \n"
			<< "5 - get the minute			6 - get the second \n"
			<< "\n"
			<< "Date command list: \n"
			<< "****************** \n"
			<< "7  - set the Date			8  - change date printing format \n" 
			<< "9  - get the day 			10 - get the month \n"
			<< "11 - get the year  			12 - get the day of the year \n"
			<< "13 - is year leap			14 - get name of the day \n"
			<< "15 - get name of the month		16 - exit program \n"
			<< "\n"
			<< "DateTime command list: \n"
			<< "********************** \n"
			<< "17 - Add time object to DateTime \n"
			<< "\n"
			<< "Member status: \n"
			<< "************** \n"
			<< "time1: "; time1.printTime();	
			cout << "time2: "; time2.printTime();
			cout << "date1: "; date1.printDate();
			cout << "date2: "; date2.printDate();
			cout << "dateTime1: "; dateTime1.print();
			cout << "dateTime2: "; dateTime2.print();
			cout << "\n"
			<< "enter command number: ";

		cin >> i;

		cout << "\n";


		if ((i == 1)||((3 < i) && (i < 7))){

			cTime_t &timeObj = getTimeObject();

			switch(i){
				case 1:
					setTime();
					timeObj.setTime(h,m,s);
					continue;
				case 4:
					cout << timeObj.getHours()<< "hours \n \n";
					continue;
				case 5:
					cout << timeObj.getMinutes() << "minutes \n \n";
					continue;
				case 6:
					cout << timeObj.getSeconds()<< "seconds \n \n";
					continue;
			}
		}else if ((1 < i) && (i < 4)){
			switch(i){
				case 2:
					time1 = time1 + time2;
					continue;
				case 3:
					int f;
					cout << "enter print format: ";
					cin >> f;
					time1.format = f;
					continue;
				}
		}else if((6 < i) && (i < 16)){

			cDate_t &dateObj = getDateObject();
			switch(i){
				case 7:
					setDate();
					dateObj.setDate(d,mo,y);
					continue;
				case 8:
					int f;
					cout << "enter print format: ";
					cin >> f;
					date1.format = f;
					continue;
				case 9:
					cout << dateObj.getDay() << " day \n \n";
					continue;
				case 10:
					cout << dateObj.getMonth() << " month \n \n";
					continue;
				case 11:
					cout << dateObj.getYear() << " year \n \n";
					continue;
				case 12:
					cout << dateObj.getDayOfTheYear() << "\n \n";
					continue;
				case 13:
					cout << (dateObj.isYearLeap() ? "yes \n \n" : "no \n \ns");
					continue;
				case 14:
					cout << dateObj.getNameOfDay() << "\n \n";
					continue;
				case 15:
					cout << dateObj.getNameOfMonth() << "\n \n";
					continue;
			}
		}else{
			if (i == 16)
			{
				exit(0);
			}
			cout << "illegal command \n";
			continue;
		}
	}
}

void setTime()
{
	cout << "\n enter hour:";
	cin >> h;
	cout << "\n enter minute:";
	cin >> m;
	cout << "\n enter second:";
	cin >> s;
}

void setDate()
{
	cout << "\n enter day:";
	cin >> d;
	cout << "\n enter month:";
	cin >> mo;
	cout << "\n enter year:";
	cin >> y;
}

cTime_t &getTimeObject(){
	int num;
	cout << "choose time object: ";
	cin >> num;
	cout << "\n";
	if (num == 1)
	{
		cTime_t &tmp = time1;
		return tmp;
	}

	cTime_t &tmp = time2;
	return tmp;
}

cDate_t &getDateObject()
{
	int num;
	cout << "choose date object: ";
	cin >> num;
	cout << "\n";
	if (num == 1)
	{
		cDate_t &tmp = date1;
		return tmp;
	}

	cDate_t &tmp = date2;
	return tmp;
}
