
#ifndef _CTIME_T_H_
#define _CTIME_T_H_



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
	void printTime() const;			//Print time in the static format
	void printTime(int f) const;	//Print time. f = 1 --> hh:mm:ss (24 hour format)
									//			  f = 2 --> h:mm:ss PM/AM

	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;


private:

	int hours;
	int minutes;
	int seconds;

	void addTime_p(int h, int m, int s); 		 //Add h:m:s to current time
	void zeroTime();		 					 //Set time to 00:00:00
	void setTime_p(int h, int m, int s);		 //Set current time to h:m:s


};




/********************
 * Inline functions
 ********************/

/********************
 * Getters
 ********************/
inline int cTime_t::getHours() const{
	return this->hours;

}

inline int cTime_t::getMinutes() const{
	return this->minutes;
}

inline int cTime_t::getSeconds() const{
	return this->seconds;
}




#endif
