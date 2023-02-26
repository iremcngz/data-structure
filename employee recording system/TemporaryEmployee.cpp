
#include "Date.h"
#include "TemporaryEmployee.h"

TemporaryEmployee::TemporaryEmployee(int number,
		bool type,
		string name,
		string surname,
		string title,
		float salaryCoefficient,
		Date dateOfBirth,
		Date dateOfAppointment,
		int lengthOfService):number(number),type(0),name(name),surname(surname),dateOfBirth(dateOfBirth),dateOfAppointment(dateOfAppointment) {
	// TODO Auto-generated constructor stub
	TemporaryEmployee::salaryCoefficient=salaryCoefficient;
	TemporaryEmployee::title=title;
	TemporaryEmployee::lengthOfService=lengthOfService;

}


void TemporaryEmployee::setTitle(string title){
		TemporaryEmployee::title=title;
	}
void TemporaryEmployee::setSalaryCoefficient(float salary){
	TemporaryEmployee::salaryCoefficient=salary;
}
/*	void TemporaryEmployee::setName(string name){
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
*/

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

TemporaryEmployee::~TemporaryEmployee() {
	// TODO Auto-generated destructor stub
}

