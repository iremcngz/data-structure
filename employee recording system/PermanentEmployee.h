
#include "Employee.h"
#ifndef PERMANENTEMPLOYEE_H_
#define PERMANENTEMPLOYEE_H_

class PermanentEmployee :public Employee {
public:
//	PermanentEmployee();
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
		void setDateOfAppointment(Date date);
		void setLengthOfService(int length);
		void setDateOfBirth(Date date);
		void setType(bool type);
		void setName( string name);
		void setSurname(string surname);
		void setNumber( int number);
		friend ostream &operator <<
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

#endif /* PERMANENTEMPLOYEE_H_ */
