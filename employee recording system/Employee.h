#include "Date.h"
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <string>
#include<vector>
#include <iostream>
using namespace std;
class Employee {

public:

/*	Employee(const int number,
		const bool type,
		const string name,
		const string surname,
		string title,
		float salaryCoefficient,
		const Date dateOfBirth,
		const Date dateOfAppointment,
		const int lengthOfService):number(number),type(type),name(name),surname(surname),dateOfBirth(dateOfBirth),
		dateOfAppointment(dateOfAppointment),lengthOfService(lengthOfService){
			Employee::title=title;
			Employee::salaryCoefficient=salaryCoefficient;
			cout <<"oluştu"<<endl;
		};*/
	virtual ~Employee();


	string getTitle();
	float getSalaryCoefficient();
	int getNumber() const;
	bool  getType() const;
	string getName() const;
	string getSurname() const;
	Date getDateOfBirth() const;
	Date getDateOfAppointment() const;
	int getLengthOfService() const;


 //   void setTitle(string title);
 //   void setSalaryCoefficient(int salary);
 //   void setDateOfAppointment(string date);
 //   void setLengthOfService(int length);
 //   void setDateOfBirth(string date);
 //   void setType(bool type);
 //   void setName(const string &name);
 //   void setSurname(string surname);
//    void setNumber(const int& number);

	void setTitle(string title);
	void setSalaryCoefficient(float salary);
	void setDateOfAppointment(Date date);
	void setLengthOfService(int length);
	void setDateOfBirth(Date date);
	void setType(bool type);
	void setName( string name);
	void setSurname(string surname);
	void setNumber( int number);





private:
	/*const int number;
	const bool type;
	const string name;
	const string surname;
	string title;  //değişiyor
	int salaryCoefficient; //değişiyor
	const string dateOfBirth;
	const string dateOfAppointment;
	const int lengthOfService;
	*/
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

ostream& operator<<(ostream& out,Employee emp);
#endif /* EMPLOYEE_H_ */
