// Wesley Johanson	Pengo:wjohanso	Talk2wes@gmail.com
// Filename: IntSet.h
// Assignment 3: Integer Set Class

#ifndef FILLIT_H
	#define FILLIT_H
	
	#include <iostream>			
	#include <cstdlib>			
	#include <string>
	
	// CS19: C++ Integer Sets Program
	class IntSet{
	public:
	  		IntSet(int =-1,int =-1, int =-1, int =-1, int =-1);
	  		~IntSet();
	  void 		insertElement(int);
	  std::string 	toString() const;
	  int static 	getMax(){ return MAXSETVAL; }
	  void		deleteElement(int);
	  void 		unionOf(IntSet &, IntSet &);
	  bool 		hasElement(int) const;
	  void		intersectionOf(IntSet &, IntSet &);
	  bool		equals(const IntSet &) const;

	private:
	  static const int 	MAXSETVAL=1000; // largest legal value
	  bool 				*data; // array to store elements
	};

#endif
