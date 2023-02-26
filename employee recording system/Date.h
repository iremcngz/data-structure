/*
 * Date.h
 *
 *  Created on: 26 Kas 2021
 *      Author: elif_
 */
#include <iostream>
using namespace std;

#ifndef DATE_H_
#define DATE_H_

class Date {
public:
	Date(int day,int mounth,int year);
	virtual ~Date();


	int getDay() const;
	int getMounth() const;
	int getYear() const;
/*
	void setDay(int day);
	void setMounth(int mounth);
	void setYear(int year);
	*/




	bool operator==(const Date&other) const{
			return day==other.day && mounth == other.mounth && year == other.year;
		}
	bool operator!=(const Date& other) const{
		return day!=other.day && mounth != other.mounth && year != other.year;
	}

	bool operator<(const Date&other) const{  //which one is new
		if(year>other.year)
			return true;
		else if(year==other.year && mounth>other.mounth)
			return true;
		else if(year==other.year && mounth==other.mounth && day >other.day)
			return true;
		else
			return false;
	}

	bool operator>(const Date&other) const{  //which one is old
		if(year<other.year)
		    return true;
		else if(year==other.year && mounth<other.mounth)
			return true;
		else if(year==other.year && mounth==other.mounth && day < other.day)
			return true;
		else
			return false;
	}
	bool operator<=(const Date&other) const{  //which one is new
		if(year>other.year)
			return true;
		else if(year==other.year && mounth>other.mounth)
			return true;
		else if(year==other.year && mounth==other.mounth && day == other.day)
			return true;
		else
			return false;
	}
	bool operator>=(const Date&other) const{  //which one is old
		if(year<other.year)
			return true;
		else if(year==other.year && mounth<other.mounth)
			return true;
		else if(year==other.year && mounth==other.mounth && day < other.day)
			return true;
		else if(year==other.year && mounth==other.mounth && day == other.day)
			return true;
		else
		    return false;
	}


private:
	int day,mounth,year;
};



#endif /* DATE_H_ */
