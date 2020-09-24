/*
 * CS19 Programming Assignment #1 Part 1
 * Filename: words.cpp 
 * This program is designed to generate a series of strings
 * specified by userNumStr and stores them into a vector named
 * allStr. The length of each string in allStr is summed into totalChars
 * and then divided by the userNumStr to calculate a mean. 
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
#include <stdlib.h>
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
	double			average = 0;	
	int 			userNumStr = 0;

	cout << "argc = " << argc << endl; // TESTING 
	userNumStr = NUMBER_OF_STRINGS;
	if (argc == 2){
		cout << "atoi = " << atoi(argv[1]) << endl; // TESTING 
		if (atoi(argv[1]) != 0 && atoi(argv[1]) > 0)
			userNumStr = atoi(argv[1]);
	}
	cout << "userNumStr = " << userNumStr << endl;
	allStr.reserve(userNumStr);
	for (int i = 0; i < userNumStr; i++){
		allStr[i] = genStr();
		totalChars += (allStr[i]).length();
	}
	average = (double) totalChars / userNumStr;
	cout << fixed << showpoint << setprecision(1);
	cout << "CS 19 Assignment #1 Random String Generator " << endl;
	cout << "Wesley Johanson Talk2wes@gmail.com " << endl;
	cout << "Mean = " << average << endl;
		return(0);
}
