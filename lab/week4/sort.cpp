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

//Swaps two adjactent elements, (L) && (L + 1)
void	swapL2R(vector<int> *nums, int L)
{
	int 	bigger = 0;

	bigger = nums->at(L);
	nums->at(L) = nums->at(L + 1);
	nums->at(L + 1) = bigger;
}
void	swap(vector<int> *nums, int x, int y)
{
	int 	temp = 0;

	temp = nums->at(x);
	nums->at(x) = nums->at(y);
	nums->at(y) = temp;

}

void 	bubbleSort(vector<int> nums)
{
	//	int 	bigger = 0;

	for (int limit = nums.size() - 1; limit > 0; limit--)
	{
		for (int i = 0; i < limit; i++)
		{
			//cout << "limit = " << limit << "\t" << "i = "
			//	<< i << endl;
			if (nums.at(i) > nums.at(i + 1))
			{
			//	cout << "\tlimit = " << limit << "\t" << "i = "
			//		<< i << endl;
				swapL2R(&nums,i);
			}	
		}
	}
	printVec(nums);
}

void	selectSort(vector<int> nums)
{
	cout << "heee hehee" << endl;
}

int	main()
{
	vector<int> nums{3,9,0,4,11,2,856,35,98,86521,24};
	printVec(nums);
	bubbleSort(nums);
	return (0);
}
