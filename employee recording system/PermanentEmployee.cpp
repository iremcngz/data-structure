
#include "Date.h"
#include "PermanentEmployee.h"

PermanentEmployee::PermanentEmployee(int number,
		bool type,
		string name,
		string surname,
		string title,
		float salaryCoefficient,
		Date dateOfBirth,
		Date dateOfAppointment,
		int lengthOfService):number(number),type(1),name(name),surname(surname),dateOfBirth(dateOfBirth),dateOfAppointment(dateOfAppointment)  {
	// TODO Auto-generated constructor stub
	PermanentEmployee::salaryCoefficient=salaryCoefficient;
	PermanentEmployee::title=title;
	PermanentEmployee::lengthOfService=lengthOfService;

}
/*
ostream& operator<<(ostream& Out,PermanentEmployee &emp){
			Out <<"type: "<< emp.getType() <<endl;
			Out <<"name: "<< emp.getName() <<endl;
			Out <<"surname: "<< emp.getSurname() <<endl;
			Out <<"title: "<<emp.getTitle()<<endl;
			Out <<"salary coefficient: "<<emp.getSalaryCoefficient()<<endl;
			Out <<"birth date: "<<emp.getDateOfBirth().getDay()<<"-"<<emp.getDateOfBirth().getMounth()<<"-"
					<<emp.getDateOfBirth().getYear()<<endl;
			Out <<"appointment day: "<<emp.getDateOfAppointment().getDay()<<"-"<<emp.getDateOfAppointment().getMounth()
					<<"-"<<emp.getDateOfAppointment().getYear()<<endl;
			Out <<"length of services: "<<emp.getLengthOfService()<<endl;
			return Out;
}*/

void PermanentEmployee::setTitle(string title){
	PermanentEmployee::title=title;
}
void PermanentEmployee::setSalaryCoefficient(float salary){
	PermanentEmployee::salaryCoefficient=salary;
}
/*	void PermanentEmployee::setName(string name){
		PermanentEmployee::name=name;
	}
	void PermanentEmployee::setType(bool type){
		PermanentEmployee::type=type;
	}
	void PermanentEmployee::setSurname(string surname){
		PermanentEmployee::surname=surname;
	}
	void PermanentEmployee::setNumber(int number){
		PermanentEmployee::number=number;
	}
	void PermanentEmployee::setDateOfAppointment(Date date){
		PermanentEmployee::dateOfAppointment=date;
	}
	void PermanentEmployee::setLengthOfService(int length){
		PermanentEmployee::lengthOfService=length;
	}
	void PermanentEmployee::setDateOfBirth(Date date){
		PermanentEmployee::dateOfBirth=date;
	}
*/

float PermanentEmployee::getSalaryCoefficient(){
		return PermanentEmployee::salaryCoefficient;
}
string PermanentEmployee::getTitle(){
		return PermanentEmployee::title;
}
bool PermanentEmployee::getType() const{
		return PermanentEmployee::type;
}
string PermanentEmployee::getName() const{
		return PermanentEmployee::name;
}
string PermanentEmployee::getSurname() const{
		return PermanentEmployee::surname;
}
Date PermanentEmployee::getDateOfBirth() const{
		return PermanentEmployee::dateOfBirth;
}
Date PermanentEmployee::getDateOfAppointment() const{
	return PermanentEmployee::dateOfAppointment;
}
int PermanentEmployee::getLengthOfService() const{
	return PermanentEmployee::lengthOfService;
}
int PermanentEmployee::getNumber() const{
	return PermanentEmployee::number;
}


PermanentEmployee::~PermanentEmployee() {
	// TODO Auto-generated destructor stub
}

