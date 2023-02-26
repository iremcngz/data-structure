/*
 * PermanentEmployee.h
 *
 *  Created on: 26 Kas 2021
 *      Author: elif_
 */
#include "Employee.h"
#include "Date.h"
#ifndef PERMANENTEMPLOYEE_H_
#define PERMANENTEMPLOYEE_H_
#include <string>
using namespace std;
class PermanentEmployee:public Employee {
public:

	PermanentEmployee(int number,
				const bool type,
				const string name,
				const string surname,
				string title,
				float salaryCoefficient,
				const Date dateOfBirth,
				const Date dateOfAppointment,
				const int lengthOfService);

	PermanentEmployee();



	string getTitle();
	float getSalaryCoefficient();
	int getNumber() const;
	bool  getType() const;
	string getName() const;
	string getSurname() const;
	Date getDateOfBirth() const;
	Date getDateOfAppointment() const;
	int getLengthOfService() const;
	void setTitle(string title);
	void setSalaryCoefficient(float salary);

	virtual ~PermanentEmployee();
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
/*
ostream& operator<<(ostream& out,PermanentEmployee emp){
			out <<"type: "<< emp.getType() <<endl;
			out <<"name: "<< emp.getName() <<endl;
			out <<"surname: "<< emp.getSurname() <<endl;
			out <<"title: "<<emp.getTitle()<<endl;
			out <<"salary coefficient: "<<emp.getSalaryCoefficient()<<endl;
			out <<"birth date: "<<emp.getDateOfBirth().getDay()<<"-"<<emp.getDateOfBirth().getMounth()<<"-"
					<<emp.getDateOfBirth().getYear()<<endl;
			out <<"appointment day: "<<emp.getDateOfAppointment().getDay()<<"-"<<emp.getDateOfAppointment().getMounth()
					<<"-"<<emp.getDateOfAppointment().getYear()<<endl;
			out <<"length of services: "<<emp.getLengthOfService()<<endl;
			return out;
}*/

#endif /* PERMANENTEMPLOYEE_H_ */
