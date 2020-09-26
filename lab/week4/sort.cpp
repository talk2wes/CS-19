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
	int	bigInd = 0;
	for (int n = nums.size() - 2; n > 0 ; n--)
	{
		//Biggest element starts with the first element
		bigInd = 0;
		//Find the biggest element in 1->n-1.
		for (int i = 1; i < n ; i++)
		{
			cout << "n: " << n << "\t" << "i: " << i << endl;
			if (nums[i] > nums[bigInd])
				bigInd = i;
		}
		//Compare with the last element in the array and swap if >>
		if (nums[bigInd] > nums[nums.size() - 1])
		{
			swap(&nums, bigInd, nums.size() - 1);
			cout << "SWAP" << endl;
		}
		
	}
	printVec(nums);
}

int	main()
{
	const vector<int> temp{3,9,0,4,11,2,856,35,98,86521,24};
	vector<int> nums(temp);
	printVec(nums);		//Initial vector
	bubbleSort(nums);	//Bubblesort
	cout << "BubbleSort output \t";
	printVec(nums);		//Show result of bubblesort


	nums = temp;		//Reset nums to the initial state
	

	printVec(nums);		//show that the vector has been reset
	selectSort(nums);	//Select sort 	
	cout << "Select sort output\t";
	printVec(nums);		//Show results of the select sort 
	return (0);
}
