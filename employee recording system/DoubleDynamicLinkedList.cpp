/*
 * DoubleDynamicLinkedList.cpp
 *
 *  Created on: 26 Kas 2021
 *      Author: elif_
 */

#include "DoubleDynamicLinkedList.h"
#include "PermanentEmployee.h"
DoubleDynamicLinkedList::DoubleDynamicLinkedList() {
	// TODO Auto-generated constructor stub

}

struct Node* DoubleDynamicLinkedList::getNode(PermanentEmployee data)
	{
	    // allocate node
	    struct Node* newNode =
	          (struct Node*)malloc(sizeof(struct Node));

	    // put in the data
	    newNode->data = data;
	    newNode->prev = newNode->next = NULL;
	    return newNode;
}

void DoubleDynamicLinkedList::sortedInsert(struct Node** head_ref, struct Node* newNode){
	    struct Node* current;

	    if (*head_ref == NULL){
	        *head_ref = newNode;
	    }

	    else if ((*head_ref)->data.getDateOfAppointment() <=newNode->data.getDateOfAppointment() ) { //yeni
	    	newNode->next = *head_ref;
	        newNode->next->prev = newNode;
	        *head_ref = newNode;
	    }

	    else {
	        current = *head_ref;

	        while (current->next != NULL &&
	        		current->next->data.getDateOfAppointment() > newNode->data.getDateOfAppointment() )
	        	current = current->next;

	        newNode->next = current->next;

	        if (current->next != NULL)
	            newNode->next->prev = newNode;
	        current->next = newNode;
	        newNode->prev = current;
	    }
}


struct Node* DoubleDynamicLinkedList::findByNumber(Node* head,int number){
	struct Node* temp=head;
	while(temp!=NULL){
		if(temp->data.getNumber()==number)
		    return temp;
		temp=temp->next;
	}
}
void DoubleDynamicLinkedList::deleteNode(Node** head_ref,struct Node* del){
    if (*head_ref == NULL || del == NULL)
        return;
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    //free the memory occupied by old node/
    free(del);
    return;
}

ostream& operator<<(ostream& COut,PermanentEmployee &emp){
			COut <<"type: "<< emp.getType() <<endl;
			COut <<"name: "<< emp.getName() <<endl;
			COut <<"surname: "<< emp.getSurname() <<endl;
			COut <<"title: "<<emp.getTitle()<<endl;
			COut <<"salary coefficient: "<<emp.getSalaryCoefficient()<<endl;
			COut <<"birth date: "<<emp.getDateOfBirth().getDay()<<"-"<<emp.getDateOfBirth().getMounth()<<"-"
					<<emp.getDateOfBirth().getYear()<<endl;
			COut <<"appointment day: "<<emp.getDateOfAppointment().getDay()<<"-"<<emp.getDateOfAppointment().getMounth()
					<<"-"<<emp.getDateOfAppointment().getYear()<<endl;
			COut <<"length of services: "<<emp.getLengthOfService()<<endl;
			return COut;
}
bool DoubleDynamicLinkedList::isThere(Node *head,int number){

	struct Node* temp=head;
	while(temp!=NULL){
		if(temp->data.getNumber()==number)
				return true;
		temp=temp->next;
	}
	return false;

}

DoubleDynamicLinkedList::~DoubleDynamicLinkedList() {
	// TODO Auto-generated destructor stub
}

