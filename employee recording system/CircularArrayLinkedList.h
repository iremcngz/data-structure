#include "TemporaryEmployee.h"

#ifndef CIRCULARARRAYLINKEDLIST_H_
#define CIRCULARARRAYLINKEDLIST_H_

/*struct node{
	TemporaryEmployee data;
	int next;

};*/
/*
class CircularArrayLinkedList {
int head=0;
public:
	int avail=0;
	//struct node Tnode[20];
	int numOfNode=0;
	//CircularArrayLinkedList(){
//		    for(int i=0;i<19;i++){
//		    	Tnode[i].next=i+1;
//		    }
//		    Tnode[19].next=0;
//	}

	int getNode(TemporaryEmployee temp){
	    int tp=head;
		if(tp=0 && numOfNode != 20){
	    	return tp;
	    }
		int p;
	    if(avail == -1){
	        cout<<"ERROR: overflow!"<<endl;
	    }
	     while(Tnode[avail].data.getNumber()<temp.getNumber()){
	    	 tp=Tnode[tp].next;
	     }
	    p=tp;
	    tp=Tnode[tp].next;
	    return p;
	}

	void freeNode(int p){
	    Tnode[p].next = avail;
	    avail = p;
	    return;
	}

	void insertionSorted(int head,TemporaryEmployee temp){
		int q=getNode(temp);
		Tnode[q].data=temp;
		Tnode[q].next=avail;
	}



	virtual ~CircularArrayLinkedList();
};

*/


//#endif /* CIRCULARARRAYLINKEDLIST_H_ */
