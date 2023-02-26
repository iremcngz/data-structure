/*
 * TemporaryEmployee.cpp
 *
 *  Created on: 23 Kas 2021
 *      Author: elif_
 */

#include "TemporaryEmployee.h"

//TemporaryEmployee::TemporaryEmployee() :Employee(Employee::getNumber(),Employee::getType(),Employee::getName(),Employee::getSurname(),
//		Employee::getTitle(),Employee::getSalaryCoefficient(),Employee::getDateOfBirth(),Employee::getDateOfAppointment(),
//		Employee::getLengthOfService()){
//	TemporaryEmployee::setType(0);


//}
void TemporaryEmployee::setTitle(string title){
		TemporaryEmployee::title=title;
	}
	void TemporaryEmployee::setSalaryCoefficient(float salary){
		TemporaryEmployee::salaryCoefficient=salary;
	}
	void TemporaryEmployee::setName(string name){
		TemporaryEmployee::name=name;
	}
	void TemporaryEmployee::setType(bool type){
		TemporaryEmployee::type=type;
	}
	void TemporaryEmployee::setSurname(string surname){
		TemporaryEmployee::surname=surname;
	}
	void TemporaryEmployee::setNumber(int number){
		TemporaryEmployee::number=number;
	}
	void TemporaryEmployee::setDateOfAppointment(Date date){
		TemporaryEmployee::dateOfAppointment=date;
	}
	void TemporaryEmployee::setLengthOfService(int length){
		TemporaryEmployee::lengthOfService=length;
	}
	void TemporaryEmployee::setDateOfBirth(Date date){
		TemporaryEmployee::dateOfBirth=date;
	}


	float TemporaryEmployee::getSalaryCoefficient(){
		return TemporaryEmployee::salaryCoefficient;
	}
	string TemporaryEmployee::getTitle(){
		return TemporaryEmployee::title;
	}
	bool TemporaryEmployee::getType() const{
		return TemporaryEmployee::type;
	}
	string TemporaryEmployee::getName() const{
		return TemporaryEmployee::name;
	}
	string TemporaryEmployee::getSurname() const{
		return TemporaryEmployee::surname;
	}
	Date TemporaryEmployee::getDateOfBirth() const{
		return TemporaryEmployee::dateOfBirth;
	}
	Date TemporaryEmployee::getDateOfAppointment() const{
		return TemporaryEmployee::dateOfAppointment;
	}
	int TemporaryEmployee::getLengthOfService() const{
		return TemporaryEmployee::lengthOfService;
	}
	int TemporaryEmployee::getNumber() const{
		return TemporaryEmployee::number;
	}


	string getTitle();
	float getSalaryCoefficient();
	int getNumber() ;
	bool  getType() ;
	string getName() ;
	string getSurname();
	Date getDateOfBirth() ;
	Date getDateOfAppointment() ;
	int getLengthOfService();

	void setTitle(string title);
	void setSalaryCoefficient(float salary);
	void setDateOfAppointment(Date date);
	void setLengthOfService(int length);
	void setDateOfBirth(Date date);
	void setType(bool type);
	void setName( string name);
	void setSurname(string surname);
	void setNumber( int number);


/*ostream& operator<<(ostream& out,Employee emp){
	out <<"type: "<< emp.getType() <<endl;
	out <<"name: "<< emp.getName() <<endl;
	out <<"surname: "<< emp.getSurname() <<endl;
	out <<"title: "<<emp.getTitle()<<endl;
	out <<"salary coefficient: "<<emp.getSalaryCoefficient()<<endl;

	out <<"birth date: "<<emp.getDateOfBirth().getDay()<<"-"<<emp.getDateOfBirth().getMounth()<<"-"
			<<emp.getDateOfBirth().getYear()<<endl;
	Date d2=emp.getDateOfAppointment();
	out <<"appointment day: "<<emp.getDateOfAppointment().getDay()<<"-"<<emp.getDateOfAppointment().getMounth()
					<<"-"<<emp.getDateOfAppointment().getYear()<<endl;
	out <<"length of services: "<<emp.getLengthOfService()<<endl;
	return out;
}*/
TemporaryEmployee::~TemporaryEmployee() {
	// TODO Auto-generated destructor stub
}







