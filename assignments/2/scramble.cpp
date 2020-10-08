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

	//cout << "\nshuffleword\n" ;						//TESTING 
	if (start < 0 || stop < 0 || stop <= start)
		return (word);
	//cout << "GOT PASSED STOPPER\n";
	
	for (int i = stop; i > start; i--)
	{
		cout << "//word: " << word << "\tLen:" << wordLen(word) << endl; 
		cout << "swapping location i: " << i << endl
			<< "looking in location: [" << start 
			<< ", " << stop << "]" << endl;
		swapInd = (rand() % (stop - start + 1)) + start;
		
	}
	
	return (shuffledWord);
}

vector<vector<string> > shuffleMatrix(vector<vector<string> > matrix)
{
	vector<vector<string> > shuffledMatrix;
	int length = 0;
	//cout << "\nshuffleMatrix" << endl; 				//TESTING 
	for (int row = 0; row < matrix.size(); row++)
	{
		for (int col = 0; col < matrix[row].size(); col++)
		{
			length = wordLen(matrix[row][col]);
			if (length >= MIN_SCAMBLE_LEN)
			{
				//cout << "inside of shuffleMatrix" << endl;
				matrix[row][col] = shuffleWord(matrix[row][col], 1,
						wordLen(matrix[row][col]) - 2);
			}
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
