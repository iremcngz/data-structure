#include <vector>
#include <iostream>
#include  <bits/stdc++.h>
#include <iomanip>
using namespace std;
#include "Employee.h"
#include "TemporaryEmployee.h"
#include "PermanentEmployee.h"
#include "DoubleDynamicLinkedList.h"
#include "Date.h"

PermanentEmployee createPEmployee(int number,int type);
TemporaryEmployee createTEmployee(int number,int type);
int main() {

	char choice;
	int number;
	int type;
	do{

		cout<<"-----Employee Recording System-----"<<endl;
		cout<<"Please select for the for the following Menu Operation: "<<endl;
		cout<<"1) Appointment of a new employee"<<endl;
		cout<<"2) Appointment of a transferred employee"<<endl;
		cout <<"3) Updating the title and salary coefficient of an employee"<<endl;
		cout <<"4) Deletion of an employee"<<endl;
		cout<<"5) Listing the information of an employee"<<endl;
		cout<<"6) Listing employees ordered by employee number"<<endl;
		cout<<"7) Listing employees ordered by appointment day"<<endl;
		cout<<"8) Listing employees appointed after a certain date"<<endl;
		cout<<"9) Listing employees assigned in a given year"<<endl;
		cout<<"10) Listing employees born before a certain date"<<endl;
		cout<<"11) Listing employees born in a particular month"<<endl;
		cout<<"12) Listing the information of the last assigned employee with a given title"<<endl;

		cin >> choice;
		cout<<endl;

		DoubleDynamicLinkedList dl;


		switch(choice)
		        {
		        case '1':
		        	cout<<"Please type the employee number"<<endl;
		        		    cin >>number;
		        	cout <<"Please type the employee type"<<endl;
		        	cin>>type;
		        	if(type==0){
		        		int lengthOfService;
		        			string salarystr;
		        			float salaryCoefficient;
		        			string name,surname,title,dateOfBirth,dateOfAppointment;
		        					//TemporaryEmployee* temp;
		        					TemporaryEmployee temp;
		        					//temp=&tm;
		        		            temp.setNumber(number);
		        					cout<<"Please type the Name"<<endl;
		        					cin>>name;
		        					temp.setName(name);
		        					cout<<"Please type the Surname"<<endl;
		        					cin>>surname;
		        					temp.setSurname(surname);
		        					cout<<"Type title"<<endl;
		        					cin>>title;
		        					temp.setTitle(title);
		        					cout<<"Type salary coefficient"<<endl;
		        					cin>>salaryCoefficient;
		        					temp.setSalaryCoefficient(salaryCoefficient);
		        					cout <<"Type birth date"<<endl;
		        					cin>>dateOfBirth;
		        					Date b=Date(dateOfBirth[0,2],dateOfBirth[3,2],dateOfBirth[6,2]);
		        					temp.setDateOfBirth(b);
		        					cout <<"Type appointment date"<<endl;
		        					cin>>dateOfAppointment;
		        					Date a=Date(dateOfAppointment[0,2],dateOfAppointment[3,2],dateOfAppointment[6,2]);
		        					temp.setDateOfAppointment(a);
		        					cout <<"Type length of service days"<<endl;
		        					cin>>lengthOfService;
		        					temp.setLengthOfService(lengthOfService);
		        	}


		        	break;
		        }

	}while(true);
	return 0;
}

PermanentEmployee createPEmployee(int number,int type){
	int lengthOfService;
	float salaryCoefficient;
	string name,surname,title,dateOfBirth,dateOfAppointment;
			PermanentEmployee per;
			//PermanentEmployee pr;
			//per=&pr;
			per.setNumber(number);
			cout<<"Please type the Name"<<endl;
			cin>>name;
			cout<<name;
			per.setName(name);
			cout<<"Please type the Surname"<<endl;
			cin>>surname;
			cout<<surname;
			per.setSurname(surname);
			cout<<"Type title"<<endl;
			cin>>title;
			cout<<title;
			per.setTitle(title);
			cout<<"Type salary coefficient"<<endl;
			cin>>salaryCoefficient;
			per.setSalaryCoefficient(salaryCoefficient);
			cout <<"Type birth date"<<endl;
			cin>>dateOfBirth;
			Date b=Date(dateOfBirth[0,2],dateOfBirth[3,2],dateOfBirth[6,2]);
			per.setDateOfBirth(b);
			cout <<"Type appointment date"<<endl;
			cin>>dateOfAppointment;
			Date a=Date(dateOfAppointment[0,2],dateOfAppointment[3,2],dateOfAppointment[6,2]);
			per.setDateOfAppointment(a);
			cout <<"Type length of service days"<<endl;
			cin>>lengthOfService;
			per.setLengthOfService(lengthOfService);
			return per;
		}

TemporaryEmployee createTEmployee(int number,int type){
	int lengthOfService;
	string salarystr;
	float salaryCoefficient;
	string name,surname,title,dateOfBirth,dateOfAppointment;
		cout<<"Please type the employee type"<<endl;
		cin>>type;
			//TemporaryEmployee* temp;
			TemporaryEmployee temp;
			//temp=&tm;
            temp.setNumber(number);
			cout<<"Please type the Name"<<endl;
			cin>>name;
			temp.setName(name);
			cout<<"Please type the Surname"<<endl;
			cin>>surname;
			temp.setSurname(surname);
			cout<<"Type title"<<endl;
			cin>>title;
			temp.setTitle(title);
			cout<<"Type salary coefficient"<<endl;
			cin>>salaryCoefficient;
			temp.setSalaryCoefficient(salaryCoefficient);
			cout <<"Type birth date"<<endl;
			cin>>dateOfBirth;
			Date b=Date(dateOfBirth[0,2],dateOfBirth[3,2],dateOfBirth[6,2]);
			temp.setDateOfBirth(b);
			cout <<"Type appointment date"<<endl;
			cin>>dateOfAppointment;
			Date a=Date(dateOfAppointment[0,2],dateOfAppointment[3,2],dateOfAppointment[6,2]);
			temp.setDateOfAppointment(a);
			cout <<"Type length of service days"<<endl;
			cin>>lengthOfService;
			temp.setLengthOfService(lengthOfService);
			return temp;
}
