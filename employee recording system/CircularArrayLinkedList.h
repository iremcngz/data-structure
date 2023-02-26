/*
 * CircularArrayLinkedList.h
 *
 *  Created on: 26 Kas 2021
 *      Author: elif_
 */

#include "TemporaryEmployee.h"
#ifndef CIRCULARARRAYLINKEDLIST_H_
#define CIRCULARARRAYLINKEDLIST_H_







class CircularArrayLinkedList {
public:

	CircularArrayLinkedList():nextFree(0),head(-1),numOfTemp(0){};
	struct node{
		TemporaryEmployee* data;
		int next;
	};

	struct node Tnode[20];
	int nextFree;
	int head;
	int numOfTemp;

	void setLinks(struct node Tnode[]){
	    Tnode[0].next=1;
		for(int i=1;i<19;i++){
		    Tnode[i].next=i+1;
	    }
	    Tnode[19].next=0;
	}

	//avail list
	int* createAvail(){
		static int arr[20];
		for(int i=0;i<20;i++){
			arr[i]=true;
		}
		return arr;
	}
	int findAvail(int* availList){
		for(int i=0;i<20;i++){
			if(availList[i]==true){
			    return i;
			    break;
			}
		}
	}
	void printLinks(struct node Tnode[]){

		for (int i=0;i<20;i++){
			cout <<Tnode[i].next<<" ";
		}
	};
	void insert(TemporaryEmployee *temp,int* availList,struct node Tnode[]){
		if(numOfTemp>20)
			return;
		if(numOfTemp==0){
			cout <<"bua"<<endl;
            Tnode[0].data=temp;
            Tnode[0].next=1;
            availList[0]=false;
            head=0;
         //   cout <<"yeni head "<<head;
            numOfTemp+=1;

		}else{

			int tp=head;
        //  cout <<findAvail(availList)<<endl;
		    cout <<head<<" "<<Tnode[tp].data->getNumber()<<" "<<temp->getNumber()<<endl;
			while(Tnode[tp].data->getNumber()<temp->getNumber()){
                cout <<"geldi"<<endl;
				tp=Tnode[tp].next;
			}
			/*Tnode[findAvail(availList)].next=Tnode[tp].next;
			Tnode[tp].next=findAvail(availList);
			Tnode[findAvail(availList)].data=temp;
			availList[findAvail(availList)]=false;
			numOfTemp+=1;*/
		}
	}

	void print(struct node Tnode[],int *availList,int head){
		for(int i=0;i<20;i++){
			cout <<availList[i]<<" ";
		}
        cout<< endl;
		cout <<"Tnode"<<endl;

		/*do{
			cout << Tnode[curr].data->getNumber()<<" ";
			curr=Tnode[curr].next;
		}
		while(curr!=head);
		*/
	}


	void insertionSort(node* headref,TemporaryEmployee temp,int avail,struct node Tnode[]);


	struct node getNode(TemporaryEmployee temp,int avail);

	//void freenode(int p);



	virtual ~CircularArrayLinkedList();
};

#endif /* CIRCULARARRAYLINKEDLIST_H_ */

