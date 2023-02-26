/*
 * PermanentEmployee.cpp
 *
 *  Created on: 23 Kas 2021
 *      Author: elif_
 */
#include "Date.h"
#include "PermanentEmployee.h"

//PermanentEmployee::PermanentEmployee():name(name),Employee(Employee::getNumber(),Employee::getType())/*,Employee::getName(),Employee::getSurname(),
//		Employee::getTitle(),Employee::getSalaryCoefficient(),Employee::getDateOfBirth(),Employee::getDateOfAppointment(),
//		Employee::getLengthOfService()) */{
//	 PermanentEmployee::setType(1);
//


void PermanentEmployee::setTitle(string title){
	PermanentEmployee::title=title;
	}
	void PermanentEmployee::setSalaryCoefficient(float salary){
		PermanentEmployee::salaryCoefficient=salary;
	}
	void PermanentEmployee::setName(string name){
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

