/* Wesley Johanson	Pengo: wjohanso		Talk2wes@gmail.com
 * Filename: main.cpp
 * Assignment 6: Splicer 
 *
 * Status: Unworking & Untested
 */

#include "splicer.h"

using std::cout;

int	main(int argc, char** argv){
		cout << "testing \n";
		List* myList = new List();	
		cout << "initial size = " << myList->getSize() << "\n";	
		myList->print();
		myList->insert("ABC");
		cout << "size: " << myList->getSize() << "\n";
		myList->insert("RETARD");
		cout << "toString = " << myList->toString() << "\n";
		cout << "deleting myList now\n";
		myList->~List();
		
 }
