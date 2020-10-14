// Don't forget to comment code according to requirements

#include "IntSet.h"

void IntSet::insertElement(int num)
{
  if (num >= 0 && num <= MAXSETVAL)
    {
    	data[num] = true;
    	cout << num << " was a valid element to add to the set" << endl; 
    }
    else
    {
    	cout << num << " was NOT a valid element to add to the set" << endl; 
    }
}

string IntSet::toString() const
{
	string 	str = "";

	cout << "TO STRING FUNCTION CALLED\n";
	cout << "{";
	bool 	firstElementPrinted = false;

	for (int i = 0; i <= MAXSETVAL; i++)
	{
		if (data[i] == true)
		{
			cout << i << "\t is true\n";
			/*
			if (firstElementPrinted)
				cout << ", ";
			firstElementPrinted = true;
			cout << i;
			*/
		}
		else 
			cout << i << "\t is false\n";
	}
	cout << "}" << endl;

}

IntSet::IntSet(int a,int b, int c, int d, int e)
{
  data = new bool[MAXSETVAL + 1];
  /*
  bool array[MAXSETVAL + 1];
  for (int i = 0; i <= MAXSETVAL; i++)
  {
  		array[i] = false; 
  		cout << i << "\t is set to false" << endl; 
  }
  data = array;
  */
  insertElement(a);
  insertElement(b);
  insertElement(c);
  insertElement(d);
  insertElement(e);

}


