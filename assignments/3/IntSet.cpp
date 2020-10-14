// Don't forget to comment code according to requirements

#include "IntSet.h"

void IntSet::insertElement(int num)
{
  if (num >= 0 && num <= MAXSETVAL)
    data[num] == true;
}

//tSet::IntSet(int a = -1, int b = -1, int c = -1, int d = -1, int e = -1)
IntSet::IntSet(int a,int b, int c, int d, int e)
{
  bool array[MAXSETVAL + 1] = {false};
  data = array;
  insertElement(a);
  insertElement(b);
  insertElement(c);
  insertElement(d);
  insertElement(e);

}


