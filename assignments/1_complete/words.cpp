/*
 * CS19 Programming Assignment #1 
 * Filename: words.cpp 
 * This program is designed to generate a series of strings
 * specified by userNumStr and stores them into a vector named
 * allStr. The length of each string in allStr is summed into totalChars
 * and then divided by the userNumStr to calculate a mean. 
 * Working/tested. Code Compile, works as expected.
 * 
 * NOTE: the random number generator will generate the same sequence of random
 * numbers (and strings) because it doesn't have a time dependent seed value
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
const int		MAX_USER_INPUT = 78951604;

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

double		meanLength(vector<int> *strLen){
	double	mean = 0;
	long	sum = 0;
	for (int i = 0; i < strLen->capacity() ; i++)
			sum += (*strLen)[i]; //(*strLen)[i];
	mean = (double) sum / strLen->capacity();
	return (mean);	
}

double		stdDev(vector<int> *strLen)
{	double rieSum = 0;
	double mean = meanLength(strLen);

	for (int i = 0; i < strLen->capacity() ; i++)
	{
		rieSum += pow((*strLen)[i] - mean, 2);
	}
	rieSum /= strLen->capacity();
	return (sqrt(rieSum));
}


int	main(int argc, char** argv){
	vector<string>		allStr;
	vector<int>		strLen;
	unsigned long int	totalChars = 0;
	double			average = 0;	
	int 			userNumStr = 0;
	double 			stdDeviation = 0;	

	//Determine the number of stings to generate
	userNumStr = NUMBER_OF_STRINGS;
	if (argc == 2){
		if (atoi(argv[1]) != 0 && atoi(argv[1]) > 0
			&& atoi(argv[1]) <= MAX_USER_INPUT){
		userNumStr = atoi(argv[1]);
		}
	}
	strLen.reserve(userNumStr);
	allStr.reserve(userNumStr);

	//Generate strings, store length
	for (int i = 0; i < userNumStr; i++){
		/* so the g++ compiler DOES NOT LIKE ARRAY notation!!
		* ONLY CLANG 
		allStr[i] = genStr();
		strLen[i] = allStr[i].length();
		*/
		allStr.push_back(genStr());
		strLen.push_back(allStr[1].length());
	}
	//Calculate statistics off data generated
	average = meanLength(&strLen);
	stdDeviation = stdDev(&strLen);
	cout << fixed << showpoint << setprecision(1);
	cout << "CS 19 Assignment #1 Random String Generator " << endl;
	cout << "Wesley Johanson Talk2wes@gmail.com " << endl;
	cout << userNumStr << " random strings generated" << endl;
	cout << "first string:" << allStr[0] << endl
		<< "last string:" << allStr[userNumStr - 1] << endl;
	cout << average << " mean length" <<  endl;
	cout << stdDeviation << " std dev" << endl; 
		return(0);
}
