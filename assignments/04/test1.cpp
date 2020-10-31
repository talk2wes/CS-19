// filetest-sequential.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>


const int LINESIZE=256;

using namespace std;

main(){
  ifstream inF;
  ofstream outF;
  int temp;
  char c[LINESIZE+1];


  inF.open("input.txt");

  if (inF.fail()){
    cerr << "Error opening input.txt" << endl;
    exit(1);
  }

  outF.open("output.txt");

  if (outF.fail()){
    cerr << "Error opening output.txt" << endl;
    exit(1);
  }

  while( inF >> temp ){
     cout << temp << endl;
     outF << temp << endl;
    }
  
  int linenum = 1;
 /* 
  while( inF.getline(c, LINESIZE) ){
    outF << linenum << " " << c << endl;
    linenum++;
  }
*/



}

// filetest-random.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>


const int LINESIZE=256;

using namespace std;

struct Record{
  char name[128];
  int age;
};



main(){
  fstream rwFile;

  rwFile.open("datafile", ios::in | ios::out);



  if (rwFile.fail()){
    cerr << "Error opening datafile" << endl;
    exit(1);
  }

  Record person;

  strcpy(person.name, "Steve J. Hodges");
  person.age = 18;


  rwFile.seekp(0);
  rwFile.write( reinterpret_cast<const char *>( &person), sizeof(person) );

  // int a[10];
  // cout << sizeof(a) / sizeof(int);


  Record inPerson;

  rwFile.seekg(0);
  rwFile.read( reinterpret_cast<char *>( &inPerson), sizeof(Record) );

  cout << inPerson.name << endl;

  rwFile.close();


}
