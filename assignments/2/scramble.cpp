/*
 * CS19 Programming Assignment #2
 * Filename: scramble.cpp
 * This program takes input from STDIN, scrambles the characters in each word 
 * and outputs the scrambled words to STDOUT. First and last characters 
 * are not scrambled. Newlines and whitespace info is conserved.
 *
 * Working/tested. Code Compiles. I had major difficulty trying to get 
 * redirections to output the first character of all the lines input.
 *
 * @Author Wesley Johanson, talk2wes@gmail.com, Pengo: wjohanso
 * @Version: 1.0
 * @Since Fall 2020 Semester.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int					MIN_SCAMBLE_LEN = 4;
const char					WHITESPACE = ' ';
const char					NEWLINE = '\n';

//splits a string into a vector of words, delimited by whitespace
vector<string> 				strSplit(string str)
{
	vector<string>			tokens;
	stringstream 			s(str);
	string 					tempStr = "";

	while (getline(s, tempStr, WHITESPACE))
		tokens.push_back(tempStr);
	return (tokens);
}

//takes input from cin and returns a matrix of words. Each line becomes a row 
//and each word becomes a column in the matrix. 
vector<vector<string> >		cin2matrix()
{
	vector<vector<string> > matrix;
	vector<string> 			line; 
	string					tempStr = "";

	getline(cin, tempStr);		//get a line
	line = strSplit(tempStr);	//split line into a vector of words
	matrix.push_back(line);		//add this row of words to the matrix
	return(matrix);
}

//Outputs a matrix of words (strings) to STDOUT
void						matrix2cout(vector<vector<string> > matrix)
{
	for (int i = 0; i < matrix.size() ; i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << WHITESPACE;
		if (matrix[0].size() != 0)		//don't output newline at end of input
			cout << NEWLINE;
	}
}

//Finds the length of a word in a string, counting only alphabet characters.
int							wordLen(string str)
{
	int						length = 0;
	
	for (int i = 0 ; i < str.length() ; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' ||
			str[i] >= 'a' && str[i] <= 'z')
			length++;
	}
	return(length);
}

//Swaps two characters in a string, specified by the two indicies: i, j
void						swapChar(string* str, int i, int j)
{
	char 					temp = (*str)[i];
	
	(*str)[i] = (*str)[j];
	(*str)[j] = temp;
}

//Shuffles a characters in a string within the indicies: start, stop. 
//Boundaries are inclusive
void						shuffleWord(string* word, int start, int stop)
{
	int 					swapInd = -1;

	if (start < 0 || stop < 0 || stop <= start)
		return;	
	for (int i = stop; i > start; i--)
	{
		swapInd = (rand() % (i - start + 1)) + start;
		swapChar(word, swapInd, i);		
	}
}

//Individually shuffles characters in each word within the matrix
void						shuffleMatrix(vector<vector<string> >* matrix)
{
	vector<vector<string> > shuffledMatrix;
	int 					length = 0;

	for (int row = 0; row < (*matrix).size(); row++)
	{
		for (int col = 0; col < (*matrix)[row].size(); col++)
		{
			length = wordLen((*matrix)[row][col]);
			if (length >= MIN_SCAMBLE_LEN)
				shuffleWord(&(*matrix)[row][col], 1, 
					length - 2);								
		}
	}
}

int 						main(int argc, char **argv)
{
	vector<vector<string> > matrix;
	
	srand(time(NULL));
	while(cin)
	{
		matrix = cin2matrix();
		shuffleMatrix(&matrix);
		matrix2cout(matrix);
	}	
}
