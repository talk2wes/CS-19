// Don't forget to comment code according to requirements

#include "IntSet.h"
using namespace std;
void IntSet::insertElement(int num)
{
  if (num >= 0 && num <= MAXSETVAL && data != NULL)
    	data[num] = true;
}

void IntSet::deleteElement(int num)
{
	if (num >= 0 && num <= MAXSETVAL && data != NULL)
		data[num] = false;
}

IntSet::~IntSet()
{
	if (data != NULL)
		delete[] data;
	data = NULL;
}

bool 	IntSet::hasElement(int num) const
{
	 if (num >= 0 && num <= MAXSETVAL && data != NULL)
	 	if (data[num] == true)
			return (true);
	 return (false);
}

void	IntSet::intersectionOf(IntSet& setA, IntSet& setB)
{
	//Protect against self-refecence & NULL data
	if ((data == setA.data && data == setB.data) ||
		(setA.data == NULL) || (setB.data == NULL))
		return;
	for (int i = 0; i <= MAXSETVAL; i++)
	{
		if (setA.data[i] == true && setB.data[i] == true)
			this->insertElement(i);
		else
			this->deleteElement(i);
	}
}

bool	IntSet::equals(const IntSet& setA) const
{
	//returns false if either have NULL data
	if (this->data == NULL || setA.data == NULL)
		return false;
	for (int i = 0; i <= MAXSETVAL; i++)
	{
		if (this->data[i] != setA.data[i])
			return (false);
	}
	return (true);
}


void 	IntSet::unionOf(IntSet& setA, IntSet& setB)
{
	//Protect against self-refecence & NULL data
	if ((data == setA.data && data == setB.data) ||
		(setA.data == NULL) || (setB.data == NULL))
		return;
	for (int i = 0; i <= MAXSETVAL; i++)
	{
		if (setA.data[i] == true || setB.data[i] == true)
			this->insertElement(i);
		else
			this->deleteElement(i);
	}
}

string IntSet::toString() const
{
	string 		str = "";
	bool 		firstElementPrinted = false;
	string 		temp;

	if (data == NULL)
		return (str);
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

IntSet::IntSet(int a,int b, int c, int d, int e)
{
  data = new bool[MAXSETVAL + 1];
  insertElement(a);
  insertElement(b);
  insertElement(c);
  insertElement(d);
  insertElement(e);
}
