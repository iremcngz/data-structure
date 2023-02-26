/*
 * CircularArrayLinkedList.cpp
 *
 *  Created on: 26 Kas 2021
 *      Author: elif_
 */

#include "TemporaryEmployee.h"
#include "CircularArrayLinkedList.h"





/*
struct node* CircularArrayLinkedList::getNode(TemporaryEmployee temp,int avail,struct node Tnode[]){
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=temp;
	newNode->next=NULL;
}

void CircularArrayLinkedList::insertionSort(node* headref,TemporaryEmployee temp,int avail,struct node Tnode[]){
	struct node* current=headref;
	while(current->data->getNumber()<temp.getNumber()){
		current=Tnode[current->next];
	}
	struct node* newNode=getNode(temp,avail,Tnode);
	newNode->next=current->next;
	Tnode[current->next]=newNode;

}*/

/*
void insertionSort(node* headref,TemporaryEmployee temp,struct node Tnode[])
   {
       // Initialize sorted linked list
       node* current = headref;
       // Traverse the given linked list and insert every
       // node to sorted
       while (current != NULL && current->data.getNumber() <Tnode[current->next].data.getNumber()){
           (*current)=Tnode[current->next];
           // insert current in sorted linked list
       struct node *newNode=(struct node*)malloc(sizeof(struct node));
       newNode->data= temp;
       newNode->next=current->next;
       Tnode[current->next]=(*newNode);
       }
       // Update head_ref to point to sorted linked list

}
*/
CircularArrayLinkedList::~CircularArrayLinkedList() {
	// TODO Auto-generated destructor stub
}


