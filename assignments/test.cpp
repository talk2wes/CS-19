#include<string> 
#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	//std::cout << "\U0001F600" << endl;;	
	string c = "\U0001F600";
	for (int i = 0 ; i < 3 ; i++){
		for (int j = 0 ; j < 3; j++){
			cout << c ;
		}
		cout << endl;
	}

	return (0);	
}

