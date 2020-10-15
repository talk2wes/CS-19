// Don't forget to comment code according to requirements

#include "IntSet.h"

void IntSet::insertElement(int num)
{
  if (num >= 0 && num <= MAXSETVAL)
    	data[num] = true;
}

IntSet::~IntSet()
{
	delete []data;
}
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

IntSet::IntSet(int a,int b, int c, int d, int e)
{
  data = new bool[MAXSETVAL + 1];
  insertElement(a);
  insertElement(b);
  insertElement(c);
  insertElement(d);
  insertElement(e);
}
