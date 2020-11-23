/* Wesley Johanson	Pengo: wjohanso		Talk2wes@gmail.com
 * Filename: splicer.h
 * Assignment 6: Splicer */

#ifndef SPLICER_H
	#define SPLICER_H
	#include <iostream>
	
	class		List{

	};

	class		LinkNode{
		friend class List;
	public:
		LinkNode(){ next = 0 ; data = 0; }
		~LinkNode(){ if (data) { delete data; data = 0; } }
	private:
		LinkNode*	next;
		std::string*	data;
	};
#endif


