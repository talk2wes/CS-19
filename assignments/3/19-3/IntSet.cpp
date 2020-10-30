// Wesley Johanson	Pengo:wjohanso	Talk2wes@gmail.com
// Filename: IntSet.cpp
// Assignment 3: Integer Set Class

#include "IntSet.h"
using namespace std;

//Inserts an element into the set. Given the parameter is within range.
void IntSet::insertElement(int num)
{
  if (num >= 0 && num <= MAXSETVAL)
    	data[num] = true;
}

//Deletes an element in the set. Given the parameters is within range.
void IntSet::deleteElement(int num)
{
	if (num >= 0 && num <= MAXSETVAL)
		data[num] = false;
}

//Destructor. Deletes the array 'data' from the object 
IntSet::~IntSet()
{
	if (data != NULL)
		delete[] data;
	data = NULL;
}

//Returns true if the element passed is an element of the set.
bool 	IntSet::hasElement(int num) const
{
	 if (num >= 0 && num <= MAXSETVAL)
	 	if (data[num] == true)
			return (true);
	 return (false);
}

//Finds the intersection of sets setA and setB. Assigns this set to the 
//object this method was envoked on.
void	IntSet::intersectionOf(IntSet& setA, IntSet& setB)
{
	//Protect against self-refecence & NULL data
	if (data == setA.data && data == setB.data)
		return;
	for (int i = 0; i <= MAXSETVAL; i++)
	{
		if (setA.data[i] == true && setB.data[i] == true)
			this->insertElement(i);
		else
			this->deleteElement(i);
	}
}

//Returns true if the sets are equivalent.
bool	IntSet::equals(const IntSet& setA) const
{
	for (int i = 0; i <= MAXSETVAL; i++)
	{
		if (this->data[i] != setA.data[i])
			return (false);
	}
	return (true);
}


//Finds the union of setA and setB. Assigns this set to the object
//that this method was envoked on.
void 	IntSet::unionOf(IntSet& setA, IntSet& setB)
{
	//Protect against self-refecence & NULL data
	if (data == setA.data && data == setB.data)
		return;
	for (int i = 0; i <= MAXSETVAL; i++)
	{
		if (setA.data[i] == true || setB.data[i] == true)
			this->insertElement(i);
		else
			this->deleteElement(i);
	}
}

//Returns a string of the set in standard curly brace notation
// e.g. {x1, x2, x3, ...,xn}
string IntSet::toString() const
{
	string 		str = "";
	bool 		firstElementPrinted = false;
	string 		temp;

	str.append("{");
	for (int i = 0; i <= MAXSETVAL; i++)
	{
		if (data[i] == true)
		{
			if (firstElementPrinted)
				str.append(", ");
			firstElementPrinted = true;
			str.append(to_string(i));
		}
	}
	str.append("}");
	return (str);
}

//Default Constructor. Allows 0 - 5 arguments of type int
IntSet::IntSet(int a,int b, int c, int d, int e)
{
  data = new bool[MAXSETVAL + 1];
  insertElement(a);
  insertElement(b);
  insertElement(c);
  insertElement(d);
  insertElement(e);
}
