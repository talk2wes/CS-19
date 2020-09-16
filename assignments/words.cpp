#include <string>
#include <iostream>
#include <cmath> 
#include <vector>
using namespace std;

unsigned const int	NUMBER_OF_STRINGS = pow(10, 6);

// Generates a random string within the ascii values specified
string	genStr(){
	string 		newString;
	unsigned char	randChar;
	
	newString = ""; //DUMMY RETURN VALUE 
	return (newString);
}


int	main(int argc, char** argv){
	vector<string>	allNumber;
	int		totalChars;
	double		average;	

	allNumber.reserve(NUMBER_OF_STRINGS);
	//generate strings and store them into vector allString
	for (int i = 0; i < NUMBER_OF_STRINGS; i++){
		printf("Loop i = %i\n",i);
		allNumber[i] = genStr();
	}
	//find sum of all string lengths
	//divide total string lengths by the number of string to find the mean
	//format the output to one decimal place 
	return(0);
}
