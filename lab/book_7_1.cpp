/*
Define a class called Month that is an abstract data type for a month. Your class will have one member variable of type int to represent a month (1 for January, 2 for February, and so forth). Include all the following member functions: a construc- tor to set the month using the first three letters in the name of the month as three arguments, a constructor to set the month using an integer as an argument (1 for January, 2 for February, and so forth), a default constructor, an input function that reads the month as an integer, an input function that reads the month as the first three letters in the name of the month, an output function that outputs the month as an integer, an output function that outputs the month as the first three letters in the name of the month, and a member function that returns the next month as a value of type Month. Embed your class definition in a test program.
*/
#include <iostream>
#include <string>

using namespace std;

class	month
{
	public:
	// 1 - January 2 - February .... 12 - Dec
	int	month_index;

	month(string month);

	private:
};

int	main(int argc, char** arv)
{
	cout << "Hello world" << endl;
	month jan = month("JAN");
	return (0);	
}

month::month(string month)
{
	month_index = 1;
	cout << month << endl;
	printf("the month index = %i\n",month_index);	
}
