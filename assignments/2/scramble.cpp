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

	while (getline(s, temp, delimiter))
	{
		tokens.push_back(temp);
		cout << temp << endl; 
	}
	return (tokens);

}


int main(int argc, char **argv)
{
	string line = "";
	const char delimiter = ' ';
	const char delimiter2 = '\n';
	vector<string> tokens; 

	while (!cin.eof())
	{
		cout << "enter something in" << endl;
		getline(cin, line, delimiter2);
		tokens = strSplit(line, delimiter);
		cout << "you entered in: " << tokens.size() << endl; 
	}

	
}
