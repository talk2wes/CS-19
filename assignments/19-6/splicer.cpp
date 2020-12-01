/* Wesley Johanson	Pengo: wjohanson	Talk2wes@gmail.com
 * Filename: splicer.cpp
 * Assignment 6: Splicer */

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
	return true;
 }

/* A public function named insert(string s) that inserts one or more new nodes 
 * to the start of the list. Do nothing if s is empty. Otherwise create one 
 * new node for each character in the string, inserting the characters in the 
 * string, one per node, into the list in the same order as the string. For 
 * example if you insert "ACGT" into a list that contains A-G (size 2), then 
 * the resulting list would be A-C-G-T-A-G (size 6) */

bool 	List::insert(std::string s){
	cout << "string passed = " << s << "\n";
	//idk how to check is s is a null string. OHH it's not a pointer 

	if (s.size() == 0) // size = 0 case 
		return false;
	//case size = 1 OR > 1 
	List* newList = new List( *strToList(s) );
	newList->append(this);
	this->first = newList->first;
	this->size = this->size + newList->size;
	newList->first = 0;
	newList->size = 0;
	cout << "this list = ";
	this->print(); //testing 
	newList->~List();
	return true;	
}

/* links newList at the end of this list */
void	List::append(List* newList){
	LinkNode* lastNode = this->first;
	while (lastNode->next)
		lastNode = lastNode->next;
	lastNode->next = newList->first;
}

List*	List::strToList(std::string str){
	List* newList = new List();
	LinkNode* newNode;
	for (int i = 0; i < str.size(); i++){
		newNode = new LinkNode();
		//make case insensitive & exclude invalid characters 
		//std::string character = str.substr(i, 1);
		newNode->data = new std::string( str.substr(i, 1) );
		
		cout << "\n";
		cout << "*(newNode->data) = " << *(newNode->data) << "\n";
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
		cout << "newList = ";
		newList->print(); //testing 
	}
	return newList;	
}


List::~List(){
	cout << "the destructor was called \n";
	if (first != 0){
		while(first){
			LinkNode* temp = first->next;
			cout << "deleting: " << *(first->data) << "\n";
			delete first;
			first = temp;
		}
	}
}

std::string	List::toString(){
	std::string str = "";
	LinkNode* temp = first;
	while (temp){
		str.append( *(temp->data) );
		temp = temp->next;
	}
	return str;
}

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


