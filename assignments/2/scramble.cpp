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
	while (!cin.eof())
	{
		//cout << "enter something in" << endl;
		getline(cin, temp, delimiter);
		cout << "input:\t" << temp << endl;
		//lines = istr2vec(cin, delimiter2);
		line = strSplit(temp, delimiter2);
		mat.push_back(line);
		cout << "\tnumOfWords: " << line.size() << endl; 
	}
	return(mat);
}

void mat2cout(vector<vector<string> > mat, const char delimiter,
		const char delimiter2)
{
	for (int i = 0; i < mat.size() ; i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			cout << mat[i][j] << delimiter;
		}
		cout << delimiter2;
	}
}

int main(int argc, char **argv)
{
	string line = "";
	const char WHITESPACE = ' ';
	const char NEWLINE = '\n';
	vector<string> lines; 
	vector<vector<string> > mat;

	mat = cin2mat(NEWLINE, WHITESPACE);
	cout << "rows of mat: " << mat.size() << endl;
	mat2cout(mat,WHITESPACE, NEWLINE);
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
