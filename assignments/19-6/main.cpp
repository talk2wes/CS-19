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
			if (argc > 1){
			List* myList = new List();	
			std::string temp = "";

			myList->print();
			cout << "initial size = " << myList->getSize() << "\n";
			cout << "toString: " << myList->toString() << "\n\n";
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
		}else{
using std::endl;
	List my_new_list;
	cout << my_new_list.toString() << endl; // (0)
	my_new_list.insert("");
	cout << my_new_list.toString() << endl; // (0)                                        
	my_new_list.insert("a");
	cout << my_new_list.toString() << endl; // (1)A                                       
	my_new_list.insert("BCdB");
	cout << my_new_list.toString() << endl; // (5)BCDBA                                   
	my_new_list.splice("", "");
	cout << my_new_list.toString() << endl; // (5)BCDBA                                   
	my_new_list.splice("B", "C");
	cout << my_new_list.toString() << endl; // (5)CCDCA                                   
	my_new_list.splice("C", "CC");
	cout << my_new_list.toString() << endl; // (8)CCCCDCCA                                
	my_new_list.splice("C", "BAB");
	cout << my_new_list.toString() << endl; // (20)BABBABBABBABDBABBABA                   
	// extra credit tests                                                            
	// without extra credit, no changes to List                                      
	/*
	my_new_list.splice("BA", "DBAD");
	cout << my_new_list.toString() << endl; // (34)DBADBDBADBDBADBDBADBDDBADBDBADDBAD     
	my_new_list.splice("BAD", "E");
	cout << my_new_list.toString() << endl; // (20)DEBDEBDEBDEBDDEBDEDE                   
	my_new_list.splice("DEB", "A");
	cout << my_new_list.toString() << endl; // (10)AAAADADEDE
	my_new_list.splice("DE", "F");
	cout << my_new_list.toString() << endl; // (8)AAAADAFF
	*/
	//regular tests
	my_new_list.splice("A", "");
	cout << my_new_list.toString() << endl; // (3)DFF                                                      
	my_new_list.splice("F","");
	cout << my_new_list.toString() << endl; // (1)D                                                        
	my_new_list.splice("D","");
	cout << my_new_list.toString() << endl; // (0)
	}
}
