#ifndef FILLIT_H
	#define FILLIT_H
	
	#include <iostream>			//cout 
	#include <cstdlib>			//rand
	#include <vector>			
	using namespace std;

	// CS19: C++ Integer Sets Program
	// Starter Code by Steve J. Hodges
	class IntSet{
	public:
	  IntSet(int =-1,int =-1, int =-1, int =-1, int =-1);
	  void insertElement(int);
	  /*
	  ~IntSet();  
	  
	  void deleteElement(int);
	  std::string toString() const;
	  void unionOf(IntSet &, IntSet &);
	  void intersectionOf(IntSet &, IntSet &);
	  bool equals(const IntSet &) const;
	  bool hasElement(int) const;
	  int static getMax(){ return MAXSETVAL; }
	  */
	private:
	  static const int MAXSETVAL=1000; // largest legal value
	  bool *data; // array to store elements
	};

#endif