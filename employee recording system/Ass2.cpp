
#include <iostream>
#include <sstream>
#include <vector>
#include "Employee.h"
#include "Date.h"
#include "TemporaryEmployee.h"
#include "PermanentEmployee.h"
#include "DoubleDynamicLinkedList.h"
#include "CircularArrayLinkedList.h"

using namespace std;

int main() {
	char choice;
	int number;
	int type;
	DoubleDynamicLinkedList D;
	CircularArrayLinkedList C;
	int* availList=C.createAvail();
    C.setLinks(C.Tnode);
    int C_head=0;



    struct Node* head=NULL;


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
		switch(choice){
		case '1':
			cout<<"Please type the employee number"<<endl;
						cin >>number;
						cout <<"Please type the employee type"<<endl;
						cin>>type;
						if(type==0){
							string salarystr;
							float salaryCoefficient;
							string name,surname,title,dateOfBirth,dateOfAppointment;
							cout<<"Please type the Name"<<endl;
							cin>>name;
							cout<<"Please type the Surname"<<endl;
							cin>>surname;
							cout<<"Type title"<<endl;
							cin>>title;
							cout<<"Type salary coefficient"<<endl;
							cin>>salaryCoefficient;
							cout <<"Type birth date"<<endl;
							cin>>dateOfBirth;
							string strdate=dateOfBirth;
						    vector<int> birthDate;
							istringstream ss(strdate);
						    string n;
							while(getline(ss,n,'-')){
							   birthDate.push_back(stoi(n));
							}
							Date b=Date(birthDate[0],birthDate[1],birthDate[2]);
							cout <<"Type appointment date"<<endl;
							cin>>dateOfAppointment;
							string strdate2=dateOfAppointment;
							vector<int> appD;
							istringstream s1(strdate2);
						     string m;
							while(getline(s1,m,'-')){
							    appD.push_back(stoi(m));
							}
			                Date a=Date(appD[0],appD[1],appD[2]);

						    TemporaryEmployee temp(number,type,name,surname,title,salaryCoefficient,b,a,0);
						    C.insert(&temp, availList,C.Tnode);
						    C.printLinks(C.Tnode);
						   // C.print(C.Tnode, availList, C_head);

						  }
					     if(type==1){
							  string salarystr;
							 float salaryCoefficient;
							  string name,surname,title,dateOfBirth,dateOfAppointment;
			                  cout<<"Please type the Name"<<endl;
							 cin>>name;
							  cout<<"Please type the Surname"<<endl;
							 cin>>surname;
							 cout<<"Type title"<<endl;
							 cin>>title;
							 cout<<"Type salary coefficient"<<endl;
							  cin>>salaryCoefficient;
			 				  cout <<"Type birth date"<<endl;
							  cin>>dateOfBirth;
							  string strdate=dateOfBirth;
							  vector<int> birthDate;
							  istringstream ss(strdate);
							  string n;
							  while(getline(ss,n,'-')){
							      birthDate.push_back(stoi(n));
							  }
							  Date b=Date(birthDate[0],birthDate[1],birthDate[2]);
							 cout <<"Type appointment date"<<endl;
							  cin>>dateOfAppointment;
							  string strdate2=dateOfAppointment;
							  vector<int> appD;
							 istringstream s1(strdate2);
							 string m;
							  while(getline(s1,m,'-')){
							      appD.push_back(stoi(m));
							  }
							Date a=Date(appD[0],appD[1],appD[2]);

							  PermanentEmployee per(number,type,name,surname,title,salaryCoefficient,b,a,0);
							   //cout<<per.getDateOfAppointment().getDay();
							 struct Node* newNode =D.getNode(per);
			                 D.sortedInsert(&head,newNode);

							 }

							 break;
		case '2':
			cout<<"Please type the employee number"<<endl;
			cin >>number;
			cout <<"Please type the employee type"<<endl;
			cin>>type;
			if(type==0){
				int lengthOfService;
				string salarystr;
				float salaryCoefficient;
				string name,surname,title,dateOfBirth,dateOfAppointment;
				cout<<"Please type the Name"<<endl;
				cin>>name;
				cout<<"Please type the Surname"<<endl;
				cin>>surname;
				cout<<"Type title"<<endl;
				cin>>title;
				cout<<"Type salary coefficient"<<endl;
				cin>>salaryCoefficient;
				cout <<"Type birth date"<<endl;
				cin>>dateOfBirth;
				string strdate=dateOfBirth;
			    vector<int> birthDate;
				istringstream ss(strdate);
			    string n;
				while(getline(ss,n,'-')){
				   birthDate.push_back(stoi(n));
				}
				Date b=Date(birthDate[0],birthDate[1],birthDate[2]);
				cout <<"Type appointment date"<<endl;
				cin>>dateOfAppointment;
				string strdate2=dateOfAppointment;
				vector<int> appD;
				istringstream s1(strdate2);
			     string m;
				while(getline(s1,m,'-')){
				    appD.push_back(stoi(m));
				}
                Date a=Date(appD[0],appD[1],appD[2]);
				cout <<"Type length of service days"<<endl;
				cin>>lengthOfService;
			    TemporaryEmployee temp(number,type,name,surname,title,salaryCoefficient,b,a,lengthOfService);
				        	}
		     if(type==1){
				 int lengthOfService;
				  string salarystr;
				 float salaryCoefficient;
				  string name,surname,title,dateOfBirth,dateOfAppointment;
                  cout<<"Please type the Name"<<endl;
				 cin>>name;
				  cout<<"Please type the Surname"<<endl;
				 cin>>surname;
				 cout<<"Type title"<<endl;
				 cin>>title;
				 cout<<"Type salary coefficient"<<endl;
				  cin>>salaryCoefficient;
 				  cout <<"Type birth date"<<endl;
				  cin>>dateOfBirth;
				  string strdate=dateOfBirth;
				  vector<int> birthDate;
				  istringstream ss(strdate);
				  string n;
				  while(getline(ss,n,'-')){
				      birthDate.push_back(stoi(n));
				  }
				  Date b=Date(birthDate[0],birthDate[1],birthDate[2]);
				 cout <<"Type appointment date"<<endl;
				  cin>>dateOfAppointment;
				  string strdate2=dateOfAppointment;
				  vector<int> appD;
				 istringstream s1(strdate2);
				 string m;
				  while(getline(s1,m,'-')){
				      appD.push_back(stoi(m));
				  }
			      Date a=Date(appD[0],appD[1],appD[2]);
				  cout <<"Type length of service days"<<endl;
				  cin>>lengthOfService;
				  PermanentEmployee per(number,type,name,surname,title,salaryCoefficient,b,a,lengthOfService);
			//	  if(head!=NULL){
			//	       cout<<"eklenmeden önceki  head :"<<head->data.getNumber()<<endl;
			//	   }
				//  struct Node* temp=head;
				 // while(temp!=NULL){
				  //  	cout<<temp->data.getNumber()<<" ";
				  //  	temp=temp->next;
				   //}

				 struct Node* newNode =D.getNode(per);
                 //cout << "GET NEW NODE: "<<newNode->data.getNumber();
                 D.sortedInsert(&head,newNode);
                // cout<<"eklendikten sonraki  head :"<<head->data.getNumber()<<endl;
              //   struct Node* temp2=head;
               //  		                  while(temp2!=NULL){
                // 		  			   	    cout<<temp2->data.getNumber()<<" ";
                // 		  			   	    temp2=temp2->next;
                // 		  			   	}
				 }
				 break;
		case '3':
			cout<<"Please type the employee number"<<endl;
			cin >>number;
			if(D.isThere(head,number)){
				string newTitle;
				float newSalary;
				cout <<"Please type the new title for this employee";
				cin>>newTitle;
				cout<<"Please type the new salary coefficient for this employee";
				cin>>newSalary;
				D.findByNumber(head,number)->data.setSalaryCoefficient(newSalary);
				D.findByNumber(head,number)->data.setTitle(newTitle);
			}
			break;
		case '4':
			cout<<"Please type the employee number"<<endl;
			cin >>number;
			if(D.isThere(head,number)){
			 //   struct Node* temp=head;
			  //  cout <<"silinmeden önceki list: "<<endl;
			   // while(temp!=NULL){
			   // 	cout<<temp->data.getNumber()<<" ";
			   // 	temp=temp->next;
			   // }
			    cout<<endl;
				struct Node* del=D.findByNumber(head, number);
			    D.deleteNode(&head, del);
               // cout <<"silindikten sonraki list: "<<endl;
              //  struct Node* temp2=head;
               // while(temp2!=NULL){
			   	//    cout<<temp2->data.getNumber()<<" ";
			   	//    temp2=temp2->next;
			   //	}

			//    cout<<endl;

			}
			break;
		case '5':
			cout <<"Please type the employee number to list its information:"<<endl;
			cin>>number;
			if(D.isThere(head, number)){
				//cout <<D.findByNumber(head, number)->data;                                        OVERLOAD EDİLMESİ LAZIM << EDEMEDİM
			}
			break;

		}


		}while(true);
	return 0;
}
