// Don't forget to comment code according to requirements

#include "IntSet.h"

// CS19: C++ Integer Sets Program
// Starter Code by Steve J. Hodges
class IntSet{
public:
  IntSet(int =-1,int =-1, int =-1, int =-1, int =-1);
  ~IntSet();  
  void insertElement(int);
  void deleteElement(int);
  std::string toString() const;
  void unionOf(IntSet &, IntSet &);
  void intersectionOf(IntSet &, IntSet &);
  bool equals(const IntSet &) const;
  bool hasElement(int) const;
  int static getMax(){ return MAXSETVAL; }
private:
  static const int MAXSETVAL=1000; // largest legal value
  bool *data; // array to store elements
};


IntSet::insertElement(int num)
{
  if (num >= 0 && num <= MAXSETVAL)
    if (data[num] == 0)
      bool

}

//tSet::IntSet(int a = -1, int b = -1, int c = -1, int d = -1, int e = -1)
IntSet::IntSet(int a,int b, int c, int d, int e)
{
  bool array[1000];
  data = array;

}


