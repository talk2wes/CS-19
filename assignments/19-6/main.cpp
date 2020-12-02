/* Wesley Johanson	Pengo: wjohanso		Talk2wes@gmail.com
 * Filename: main.cpp
 * Assignment 6: Splicer 
 *
 * Status: Unworking & Untested
 */

#include "splicer.h"

using std::cout;

int	main(int argc, char** argv){
		List* myList = new List();	
		std::string temp = "";
		myList->insert("ABCDEFGHIJKLMNOP");
		myList->print();
		cout << "size = " << myList->getSize() << "\n";
		/*
		while (std::cin >> temp){
			myList->insert(temp);
			myList->print();
			cout << myList->getSize() << "\n";

		} */
		while (std::cin >> temp){
			myList->splice(temp, "Piss");
			cout << "return from splice\n";
			myList->print();
			cout << "size = " << myList->getSize() << "\n";
		}
}
