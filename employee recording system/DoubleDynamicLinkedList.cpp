#include "PermanentEmployee.h"
#include "DoubleDynamicLinkedList.h"
struct node{
	PermanentEmployee* data;
	struct node* next;
	struct node* prev;
};

struct node *DoubleDynamicLinkedList::getNode(PermanentEmployee *data)
{
    struct node* newNode =
        (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}


void DoubleDynamicLinkedList::sortedInsert(struct node** head_ref, struct node* newNode){
    struct node* current;
    if (*head_ref == NULL)
        *head_ref = newNode;
    else if ((*head_ref)->data->getDateOfAppointment() >= newNode->data->getDateOfAppointment()) {
        newNode->next = *head_ref;
        newNode->next->prev = newNode;
        *head_ref = newNode;
    }
    else {
        current = *head_ref;
        while (current->next != NULL &&
               current->next->data->getDateOfAppointment() < newNode->data->getDateOfAppointment())
            current = current->next;
        newNode->next = current->next;
        if (current->next != NULL)
            newNode->next->prev = newNode;

        current->next = newNode;
        newNode->prev = current;
    }
}



bool DoubleDynamicLinkedList::search(node* head, int x)
{
    node* current = head; // Initialize current
    while (current != NULL)
    {
        if (current->data->getNumber() == x)
            return true;
        current = current->next;
    }
    return false;
}


bool DoubleDynamicLinkedList::searchByNum(struct node* head,int num){
	bool result=false;
	struct node* temp=head;
	if(temp==NULL) return false;
	if(temp->data->getNumber()==num) return true;
	while(temp->next!=NULL){
		temp=temp->next;
		if(temp->data->getNumber()==num)
			result= true;
	}
	return result;
}

DoubleDynamicLinkedList::DoubleDynamicLinkedList() {
	struct node* head=NULL;

}

DoubleDynamicLinkedList::~DoubleDynamicLinkedList() {
	// TODO Auto-generated destructor stub
}

