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
		cout << "toString: " << myList->toString() << "\n\n";
		if (argc > 1){
			int arg = std::stoi(argv[1]);
			std::string replaceStr = "";
			switch (arg){
				case 1:
					myList->insert("ABCDEABCDEABCDE");
					myList->print();
					cout << "size = " << myList->getSize() << "\n";
					cout << "spice tester\n";
					cout << "replace string =";
					cin >> replaceStr;
					cout << "splice which letter in list?:";
					while (std::cin >> temp){
						myList->splice(temp, replaceStr);
						cout << "main function\n";
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
					cout << "remove tester\n";
					myList->insert("ABCDEABCDEABCDE");
					//myList->insert("");
					myList->print();
					cout << "size = " << myList->getSize() << "\n";
					cout << "what char do you want to remove?: ";
					while (std::cin >> temp){
												myList->print();
						myList->splice(temp , "");
						cout << "\ntoString: " << 
							myList->toString() << "\n";
							cout << "size = " << myList->getSize() << "\n";
						myList->print();
					}
					break;
				default:
					cout << "default case\n";
					break;
			}
		}
}
