#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;
const int MIN_SCAMBLE_LEN = 4;
const char WHITESPACE = ' ';
const char NEWLINE = '\n';

//splits a string with a delimiter into a vector
vector<string> strSplit(string str)
{
	vector<string> tokens;
	stringstream s(str);
	string tempStr = "";

	while (getline(s, tempStr, WHITESPACE))
		tokens.push_back(tempStr);
	return (tokens);
}

//takes input from cin and returns a matrix of words. 
vector<vector<string> > cin2matrix()
{
	vector<vector<string> > matrix;
	vector<string> line; 

	string tempStr = "";
	getline(cin, tempStr);
	line = strSplit(tempStr);
	matrix.push_back(line);
	return(matrix);
}

//Outputs a matrix of words (strings) given the two delimiters.
//delimiters are WHITESPACE and NEWLINE
void matrix2cout(vector<vector<string> > matrix)
{
	for (int i = 0; i < matrix.size() ; i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << WHITESPACE;
		//don't output newline for blank strings/matricies 
		if (matrix[0].size() != 0)
			cout << NEWLINE;
	}
}

//Finds the length of a word in a string, 
//only counting alphabetical characters.
int wordLen(string str)
{
	int length = 0;
	for (int i = 0 ; i < str.length() ; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' ||
			str[i] >= 'a' && str[i] <= 'z')
			length++;
	}
	return(length);
}

//suffles the chars in a string within the indicies [start, stop] (inclusive)
//MAKE SURE THIS IS THE RIGHT RANDOM NUMBER GENERATOR
string shuffleWord(string word, int start, int stop)
{
	int swapInd = -1;
	string shuffledWord = word;

	if (start < 0 || stop < 0 || stop <= start)
		return (word);	
	for (int i = stop; i > start; i--)
	{
		/*
		cout << "\nword: " << word << "\tLen:" << wordLen(word) << endl; 
		cout << "swapping location\ti: " << i << endl
			<< "looking in location: [" << start 
			<< ", " << i << "]" << endl;
		*/
		swapInd = (rand() % (i - start + 1)) + start;
		//cout << "swapInd: " << swapInd << endl; 
		if (swapInd == i)
			return (word);
	}
	return (shuffledWord);
}

vector<vector<string> > shuffleMatrix(vector<vector<string> > matrix)
{
	vector<vector<string> > shuffledMatrix;
	int length = 0;
	for (int row = 0; row < matrix.size(); row++)
	{
		for (int col = 0; col < matrix[row].size(); col++)
		{
			length = wordLen(matrix[row][col]);
			if (length >= MIN_SCAMBLE_LEN)
				matrix[row][col] = shuffleWord(matrix[row][col], 1,
					wordLen(matrix[row][col]) - 2);
		}
	}
	return (shuffledMatrix);
}

int main(int argc, char **argv)
{
	vector<vector<string> > matrix;

	while(!cin.eof()) // not allowed to use this !!!! 
	{
		matrix = cin2matrix();
		shuffleMatrix(matrix);
		matrix2cout(matrix);
	}	
}
