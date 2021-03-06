/* Wesley Johanson	Pengo: wjohanso		Talk2wes@gmail.com
 * Filename: splicer.h
 * Assignment 6: Splicer */

#ifndef SPLICER_H
	#define SPLICER_H
	#include <iostream>
	#include <string> 	
	#include <cctype> //toUpper toLower etc. 
	#include <stdlib.h>
	
	using 	std::string;

	class		LinkNode{
		friend class List;
	public:
		LinkNode(){ next = 0 ; data = 0; }
		~LinkNode(){ if (data) { delete data; data = 0; } }
	private:
		LinkNode*	next;
		std::string*	data;
	};

	class		List{
	public:
		List(){ first = 0; size = 0; }
		bool		isEmpty(){ return first == 0 ; }
		~List(); // deallocates all objects in list
		int		getSize(){ return size; } // returns length of the list
		std::string	toString(); //returns contents as a string
		void		print(); //print each item in list
		bool 		insert(std::string); //insert at front
		bool		splice(std::string find, std::string replace);
		List*		strToList(std::string);
		void		append(List*);
		void		append(LinkNode*);
		static string	upperCase(std::string);

	private:
		LinkNode*	first;
		int		size;
	};
#endif


