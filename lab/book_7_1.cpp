/*
Define a class called Month that is an abstract data type for a month. Your class will have one member variable of type int to represent a month (1 for January, 2 for February, and so forth). Include all the following member functions: a construc- tor to set the month using the first three letters in the name of the month as three arguments, a constructor to set the month using an integer as an argument (1 for January, 2 for February, and so forth), a default constructor, an input function that reads the month as an integer, an input function that reads the month as the first three letters in the name of the month, an output function that outputs the month as an integer, an output function that outputs the month as the first three letters in the name of the month, and a member function that returns the next month as a value of type Month. Embed your class definition in a test program.
*/
#include <iostream>
#include <string>

using namespace std;


string	toUpper(string str_org);

class	month
{
	public:
	// 1 - January 2 - February .... 12 - Dec
	int	index;

	month(string month);

	private:
};

int	main(int argc, char** arv)
{
	string testing = "this is a lower case string";
	month jan = month("JAN");
	// testing output of toUpper
	cout << "before function\n" << testing << endl;
	cout << toUpper(testing) << endl;
	return (0);	
}

string toUpper(string str_org){
	string	str_final;
	str_final = str_org;
	char test_char = 'x'; // testing 
	
	for (int i = 0 ; str_org[i] ; i++)
	{
		if (str_org[i] >= 'a' && str_org[i] <= 'z'){
		str_final[i] = str_org[i] + ('A' - 'a');
		} else {
		str_final[i] = str_org[i];
		}
	}
	return (str_final);
};

month::month(string month)
{
	// finish thiss function
	index = 1;
	//cout << month << endl;
}
