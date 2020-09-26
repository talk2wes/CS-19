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

//Swaps two adjactent elements in a vector from left to right
void	swapL2R(vector<int> *nums, int i)
{
	int 	bigger = 0;

	bigger = nums->at(i);
	nums->at(i) = nums->at(i + 1);
	nums->at(i + 1) = bigger;
}

void 	bubbleSort(vector<int> nums)
{
	//	int 	bigger = 0;

	for (int limit = nums.size() - 1; limit > 0; limit--)
	{
		for (int i = 0; i < limit; i++)
		{
			cout << "limit = " << limit << "\t" << "i = "
				<< i << endl;
			if (nums.at(i) > nums.at(i + 1))
			{
				cout << "\tlimit = " << limit << "\t" << "i = "
					<< i << endl;
				swapL2R(&nums,i);
				//Could turn this into a swap function 
				/*
				bigger = nums.at(i);
				nums.at(i) = nums.at(i + 1);
				nums.at(i + 1) = bigger;
				*/
			}	
		}
	}
	printVec(nums);
}

int	main()
{
	vector<int> nums{3,9,0,4,11,2,856,35,98,86521,24};
	printVec(nums);
	bubbleSort(nums);

	
	return (0);
}
