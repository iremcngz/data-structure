
#include "Date.h"
#include "Employee.h"
#include <string>
#include<vector>
#include <iostream>
using namespace std;


float Employee::getSalaryCoefficient(){
	return Employee::salaryCoefficient;
}
string Employee::getTitle(){
	return Employee::title;
}
bool Employee::getType() const{
	return Employee::type;
}
string Employee::getName() const{
	return Employee::name;
}
string Employee::getSurname() const{
	return Employee::surname;
}
Date Employee::getDateOfBirth() const{
	return Employee::dateOfBirth;
}
Date Employee::getDateOfAppointment() const{
	return Employee::dateOfAppointment;
}
int Employee::getLengthOfService() const{
	return Employee::lengthOfService;
}
int Employee::getNumber() const{
	return Employee::number;
}





void Employee::setTitle(string title){
	Employee::title=title;
}
void Employee::setSalaryCoefficient(float salary){
	Employee::salaryCoefficient=salary;
}
void Employee::setName(string name){
	Employee::name=name;
}
void Employee::setType(bool type){
	Employee::type=type;
}
void Employee::setSurname(string surname){
	Employee::surname=surname;
}
void Employee::setNumber(int number){
	Employee::number=number;
}
void Employee::setDateOfAppointment(Date date){
	Employee::dateOfAppointment=date;
}
void Employee::setLengthOfService(int length){
	Employee::lengthOfService=length;
}
void Employee::setDateOfBirth(Date date){
	Employee::dateOfBirth=date;
}



ostream& operator<<(ostream& out,Employee emp){
	out <<"type: "<< emp.getType() <<endl;
	out <<"name: "<< emp.getName() <<endl;
	out <<"surname: "<< emp.getSurname() <<endl;
	out <<"title: "<<emp.getTitle()<<endl;
	out <<"salary coefficient: "<<emp.getSalaryCoefficient()<<endl;
	Date d1=emp.getDateOfBirth();
	out <<"birth date: "<<emp.getDateOfBirth().getDay()<<"-"<<emp.getDateOfBirth().getMounth()<<"-"
			<<emp.getDateOfBirth().getYear()<<endl;
	out <<"appointment day: "<<emp.getDateOfAppointment().getDay()<<"-"<<emp.getDateOfAppointment().getMounth()
					<<"-"<<emp.getDateOfAppointment().getYear()<<endl;
	out <<"length of services: "<<emp.getLengthOfService()<<endl;
	return out;
}



Employee::~Employee() {
	// TODO Auto-generated destructor stub
}

