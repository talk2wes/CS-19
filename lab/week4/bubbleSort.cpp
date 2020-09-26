#include <string>
#include <iostream> 
#include <vector>

using namespace std;

void	printVec(vector<int> nums)
{
	
	cout << "{ ";
	for (int i = 0; i < nums.size() ; i++)
	{
		cout << nums.at(i); 
		if (i != nums.size() - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}

void 	bubbleSort(vector<int> nums)
{
	int 	bigger = 0;

	for (int limit = nums.size() - 1; limit > 0; limit--)
	{
		for (int i = 0; i <= limit; i++)
		{
			if (nums.at(i) > nums.at(i + 1))
			{
				//Could turn this into a swap function 
				bigger = nums.at(i);
				nums.at(i) = nums.at(i + 1);
				nums.at(i + 1) = bigger;
			}	
		}
	}
}

int	main()
{
	vector<int> nums{3,9,0,4,11,2,856,35,98,86521,24};
	printVec(nums);
	
	return (0);
}
