

#include "Date.h"

Date::Date(int day,int mounth, int year) {
	Date::day=day;
    Date::mounth=mounth;
    Date::year==year;
}

ostream& operator<<(ostream& out,const Date date){
		out <<date.getDay()<<"-"<<date.getMounth()<<"-"<<date.getYear();
		return out;
}

int Date::getDay() const{
	return Date::day;
}
int Date::getMounth() const{
	return Date::mounth;
}
int Date::getYear() const{
    return Date::year;
}

void Date::setDay(int day){
	Date::day=day;
}
void Date::setMounth(int mounth){
	Date::mounth=mounth;
}
void Date::setYear(int year){
    Date::year=year;
}
Date::~Date() {
	// TODO Auto-generated destructor stub
}

