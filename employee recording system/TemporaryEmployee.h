/*
 * TemporaryEmployee.h
 *
 *  Created on: 26 Kas 2021
 *      Author: elif_
 */
#include "Employee.h"
#include "Date.h"
#ifndef TEMPORARYEMPLOYEE_H_
#define TEMPORARYEMPLOYEE_H_
#include <string>
using namespace std;
class TemporaryEmployee: public Employee {
public:
	TemporaryEmployee(int number,
			const bool type,
			const string name,
			const string surname,
			string title,
			float salaryCoefficient,
			const Date dateOfBirth,
			const Date dateOfAppointment,
			const int lengthOfService);

	TemporaryEmployee();



	void setTitle(string title);
	void setSalaryCoefficient(float salary);
	//void setDateOfAppointment(Date date);
	//void setLengthOfService(int length);
	//void setDateOfBirth(Date date);
	//void setType(bool type);
	//void setName( string name);
//	void setSurname(string surname);
//	void setNumber( int number);


	string getTitle();
	float getSalaryCoefficient();
	int getNumber() const;
	bool  getType() const;
	string getName() const;
	string getSurname() const;
	Date getDateOfBirth() const;
	Date getDateOfAppointment() const;
	int getLengthOfService() const;

	virtual ~TemporaryEmployee();
private:
	int number;
	    bool type;
	    string name;
	    string surname;
	    string title;  //değişiyor
	    float salaryCoefficient; //değişiyor
	    Date dateOfBirth;
	    Date dateOfAppointment;
	    int lengthOfService;
};

#endif /* TEMPORARYEMPLOYEE_H_ */
