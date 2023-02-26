#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>     /* atoi */
#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

vector<string> q;   //states
vector<string> q_final; //final states
vector<string> alf; //input alphabet
vector<string> s_alf; //stack alphabet

vector<vector<string> > T;

stack<string> s;



bool isTherePop(string state,string input,string pop);
bool isValidInputAlf(string new_alf);
bool isValidStackInput(string stack_input);
bool DPDA_valid=true;
bool isValidState(string state);
bool isThereState(string state);
void findT(string currState,string read,string pushE);
bool checkAccepted(string currState);
bool checkInitialInFinal(string initial);
bool isThereInput(string state,string input);
int findIndexOfTransition(string state,string input,string pop);
int findIndexOfTransitionWhenTopE(string state,string input);
int findIndexOfTWithState(string currState);
string initialState;
vector<string> finalStates;





int main(int argc, char** argv) {




	//reading dpda file
	fstream dpda;
	dpda.open(argv[1],ios::in);
	if(!dpda){
		cout<<"File creation failed";
	}else{
		string line;
		int lineNum=0;
		while (getline(dpda, line)) {
            if(lineNum==0){
            	//taking all state
            	int s=line.find(' ');
            	string subline=line.substr(2,s-2);
            	stringstream ss(subline);
            	while (ss.good()) {
            	    string substr;
            	    getline(ss, substr, ',');
            	    q.push_back(substr);
            	}

            	//taking initial and final states
                int f=line.find('(');
            	string subline0=line.substr(f);
            	stringstream ss0(subline0);
            	int count =0;
            	while (ss0.good()) {
            	   string substr0;
            	   getline(ss0, substr0, ',');
            	   if(count==0){
            		   if(isValidState(substr0.substr(1,substr0.find(')')-1))){
            			   initialState=substr0.substr(1,substr0.find(')')-1);
            			   count++;
            		   }else{
            			  DPDA_valid=false;
                   		  break;
            		   }
            	   }else{
            		   if(isValidState(substr0.substr(1,substr0.find(']')-1))){
            			   finalStates.push_back(substr0.substr(1,substr0.find(']')-1));
            		   }else{
            			   DPDA_valid=false;
            			   break;
            		   }

            	   }
            	}

                lineNum++;
            }else if(lineNum==1){
            	//taking input alf
            	string subline2=line.substr(2);
            	stringstream ss(subline2);
            	while (ss.good()) {
            	    string substr3;
            	    getline(ss, substr3, ',');
            	    alf.push_back(substr3);
            	}
                lineNum++;
            }else if(lineNum==2){
            	//taking stack alf
            	string subline3=line.substr(2);
            	stringstream ss(subline3);
            	while (ss.good()) {
            	    string substr4;
            	    getline(ss, substr4, ',');
            	    s_alf.push_back(substr4);
            	}
            	lineNum++;
            }else if(lineNum>2){
            	//taking transition rule
            	vector<string> t;
            	int countval=0;
            	int *count=&countval;
            	string subline4=line.substr(2);
            	stringstream ss(subline4);

            	while (ss.good()) {
            	   string substr5;

            	   getline(ss, substr5, ',');
                   switch(*count){
                		   case 0:
                			   if(isValidState(substr5)){     //check state if it is valid goes on else program will gives an error and will print error message
                				   t.push_back(substr5);
                				   (*count)++;
                			   }else{
                				  DPDA_valid=false;
                			   }
                			   break;
                		   case 1:
                			   if(isValidInputAlf(substr5)){ //check input if it is in input alp. goes on else gives an error
                				   t.push_back(substr5);
                				   (*count)++;
                			   }else{
                				   DPDA_valid=false;
                			   }
                			   break;
                		   case 2:
                			   if(isValidStackInput(substr5)){ //check stack input
                				   t.push_back(substr5);
                				   (*count)++;
                			   }else{
                				   DPDA_valid=false;
                			   }
                			   break;
                		   case 3:
                			   if(isValidState(substr5)){
                				   t.push_back(substr5);
                				   (*count)++;
                			   }else{
                				   DPDA_valid=false;
                			   }
                			   break;
                		   case 4:
                			   if(isValidStackInput(substr5)){
                				   t.push_back(substr5);
                				   (*count)++;
                			   }else{
                				   DPDA_valid=false;
                			   }
                			   break;

                   }

            	}
                //push new transition to all transitions vector
            	T.push_back(t);
            	lineNum++;
            }
	    }
	}

   //creat output file
	fstream output;
    output.open(argv[3],ios::out);

    //if there is an error in dpda file print it to output file
	if(!DPDA_valid){
		output << "Error [1]:DPDA description is invalid!";
	}




	//reading dpda-input file
	fstream dpda_input;
	dpda_input.open(argv[2],ios::in);
	if(!dpda_input){
		cout<<"File creation failed";
	}else if(DPDA_valid){
		string line;


	    while (getline(dpda_input, line)) {
	    	string currState=initialState;
	        string top;
	        int i=0;
            string input;
	    	bool finishLoop=false;
            //input line vector
	    	vector<string> input_line;
	    	stringstream ss(line);

	    	while (ss.good()) {
	    	   string subst;
	    	   getline(ss, subst, ',');
	    	   input_line.push_back(subst);
	        }





	    	while(!finishLoop){

	    		if(!s.empty()){
	    			top=s.top();
	    		}else{
	    			top="e";
	    		}

	    		if(i<input_line.size()){
	    			input=input_line[i];
	    		}else{
	    			if(s.empty())
	    			    input="e";
	    			else if(!s.empty()){
	    				if(s.top() == "$")
	    					input="e";
	    				else
	    					input="empty";

	    			}
	    		}

	    		if(top!="e" && isTherePop(currState,input,top)){     //currState==transition state, input==trasition, pop element not "e"
	    			i++;
	    			int indexOfT=findIndexOfTransition(currState,input,top);
	    			if(top=="$" && s.size()==1 ){ //program will stop or just will change state and goes on
	    				if(T[indexOfT][4]=="e" || T[indexOfT][4]=="$" ){ //won't push or will push $
	    					if(checkAccepted(currState)){  //if last element is $ and currState is one of the final states program will finish
	    				    	finishLoop=true;
	    				    	s.pop();
	    				    	//print output line
	    				    	output << T[indexOfT][0] <<","<<T[indexOfT][1]<<","<<T[indexOfT][2]<<" => "<<T[indexOfT][3]<<","<<T[indexOfT][4];
	    				    	output <<" [STACK]:";
	    				    	stack<string> temp;
	    				    	int count=0;
	    				    	int size=s.size();
	    				    	while(s.empty() == false){
	    				    		temp.push(s.top());
	    				    		s.pop();
	    				    	}
	    				        while (temp.empty() == false){
	    				    	    count++;
	    				            string t = temp.top();
	    				    	    output << t ;
	    				    	    if(size>1 && count<size){
	    				    	        output<<",";
	    				    	    }else
	    				    	        output <<" ";
	    				    	    temp.pop();
	    				    	// To restore contents of
	    				    	// the original stack.
	    				    	    s.push(t);
	    				        }
	    				    	output <<"ACCEPT"<<endl;
	    				    	output <<endl;

	    				    }else{     //just change state
	    				        currState=T[indexOfT][3];
	    				    }
	    				}else{       //push element and print
	    					currState=T[indexOfT][3];

	    					if(T[indexOfT][4]!="e"){
	    					    s.push(T[indexOfT][4]);
	    					}

	    					//print output line
	    					output << T[indexOfT][0] <<","<<T[indexOfT][1]<<","<<T[indexOfT][2]<<" => "<<T[indexOfT][3]<<","<<T[indexOfT][4];
	    					output <<" [STACK]:";
	    					stack<string> temp;
	    					int count=0;
	    					int size=s.size();
	    					while(s.empty() == false){
	    					    temp.push(s.top());
	    						s.pop();
	    					}
	    					while (temp.empty() == false){
	    						count++;
	    						string t = temp.top();
	    						output << t;
	    						if(size>1 && count<size){
	    							output<<",";
	    						}else
	    						    output <<" ";
	    						temp.pop();
	    						// To restore contents of
	    						// the original stack.
	    						s.push(t);
	    					}
	    					output <<endl;
	    				}
	    			}
	    			currState=T[indexOfT][3];
	    			s.pop();
	    			if(T[indexOfT][4]!="e"){
	    				s.push(T[indexOfT][4]);
	    			}


	    			//print output line
	    			output << T[indexOfT][0] <<","<<T[indexOfT][1]<<","<<T[indexOfT][2]<<" => "<<T[indexOfT][3]<<","<<T[indexOfT][4];
	    		    output <<" [STACK]:";
	    		    stack<string> temp;
	    		    int count=0;
	    		    int size= s.size();
	    		    while(s.empty() == false){
	    		        temp.push(s.top());
	    			    s.pop();
	    			}
	    			while (temp.empty() == false){
	    			    count++;
	    				string t = temp.top();
	    				output << t;
	    				if(size>1 && count<size){
	    					output<<",";
	    				}else
	    					output <<" ";
	    				temp.pop();
	    				// To restore contents of
	    		       // the original stack.
	    				s.push(t);
	    		     }
	    		     output<<endl;

	    		}else if(isThereInput(currState,input) ){ //if pop element "e"
	    			i++;
	    			int indexT=findIndexOfTransitionWhenTopE(currState,input);

	    			if(top=="$" && s.size()==1 ){ //programa ya bitecek ya da sadece state değiştirerek devam edecek
	    				if(T[indexT][4]=="e" || T[indexT][4]=="$" ){ //if won't push or will push  "$"
	    				    if(checkAccepted(currState)){  //check if program will finish
	    				    	finishLoop=true;
	    				    	s.pop();
                    	    	//print output line
	    				    	output << T[indexT][0] <<","<<T[indexT][1]<<","<<T[indexT][2]<<" => "<<T[indexT][3]<<","<<T[indexT][4];
	    				    	output <<" [STACK]:";
	    				    	stack<string> temp;
	    				    	int count=0;
	    				        int size= s.size();
	    				    	while(s.empty() == false){
	    				    	    temp.push(s.top());
	    				    	    s.pop();
	    				    	}
	    				    	while (temp.empty() == false){
	    				    		count++;
	    				    	    string t = temp.top();
	    				    	    output << t;
	    				    	    if(size>1 && count<size){
	    				    	        output<<",";
	    				    	    }else
	    				    	        output <<" ";
	    				    	    temp.pop();
	    				    	// To restore contents of
	    				        // the original stack.
	    				            s.push(t);
	    				    	}
	    				    	output <<"ACCEPT"<<endl;
	    				    	output <<endl;

	    				    	break;
	    				    	}else{     //just change state and print
	    				    		currState=T[indexT][3];
	    				    		s.push(T[indexT][4]);
	    				    		output << T[indexT][0] <<","<<T[indexT][1]<<","<<T[indexT][2]<<" => "<<T[indexT][3]<<","<<T[indexT][4];
	    				    		output <<" [STACK]:";
	    				    		stack<string> temp;
	    				    		int count=0;
	    				    		int size= s.size();
	    				    		while(s.empty() == false){
	    				    	        temp.push(s.top());
	    				    			s.pop();
	    				    	    }
	    				    		while (temp.empty() == false){
	    				    		    count++;
	    				    			string t = temp.top();
	    				    		    output << t ;
	    				    		    if(size>1 && count<size){
	    				    		       output<<",";
	    				    	       }else
	    				    		       output <<" ";
	    				    			temp.pop();
	    				    			// To restore contents of
	    				    			// the original stack.
	    				    			s.push(t);
	    				    	    }
	    				    		output <<endl;
	    				    	}
	    				}else{       //push and print
	    					int indexT=findIndexOfTransitionWhenTopE(currState,input);
	    					currState=T[indexT][3];
	    				    if(T[indexT][4]!="e"){
	    				        s.push(T[indexT][4]);
	    				    }
	    				    output << T[indexT][0] <<","<<T[indexT][1]<<","<<T[indexT][2]<<" => "<<T[indexT][3]<<","<<T[indexT][4];
	    				    output <<" [STACK]:";
	    				    stack<string> temp;
	    				    int count=0;
	    				    int size=s.size();
	    				    while(s.empty() == false){
	    				    	temp.push(s.top());
	    				    	s.pop();
	    				    }
	    				    while (temp.empty() == false){
	    				        count++;
	    				    	string t = temp.top();
	    				    	output << t ;
	    				        if(size>1 && count<size){
	    				    	   output<<",";
	    				    	}else
	    				           output <<" ";
	    				    	temp.pop();
	    				    // To restore contents of
	    				    // the original stack.
	    				        s.push(t);
	    				    }
	    				    output <<endl;
	    				}
	    		    }else{          //no pop, just push
	    		    	if(T[indexT][4]!="e"){
	    		    		s.push(T[indexT][4]);
	    		        }
	    		        currState=T[indexT][3];
	    		        //print output line
	    		        output << T[indexT][0] <<","<<T[indexT][1]<<","<<T[indexT][2]<<" => "<<T[indexT][3]<<","<<T[indexT][4];
	    		        output <<" [STACK]:";
	    		        stack<string> temp;
	    		        int count=0;
	    		        int size=s.size();
	    		        while(s.empty() == false){
	    		            temp.push(s.top());
	    		    		s.pop();
	    		        }
	    		    	while (temp.empty() == false){
	    		    	    count++;
	    		    		string t = temp.top();
	    		    		output << t;
	    		    	    if(size>1 && count<size){
	    		    		    output<<",";
	    		    		}else
	    		    		    output <<" ";
	    		    		temp.pop();
	    		    		// To restore contents of
	    		    		// the original stack.
	    		    		s.push(t);
	    		        }
	    		        output <<endl;
	    		    }
	    		}else if(isThereState(currState)){ //state==currState

                    int indexT=findIndexOfTWithState(currState);
                        if(T[indexT][4]=="e" || T[indexT][4]=="$" ){
                        	if(checkAccepted(currState)){
                        		finishLoop=true;
                    	        //print output line
                    	    	output << T[indexT][0] <<","<<T[indexT][1]<<","<<T[indexT][2]<<" => "<<T[indexT][3]<<","<<T[indexT][4];
                    	        output <<" [STACK]:";
                    	        int size=s.size();
                    	        int count=0;
                    	        stack<string> temp;
                    	    	while(s.empty() == false){
                    	    		temp.push(s.top());
                    	    		s.pop();
                    	    	}
                    	    	while (temp.empty() == false){
                    	    	    count++;
                    	    		string t = temp.top();
                    	    		output << t ;
                    	    		if(size>1 && count<size){
                    	    		    output<<",";
                    	    		}else
                    	    		    output <<" ";
                    	    		temp.pop();
                    	    		// To restore contents of
                    	    		// the original stack.
                    	    		s.push(t);
                    	    	}
                    	    	output <<"ACCEPT"<<endl;
                    	    	finishLoop=true;
                    	        output <<endl;
                    	   }else{
                    	       currState=T[indexT][3];
                    	       if(T[indexT][4]!="e")
                    	           s.push(T[indexT][4]);

                    	       output << T[indexT][0] <<","<<T[indexT][1]<<","<<T[indexT][2]<<" => "<<T[indexT][3]<<","<<T[indexT][4];
                    	       output <<" [STACK]:";
                    	       int size=s.size();
                    	       int count=0;
                    	       stack<string> temp;
                    	       while(s.empty() == false){
                    	           temp.push(s.top());
                    	           s.pop();
                    	       }
                    	       while (temp.empty() == false){
                    	           count++;
                    	    	   string t = temp.top();
                    	           output << t;
                    	           if(size>1 && count<size){
                    	              output<<",";
                    	           }else
                    	              output <<" ";
                    	           temp.pop();
                    	           // To restore contents of
                    	           // the original stack.
                    	           s.push(t);
                    	           }
                    	           output <<endl;
                    	   }
                    	}else{
                    	    currState=T[indexT][3];
                    	    if(T[indexT][4]!="e"){
                    	    	s.push(T[indexT][4]);
                    	    }
                    	    //print output line
                    	    output << T[indexT][0] <<","<<T[indexT][1]<<","<<T[indexT][2]<<" => "<<T[indexT][3]<<","<<T[indexT][4];
                    	    output <<" [STACK]:";
                    	    stack<string> temp;
                    	    int size=s.size();
                    	    int count=0;
                    	    while(s.empty() == false){
                    	    	temp.push(s.top());
                    	    	s.pop();
                    	    }
                    	    while (temp.empty() == false){
                    	        count++;
                    	    	string t = temp.top();
                    	    	output << t;
                    	    	if(size>1 && count<size){
                    	    		output<<",";
                    	    	}else
                    	    		output <<" ";
                    	    	temp.pop();
                    	     // To restore contents of
                    	     // the original stack.
                    	     	s.push(t);
                    	     }
                    	     output <<endl;
                    	}



	    		}else{
	    			if(initialState==currState){
	    				if(s.empty() && checkInitialInFinal(initialState)){
	    					output <<"ACCEPT"<<endl;
	    					output <<endl;
	    				}else{
	    					output <<"REJECT"<<endl;
	    					output <<endl;
	    				}
	    			}else if(s.empty()){
	    				    if(checkAccepted(currState)){
	    				        output <<"ACCEPT"<<endl;
	    				        output <<endl;
	    				    }
	    			}else if(s.size()==1 && s.top()=="$"){
	    				    output <<"ACCEPT"<<endl;
	    				    output<<endl;
	    			}else{
	    				    output <<"REJECT"<<endl;
	    				    output <<endl;
	    			}
	    			finishLoop=true;
	    			//delete all element in stack
	    			while(!s.empty())
	    		        s.pop();
	    		}



	    	}





	    }
	}





    output.close();
    dpda_input.close();
    dpda.close();


	return 0;
}


//helper method to take transition rule
//if input is in the list given in the second line of the dpda file (A:...)
//or it is "e" returns true else returns false
bool isValidInputAlf(string new_alf){
	bool flag=false;
	if(new_alf=="e"){
	    flag=true;
	}
	for (size_t i=0;i<alf.size();i++){
		if(alf[i] == new_alf ){
			flag=true;
		}
	}
	return flag;
}

//this function takes transition's stack input and check if it is valid
//all valid stack inputs given in the third line of the dpda file (Z:...) and if it is returns true
//if input is "e" this means we push nothing to stack so it returns true again
bool isValidStackInput(string stack_input){
	bool flag=false;
	if(stack_input=="e"){
		flag=true;
    }
	for (size_t i=0;i<s_alf.size();i++){
		if(s_alf[i] == stack_input){
				flag=true;
		}
    }
    return flag;
}

//this function takes state as parameter and check if
//Is it in the state list given in the first line of the dpda file (Q:.... )
//if it is returns true and we can go on, else returns false
bool isValidState(string state){
	bool flag=false;

	for (size_t i=0;i<q.size();i++){
		if(q[i] == state){
		    flag=true;
		}
	}
	return flag;
}


//take state as parameter and check if it is in finalstates list
bool checkAccepted(string currState){
	bool flag=false;

	if(s.empty()){
		for(size_t i =0;i<finalStates.size();i++){
		    if(finalStates[i]==currState){
			    flag=true;
			}
		}
	}else if(s.top()=="$" && s.size()==1){
		for(size_t i=0;i<finalStates.size();i++){
			if(finalStates[i]==currState){
				flag=true;
			}
		}
	}

	if(currState==initialState){
		return false;
	}else
	    return flag;


}

//check if initial state is in the final states
bool checkInitialInFinal(string initial){
	bool flag=false;
	for(size_t i =0;i<finalStates.size();i++){
		if(finalStates[i]==initial){
		    flag=true;
		}
	}
	return flag;
}

//if first 2 element are match
bool isThereInput(string state,string input){
	bool flag=false;
	for(size_t i=0;i<T.size();i++){
		if(T[i][0]==state && T[i][1]==input){
			flag=true;
		}
	}
	return flag;
}

//check if first 3 symbols are match
bool isTherePop(string state,string input,string pop){

	bool flag=false;
	for(size_t i=0;i<T.size();i++){
		if(T[i][0]==state && T[i][1]==input && T[i][2]==pop){
			flag=true;
		}
	}
	return flag;
}
//check first symbol
bool isThereState(string state){
	bool flag=false;
	for(size_t i=0;i<T.size();i++){
		if(T[i][0]==state && T[i][1]=="e" && T[i][2]=="e"){
			flag=true;
		}
	}
	return flag;
}

//find index of transition rule by using state
int findIndexOfTWithState(string currState){
	int index;
	for(size_t i=0;i<T.size();i++){
	    if(T[i][0]==currState && T[i][1]=="e" && T[i][2]=="e"){
		    index=i;
		}
	}
	return index;
}

//find index of transition rule by using state and input
int findIndexOfTransitionWhenTopE(string state,string input){
	int index;
	for(size_t i=0;i<T.size();i++){
			if(T[i][0]==state && T[i][1]==input && T[i][2]=="e"){
				index=i;
			}
	}
	return index;
}

//find index of transition rule by using state and input and top
int findIndexOfTransition(string state,string input,string pop){
	int index;
	for(size_t i=0;i<T.size();i++){
		if(T[i][0]==state && T[i][1]==input && T[i][2]==pop){
			index=i;
		}
	}
	return index;
}
