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
	unsigned char	stopChar;

	stopChar = 'Z' + 1;
	while (randChar != stopChar){
		
	}
	newString = "l"; //DUMMY RETURN VALUE 
	return (newString);
}


int	main(int argc, char** argv){
	vector<string>	allNumber;
	long int	totalChars;
	double		average;	

	totalChars = 0;
	allNumber.reserve(NUMBER_OF_STRINGS);
	//generate strings and store them into vector allString
	for (int i = 0; i < NUMBER_OF_STRINGS; i++){
		allNumber[i] = genStr();
		//find sum of all string lengths
		totalChars += (allNumber[i]).length();
		printf("Loop i = %i length = %li\n",i,totalChars); // DEBUGGING
	}
	//divide total string lengths by the number of string to find the mean
	average = (double) totalChars / NUMBER_OF_STRINGS;
	//format the output to one decimal place 
	printf("Average = %.1f\n",average);
	return(0);
}
