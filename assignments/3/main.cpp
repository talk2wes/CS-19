#include "IntSet.h"
using namespace std;
// NOTE: this main function test routine must be used for your final submission
// this is not an exhaustive test, so you'll still need to do your own testing!
int main(){  
  IntSet is1(1,6), is2(5, 8, 9), is3;
  is1.toString();
  is2.insertElement(20);
  is2.insertElement(7);
  cout << "is1 =" << is1.toString() << endl; 
  cout << "is2 =" << is2.toString() << endl; 
  cout << "is3 =" << is3.toString() << endl;
  cout << "remove 5 & 8 from is2\n";
  is2.deleteElement(5);
  is2.deleteElement(8);
  cout << "is2 =" << is2.toString() << endl;
  cout << "does is2 have " << 7 << " : " << is2.hasElement(7) << endl;
  cout << "does is2 have " << 3 << " : " << is2.hasElement(3) << endl;

  //new shit 
  is1.unionOf(is2, is3);




  /*
  cout << "is1" << endl; 
  IntSet is1(3); //,is3;
  cout << "is1.toString()\n";
  is1.toString();

  IntSet is3;
  is3.toString();
  */



  /*
  cout << "is2" << endl; 
  IntSet is2(1,2,5);
  cout << "is2.toString()\n" ;
  is2.toString();
  */



  /*
  cout << "CS19 Program #4 Integer Set Class"<<endl;
  cout << "Insert your name and email here" <<endl; 
  is1.insertElement(2);    is1.insertElement(4);
  is1.insertElement(2);    is1.insertElement(3);
  is1.insertElement(5);    is1.insertElement(7);
  is1.deleteElement(3);    is1.deleteElement(7);
  is1.deleteElement(9);

  for(int i=0; i < (is3.getMax()*0.10); i++)
    is3.insertElement( rand()%is3.getMax() );
  cout << "is3 (random): ";
  cout << is3.toString();
  cout <<endl;

  is3.unionOf(is1,is2);
  cout << "is3 (union): ";
  cout << is3.toString();
  cout <<endl;

  is3.intersectionOf(is1,is2);
  cout << "is3 (intersection): ";
  cout << is3.toString();
  cout << endl;

  if (is3.equals(is3))
    cout << "is3.equals(is3)"<<endl;
  if (is1.equals(is2))
    cout << "is1.equals(is2)"<<endl;
  if (is3.equals(is2))
    cout << "is3.equals(is2)"<<endl;
  if (is2.equals(is2))
    cout << "is2.equals(is2)"<<endl;
  
  cout << "is1: ";
  cout << is1.toString();
  	cout << endl;

  if (is1.hasElement(5) ){
    cout <<"is1 contains 5"  << endl;
  } else {
    cout <<"is1 does not contain 5"  << endl;
  }
  if (is1.hasElement(7) ){
    cout <<"is1 contains 7"  << endl;
  } else {
    cout <<"is1 does not contain 7"  << endl;
  }
  */


}

