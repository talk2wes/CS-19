#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
//#include <stdio.h>

using namespace std;



vector<string> strSplit(string str,const char delimiter)
{
	vector<string> tokens;
	
	stringstream s(str);
	string temp = "";

	//cout << "strSplit: "; 			//TESTING 
	while (getline(s, temp, delimiter))
	{
		tokens.push_back(temp);
		//cout << temp << delimiter; 			//testing 
	}
	//cout << endl; 					//testing 
	return (tokens);

}

vector<vector<string> > cin2mat( const char delimiter, 
		const char delimiter2)
{
	vector<vector<string> > mat;
	vector<string> line; 


	string temp = "";
	//while (!cin.eof())
	//{
		//cout << "enter something in" << endl;
		//if (cin.hasNext())
			getline(cin, temp, delimiter);
			//cout << "getline:" << temp <<endl;		//TESTING 
		//cout << "input:\t" << temp << endl;
		//lines = istr2vec(cin, delimiter2);
		line = strSplit(temp, delimiter2);
		mat.push_back(line);
		//cout << "mat:" << mat.back().back() << endl;	//TESTING 
		//cout << "\tnumOfWords: " << line.size() << endl; 
	//}
	return(mat);
}

void mat2cout(vector<vector<string> > mat, const char delimiter,
		const char delimiter2)
{
	for (int i = 0; i < mat.size() ; i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			cout << mat[i][j] /*.length()*/ << delimiter;
		}
		cout << delimiter2;
	}
}

int wordLen(string str)
{
	int length = 0;
	cout << "wordLen, str passed: " << str << endl; 
	for (int i = 0 ; i < str.length() ; i++)
	{
		cout << "testing: " << str[i] << "ascii dec: " << (int) str[i] << endl; 
		if (str[i] >= 'A' && str[i] <= 'Z' ||
			str[i] >= 'a' && str[i] <= 'z')
			length++;
		
	}
	return(length);
}

vector<vector<string> > scramble(vector<vector<string> > mat)
{
	vector<vector<string> > scrambledEggs;
	int length = 0;

	for (int row = 0; row < mat.size(); row++)
	{
		for (int col = 0; col < mat[row].size(); col++)
		{
			length = wordLen(mat[row][col]);
			cout << "length: " << length << endl; 			//testing 

		}
	}
	return (scrambledEggs);
}



int main(int argc, char **argv)
{
	string line = "";
	const char WHITESPACE = ' ';
	const char NEWLINE = '\n';
	vector<string> lines; 
	vector<vector<string> > mat;

	while(!cin.eof())
	{
	mat = cin2mat(NEWLINE, WHITESPACE);
	//cout << "rows of mat: " << mat.size() << endl;
	//cout << "mat2cout output\n";

	mat = scramble(mat);

	mat2cout(mat,WHITESPACE, NEWLINE);
	}
	/*
	while (!cin.eof())
	{
		cout << "enter something in" << endl;
		getline(cin, line, delimiter2);
		
		//lines = istr2vec(cin, delimiter2);
		

		lines = strSplit(line, delimiter);
		cout << "number of words entered in: " << lines.size() << endl; 
	}
	*/

	
}
