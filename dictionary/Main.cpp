#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#define ALPHABET 26
using namespace std;

char cAlphabet[] = {'a','b','c','d','e','f',
		'g','h','i','j','k','l','m','n','o','p',
		'q','r','s','t','u','v','w','x','y','z'};

class trieNode
{
    public:
	trieNode* children[ALPHABET];
    bool isEndOfWord;
    string meaning;
    trieNode()
    {
        this->isEndOfWord=false;
        for(int i=0; i<ALPHABET; i++)
            this->children[i]=NULL;
    }
};


int operationType(string opr);
int findIndexOfLetter(char ltr);
int insert(trieNode *root, string word, string meaning);
bool search(trieNode *root, string word);
bool isMeaningSame(trieNode *root, string word, string meaning);
void list(trieNode * root,char word[],int indx,fstream& output);
int howManyLetter(trieNode *root, string word);
void deleteWord(trieNode *root, string word);


bool alp[26];

int main(int argc, char** argv) {


	//output file
	fstream output;
	output.open(argv[2],ios::out);



	//input file
	fstream input;
	input.open(argv[1],ios::in);
		if(!input){
			cout<<"File creation failed";
		}else{
			trieNode *root=new trieNode();
			string line;
			while (getline(input, line)){
				int s=line.find('(');
				string subline=line.substr(0,s);
				stringstream ss(subline);
				while (ss.good()) {
				   string substr;
				   getline(ss,substr);

                   int opr=operationType(substr);

                   switch(opr){
				   case 0:  //insert
					   {int v=line.find(',');
					   int f=line.find(')');
					   string word=line.substr(s+1,v-s-1);
					   string meaning=line.substr(v+1,f-v-1);

					   if(!search(root,word)){ //not exist
                            insert(root,word,meaning);

                            output << "'" << word<< "' was added"<<endl;
					   }else if(search(root,word) && !isMeaningSame(root,word,meaning)){ //exist with different value, will update

						   insert(root,word,meaning);
						   output << "'"<<word<<"' was updated"<<endl;
					   }else if(search(root,word) && isMeaningSame(root,word,meaning)){ //exist with same value

						   output <<"'"<<word<<"' already exist"<<endl;
					   }

					    break;
					   }
				   case 1:  //delete
					   {
						   int l=line.find(')');
					       string word=line.substr(s+1,l-s-1);
						   int numOfSameLet=howManyLetter(root,word);
						   if(!search(root,word) && numOfSameLet==0){ //
						       output<<"'no record'"<<endl;
						   }else if(search(root,word)){
							   trieNode *node= root;
							   deleteWord(node,word);
							   output <<"'"<<word<<"'"<<" deletion is successful"<<endl;
						   }else if(!search(root,word) && numOfSameLet<(int)word.size()){
							   output<< "'incorrect Dothraki word'"<<endl;
						   }else if(numOfSameLet==(int)word.size()){
						        output <<"'not enough Dothraki word'"<<endl;
						   }

					   break;
					   }
				   case 2:  //list
					   {
						   for(int i=0;i<26;i++)
						   	  	alp[i]=false;
                           char word[180];
						   list(root,word,0,output);

					   break;
					   }
				   case 3:  //search
					   {
						   int l=line.find(')');

						   string word=line.substr(s+1,l-s-1);

						   int numOfSameLet=howManyLetter(root,word);
						   if(!search(root,word) && numOfSameLet==0){ //
						       output<<"'no record'"<<endl;
						   }else if(search(root,word)){
							   trieNode *node= root;
							   for (size_t i = 0; i < word.length(); i++){
							        int index = findIndexOfLetter(word[i]);
							        if (!node->children[index])
							            return false;
							        node = node->children[index];
							   }
							   if (node!= NULL && node->isEndOfWord)  {
							       output << "'The English equivalent is "<<node->meaning<<"'"<<endl;
							   }
						   }else if(numOfSameLet==(int)word.size()){
						        output <<"'not enough Dothraki word'"<<endl;
						   }else if(!search(root,word) && numOfSameLet<(int)word.size() && numOfSameLet>0){
							   output<< "'incorrect Dothraki word'"<<endl;
						   }
					   break;
					   }

				   }
				}
			}
		}
	return 0;
}

//find operation type
int operationType(string opr){
    if(opr=="insert")
    	return 0;
    else if(opr=="delete")
    	return 1;
    else if(opr=="list")
    	return 2;
    else if(opr == "search")
    	return 3;
    else
    	return 4;
}

int insert(trieNode *root, string word, string meaning){
    trieNode *node = root;
    int countOfAddedNode=0;
    for (size_t i = 0; i < word.length(); i++){
        int index = findIndexOfLetter(word[i]);

        //if index of letter is not empty this mean we should't add again,else we should add new node
        if (!node->children[index]){
            countOfAddedNode++;
        	node->children[index] = new trieNode();
        }

        node = node->children[index];
    }
    node->isEndOfWord = true;
    node->meaning = meaning;

    return countOfAddedNode;
}

int findIndexOfLetter(char ltr){
    if (ltr >= 'A' && ltr <= 'Z'){
        return ltr - 'A';
    }

    else if (ltr >= 'a' && ltr <= 'z'){
        return ltr - 'a';
    }

    return -1;
}
//search if exist return true
bool search(trieNode *root, string word){
    trieNode *node= root;

    for (size_t i = 0; i < word.length(); i++){
        int index = findIndexOfLetter(word[i]);

        if (!node->children[index])
            return false;

        node = node->children[index];
    }
    if(node->isEndOfWord==1)
    	return true;
    else
    	return false;
}



void list(trieNode * root,char word[],int indx,fstream& output){
	trieNode* node= root;
	    if(node != NULL && node->isEndOfWord == true) {
	    	if(!alp[findIndexOfLetter(word[0])]){

	    		 output<<"-"<<word[0]<<endl;
	             alp[findIndexOfLetter(word[0])]=true;

	        }
	    	output <<"    -";
	    	for(int j = 0; j < indx; j++)  {
	            output << word[j];
	            }
	        output << "(";
	        output << node->meaning <<")"<< "\n";
	    }
	    for(int i = 0; i < ALPHABET; i++)  {
	    	if(node->children[i] != NULL) {

	    		word[indx] = 'a' + i;
	            list(node->children[i], word, indx + 1,output);
	        }
	    }
}

//if same return true used to find out word exist or not
bool isMeaningSame(trieNode *root, string word, string meaning){
    trieNode *node= root;

    for (size_t i = 0; i < word.length(); i++){
        int index = findIndexOfLetter(word[i]);
        if (!node->children[index])
            return false;

        node = node->children[index];
    }
    if (node!= NULL && node->isEndOfWord)  {
        if(node->meaning==meaning){
        	return true;
        }else
        	return false;
    }
}

int howManyLetter(trieNode *root, string word){
    trieNode *node = root;
    int countOfNode=0;
    for (size_t i = 0; i < word.length(); i++){
        int index = findIndexOfLetter(word[i]);


        if (node->children[index]){
        	countOfNode++;
        	node = node->children[index];

        }else{
        	  return countOfNode;
        }

    }
    return countOfNode;
}

void deleteWord(trieNode *root, string word){
    trieNode *node= root;
    for (int i = 0; i < (int)word.length(); i++){
        int index = findIndexOfLetter(word[i]);

        if (!node->children[index])
            return;
        node= node->children[index];
    }
    if (node!= NULL && node->isEndOfWord)  {
        node->isEndOfWord = false;
        return;
    }
}


