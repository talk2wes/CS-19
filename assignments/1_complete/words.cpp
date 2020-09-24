/*
 * CS19 Programming Assignment #1 Part 1
 * Filename: words.cpp 
 * This program is designed to generate a series of strings
 * specified by NUMBER_OF_STRINGS and stores them into a vector named
 * allStr. The length of each string in allStr is summed into totalChars
 * and then divided by the NUMBER_OF_STRINGS to calculate a mean. 
 * Working/tested. Code Compile, works as expected.
 *
 * @Author Wesley Johanson, talk2wes@gmail.com, Pengo: wjohanso
 * @Version: 1.0
 * @Since Fall 2020 Semester.
*/
#include <string>
#include <iostream>
#include <cmath> 
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace 	std;
unsigned const int	NUMBER_OF_STRINGS = pow(10, 6);

// Generates a random string within the ascii values specified
char	genChar(char min, char max){
	char	randChar;
	
	randChar = rand() % (max - min + 1) + min;
	return (randChar);
}

// Generates a random string with char's between 'A' and 'Z' on the ascii table
string		genStr(){
	string 		newString;
	char	randChar;
	char	stopChar;

	stopChar = 'Z' + 1;
	newString = "";
	randChar = genChar('A', 'Z');
	while (randChar != stopChar){
		newString.push_back(randChar);
		randChar = genChar('A', 'Z' + 1);
	}
	return (newString);
}




int	main(int argc, char** argv){
	vector<string>		allStr;
	unsigned long int	totalChars = 0;
	double			average;	
	
	allStr.reserve(NUMBER_OF_STRINGS);
	for (int i = 0; i < NUMBER_OF_STRINGS; i++){
		allStr[i] = genStr();
		totalChars += (allStr[i]).length();
	}
	average = (double) totalChars / NUMBER_OF_STRINGS;
	cout << fixed << showpoint << setprecision(3);
	cout << "Mean = " << average << endl;
		return(0);
}
