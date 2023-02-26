/*
 * DoubleDynamicLinkedList.h
 *
 *  Created on: 25 Kas 2021
 *      Author: elif_
 */

#ifndef DOUBLEDYNAMICLINKEDLIST_H_
#define DOUBLEDYNAMICLINKEDLIST_H_

class DoubleDynamicLinkedList {
public:
	struct node*head=NULL;
	DoubleDynamicLinkedList();


	bool searchByNum(struct node* head,int num);
	struct node *getNode(PermanentEmployee *data);
	void sortedInsert(struct node** head_ref, struct node* newNode);
    bool search(struct node* head, int x);
	virtual ~DoubleDynamicLinkedList();
};

#endif /* DOUBLEDYNAMICLINKEDLIST_H_ */
