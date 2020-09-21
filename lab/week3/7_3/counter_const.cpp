#include <string>
#include <iostream> 
using namespace	std;

class Counter
{
	public:
	void		reset();
	void		incr1();
	void		incr10();
	void		incr100();
	void		incr1000();
	bool		overflow(int n);
	Counter();
	//Counter(int countUpTo);

	/* Display is the value that the counter displays,
	 * countMax is the maximum value that the counter can take on */
	private:
	int			display;
	const int			countMax;
	static const int	OVERFLOW_MAX = 9999;
};

int	main()
{
	int	input;
	cout << "Put in a number.... or else"  << endl;	
	//cin >> input;
	//While the input is an integer, run loop
	while(!(cin >> input)){
		cout << "You didn't enter a number: " << input << endl;
		cin >> input;
		cin.clear(); //Clear the error flag
		cin.ignore(100000,'\n'); //Skip to the next line, up to n chars
	}
	cout << "you entered a number, you entered: " << input << endl;
		
}

//Default Constructor
Counter::Counter() : countMax(OVERFLOW_MAX)
{
	display = 0;
	//countMax = OVERFLOW_MAX;
}
/*
//Overloaded Constructor: such that the counter count's up to the integer given
Counter::Counter(int countUpTo)
{
	display = 0;
	if (countUpTo <= OVERFLOW_MAX && countUpTo >=0)
	{
		countMax = countUpTo;
	}else
	{
		countMax = OVERFLOW_MAX;
		cout << "ERROR: value given is outside of the range";
		cout << " of the counter" << endl;
	}
}
*/

//Overflow Checker
bool Counter::overflow(int n)
{
	if (n > OVERFLOW_MAX)
		return (1);
	return (0);
}

void	Counter::reset()
{
	display = 0;
	//countMax = OVERFLOW_MAX;
}

