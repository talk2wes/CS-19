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
	Counter(int countUpTo);

	private:
	int		display;
	int		countMax;

};

//Default Constructor
Counter::Counter()
{
	display = 0;
	countMax = 0;
}

//Overloaded Constructor: such that the counter count's up to the integer given
Counter::Counter(int countUpTo)
{
	display = 0;
	countMax = countUpTo;
}

//Overflow Checker
bool Counter::overflow(int n)
{
	const int	OVERFLOW_COUNT = 9999;
	if (n > OVERFLOW_COUNT)
		return (1);
	return (0);
}

int	main()
{
	int	input;
	cout << "hello world 77" << endl;	
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
