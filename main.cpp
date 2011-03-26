/*
 * main.cpp
 *
 *  Created on: 26/03/2011
 *      Author: nitzo
 */
#include "cTime_t.h"
#include <iostream>

using namespace std;


int main (int argc, int **argv){


	cTime_t time;
	int h,m,s;

	time.printTime(1);

	cin >> h;
	cin >> m;
	cin >> s;

	cTime_t time1(h,m,s);

	cin >> h;
	cin >> m;
	cin >> s;


	cTime_t time2(h,m,s);

	time1.printTime();
	time2.printTime();

	time1 = time1 + time2;

	time1.printTime();
	time2.printTime();

	return 0;
}

