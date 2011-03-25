
#ifndef CTIME_T_H_
#define CTIME_T_H_



class cTime_t {


public:

	static int format;

	cTime_t();						//Default CTOR from Current Time
	cTime_t(int h, int m, int s);	//CTOR from Hours, Minutes and Seconds
	cTime_t(cTime_t& t);			//Copy CTOR
	~cTime_t();						//DTOR

	const cTime_t& operator=(const cTime_t &t);
	const cTime_t& operator+(const cTime_t &t);


	void setTime(int h, int m, int s);
	void printTime();
	void printTime(int f);		//Print time. f = 1 --> hh:mm:ss (24 hour format)
									//			  f = 2 --> h:mm:ss PM/AM

	int getHours();
	int getMintues();
	int getSeconds();


private:

	int totalSeconds;						//Holds time in seconds. Max value = 24 * 60 * 60

	int hours;
	int minutes;
	int seconds;

	void setTime_p(int h, int m, int s);

};



#endif
