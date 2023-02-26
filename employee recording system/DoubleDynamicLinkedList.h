/*
 * DoubleDynamicLinkedList.h
 *
 *  Created on: 26 Kas 2021
 *      Author: elif_
 */
#include "PermanentEmployee.h"
#include <iostream>
#ifndef DOUBLEDYNAMICLINKEDLIST_H_
#define DOUBLEDYNAMICLINKEDLIST_H_

struct Node{
	PermanentEmployee data;
	Node * next;
	Node *prev;
};

class DoubleDynamicLinkedList {
public:

	DoubleDynamicLinkedList();
    struct Node* head=NULL;

	struct Node* getNode(PermanentEmployee data);

	void sortedInsert(struct Node** head_ref, struct Node* newNode);

	struct Node* findByNumber(Node *head,int number);

	bool isThere(Node* head,int number);
    void deleteNode(Node **head_ref,struct Node* del);


	virtual ~DoubleDynamicLinkedList();
};

#endif /* DOUBLEDYNAMICLINKEDLIST_H_ */
