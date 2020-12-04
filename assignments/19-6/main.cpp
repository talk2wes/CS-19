/* Wesley Johanson	Pengo: wjohanso		Talk2wes@gmail.com
 * Filename: main.cpp
 * Assignment 6: Splicer 
 *
 * Status: Unworking & Untested
 */

#include "splicer.h"

using std::cout;
using std::cin;

int	main(int argc, char** argv){
		List* myList = new List();	
		std::string temp = "";

		myList->print();
		cout << "initial size = " << myList->getSize() << "\n";
		cout << "toString: " << myList->toString() << "\n";
		if (argc > 1){
			int arg = std::stoi(argv[1]);
			std::string replaceStr = "";
			switch (arg){
				case 1:
					myList->insert("ABCDEFGHIJKLMNOP");
					myList->print();
					cout << "size = " << myList->getSize() << "\n";
					cout << "spice tester\n";
					cout << "replace string =";
					cin >> replaceStr;
					while (std::cin >> temp){
						cout << "splice which letter in list?:";
					myList->splice(temp, replaceStr);
					myList->print();
					cout << "size = " << myList->getSize() << "\n";
					}
					break;
				case 2:
					cout << "insert tester\n";
					while (std::cin >> temp){
						myList->insert(temp);
						myList->print();
						cout << "toString: " << 
							myList->toString() << "\n";
						cout << "size = " << myList->getSize() << "\n";
						myList->print();
					} 
					break;
				case 3:
					cout << "3 \n";
					break;
				default:
					cout << "default case\n";
					break;
			}
		}
}
