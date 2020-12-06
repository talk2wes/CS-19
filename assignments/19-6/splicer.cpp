/* Wesley Johanson	Pengo: wjohanson	Talk2wes@gmail.com
 * Filename: splicer.cpp
 * Assignment 6: Splicer 
 * 
 * Status: Working & tested 
 */

#include "splicer.h"
using std::cout;

/* A public function named splice(string find, string replace) that takes two 
 * strings called find and replace. Do nothing if the find string is empty, 
 * or longer than one character. If the find string is exactly one character, 
 * replace each occurrence of that character in the string with a sequence 
 * of nodes from the replacement string. If the replacement string is empty, 
 * delete all of the found nodes from the list. New nodes that have been 
 * replaced are not subject to also being replaced -- only nodes that were 
 * present at the time of the command. For example if the list contains 
 * A-C-G-T-A-G (size 6) and you splice("A", "GAT") the resulting list would 
 * be G-A-T-C-G-T-G-A-T-G (size 10) */
 bool	List::splice(std::string find, std::string replace){
	LinkNode* tempNode = first;
	LinkNode* prev = 0; 
	find = upperCase(find);
	replace = upperCase(replace);
	bool successfulSplice = false;
 	

	cout << "\nsplice\t\""<<find<<"\"\t\""<<replace << "\"\n"; //testing 
	if (find.size() == 0){
		return false; //invalid string
	}else if (find.size() > 1){
		return false; //extra credit	
	}
	
	//iterate through the nodes in the list
	//serach for the character in the List
	while (tempNode != 0){ // && (*(tempNode->data)).compare(find) != 0){
		//The node being searched for was found

		//testing 
		LinkNode *testing_node = this->first;
		int count = 0;
		cout << "\ninitial list before loop: ";
		print();
		cout << "size = " << this->size << std::endl;
		while (testing_node != 0){
			if (testing_node == tempNode){
				cout << "letter: " << *(testing_node->data) << 
				"\tindex = " << count << std::endl;
			}else if (testing_node == prev){
				cout << "letter: " << *(testing_node->data) << 
					"\t prev index = " << count << std::endl;
			}else{
				cout << "letter: " << *(testing_node->data) << 
					std::endl; 
			}
			count++;
			testing_node = testing_node->next;
		}

		if ( (*(tempNode->data)).compare(find) == 0){ 
			successfulSplice = true;
			if (replace.size() == 0){ //delete node case
				if (prev == 0){ //head node  
					this->first = tempNode->next;
					tempNode->~LinkNode();
					tempNode = this->first;//this->first->next;
					this->size--;

				}else if ( tempNode->next == 0){ //tail node 

					prev->next = 0;
					tempNode->~LinkNode();
					tempNode = prev; // fix 
					this->size--;
				}else{ //middle node 
					prev->next = tempNode->next;
					tempNode->~LinkNode();
					tempNode = prev;  //prev->next;
					this->size--;
				}
			}else{ //replace node case
				//replace the character with the new node
				List* tempList = strToList(replace); 
				if (prev == 0){ //replace head node
					cout << "replace head\n";
					this->first = tempList->first;
				}else{ //replace body/tail node 
					cout << "replace body/tail\n";
					prev->next = tempList->first;
				}
				cout << "\ttempList b4: ";// testing 
				tempList->print();

				//get previous in the right position TEST FIX
				prev = tempList->first;
				while (prev->next != 0)
					prev = prev->next;


				tempList->append(tempNode->next);
				this->size += tempList->size - 1;

				cout << "\ttempList after: ";// testing 
				tempList->print();

				//clean up 
				tempList->first = 0;
				tempList->~List();
			}
		}
		//testing 
		count = 0;
		testing_node = this->first;
		cout << "\n\tBEFORE INCREMENT : ";
		print();
		cout << "size = " << this->size << std::endl;
		while (testing_node != 0){
			if (testing_node == tempNode){
				cout << "letter: " << *(testing_node->data) << 
				"\ttestingNode is @ index = " << count << std::endl;
			}else if (testing_node == prev){
				cout << "letter: " << *(testing_node->data) << 
					"\t prev index = " << count << std::endl;
			}else{
				cout << "letter: " << *(testing_node->data) << 
					std::endl; 
			}
			count++;
			testing_node = testing_node->next;
		}
		//increment and check for the next node 
		if (size < 2){
			prev = 0;
		}else{
			prev = tempNode;
			tempNode = tempNode->next;
		}

		//testing 
		count = 0;
		testing_node = this->first;
		cout << "\n\tinitial list after loop: ";
		print();
		cout << "size = " << this->size << std::endl;
		while (testing_node != 0){
			if (testing_node == tempNode){
				cout << "letter: " << *(testing_node->data) << 
				"\ttestingNode is @ index = " << count << std::endl;
			}else if (testing_node == prev){
				cout << "letter: " << *(testing_node->data) << 
					"\t prev index = " << count << std::endl;
			}else{
				cout << "letter: " << *(testing_node->data) << 
					std::endl; 
			}
			count++;
			testing_node = testing_node->next;
		}
	}
	cout << "end splice: " ;
	print();
	return successfulSplice;
}

/* A public function named insert(string s) that inserts one or more new nodes 
 * to the start of the list. Do nothing if s is empty. Otherwise create one 
 * new node for each character in the string, inserting the characters in the 
 * string, one per node, into the list in the same order as the string. For 
 * example if you insert "ACGT" into a list that contains A-G (size 2), then 
 * the resulting list would be A-C-G-T-A-G (size 6) */
bool 	List::insert(std::string s){
	s = upperCase(s);
	if (s.size() == 0) 
		return false;
	List* newList = new List( *strToList(s) );
	newList->append(this);
	this->first = newList->first;
	this->size = this->size + newList->size;
	newList->first = 0;
	newList->size = 0;
	newList->~List();
	return true;	
}

/* links nodes of newList at the end of 'this' list */
void	List::append(List* newList){
	LinkNode* lastNode = this->first;
	while (lastNode->next)
		lastNode = lastNode->next;
	lastNode->next = newList->first;
}

/* links nodes of newList at the end of 'this' list */
void 	List::append(LinkNode* newNode){
	LinkNode* lastNode = this->first; 
	while (lastNode->next)
		lastNode = lastNode->next;
	lastNode->next = newNode;
}

/* Converts lowercase strings to uppercase. Returns "" if invalid characters
 * are found */
std::string 	List::upperCase(std::string lowCaseStr){
	std::string	upCaseStr = "";
	
	for (int i = 0; i < lowCaseStr.size(); i++){
		if ( !isalpha(lowCaseStr[i]) )
			return ""; //invalid char found
		upCaseStr.push_back((char) toupper(lowCaseStr[i]));
	}
	return upCaseStr;
}

/* Converts strings to lists, such that each character is a node*/
List*	List::strToList(std::string str){
	List* newList = new List();
	LinkNode* newNode;
	str = upperCase(str);
	for (int i = 0; i < str.size(); i++){
		newNode = new LinkNode();
		newNode->data = new std::string( str.substr(i, 1) );

		if (newList->size == 0){
			newList->first = newNode;
			newList->size++;
		}else{ //append the newNode to the end of the list 
			LinkNode* lastNode = newList->first;
			while (lastNode->next)
				lastNode = lastNode->next;
			lastNode->next = newNode;
			newList->size++;
		}
	}
	return newList;	
}

/* The destructor*/
List::~List(){
	if (first != 0){
		while(first){
			LinkNode* nextNode= first->next;
			delete first;
			first = nextNode;
		}
	}
}

/* Converts list to a string. Includes size in parethesis as first characters*/
std::string	List::toString(){
	std::string str = "";
	LinkNode* temp = first;
	str.append("(");
	str.append(std::to_string(size));
	str.append(")");
	while (temp){
		str.append( *(temp->data) );
		temp = temp->next;
	}
	return str;
}

/* Prints the contents of the list in set format { A, B, ..., etc.} */
void	List::print(){
	LinkNode* temp = first;
	cout << "{";
	while (temp){
		if (temp != first)
			cout << ", ";
		cout << *(temp->data);
		temp = temp->next;
	}
	cout << "}\n";
}


