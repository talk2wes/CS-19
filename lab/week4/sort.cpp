#include <string>
#include <iostream> 
#include <vector>

using namespace std;
/*
 The functions that don't use pointers are passing by value and don't modify 
 the vector parameters */

// stupid one pass compilter c++ >.> 
int	binarySearch(vector<int> nums, int key); 

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

//should be a pointer parameter 
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
	int search = 24;
	cout << "binary search for value: " << search << endl; 
	if (binarySearch(nums, search) > 0)
		cout << "found " << search << " at index " 
			<< binarySearch(nums,search) << endl;
	else
		cout << "file not found" << endl;
}

// should be a pointer parameter 
void	selectSort(vector<int> nums)
{
	int	bigInd = 0;
	for (int n = nums.size() - 1; n > 0 ; n--)
	{
		//Biggest element starts with the first element
		bigInd = 0;
		//Find the biggest element in 1->n-1.
		for (int i = 1; i < n ; i++)
		{
			//cout << "n: " << n << "\t" << "i: " << i << endl;
			if (nums[i] > nums[bigInd])
				bigInd = i;
		}
		//Compare with the last element in the array and swap if >>
		//cout << "test\n";
		if (nums[bigInd] > nums[n])
		{
			//cout << "test 00\n";

			swap(&nums, bigInd, n);
			//cout << "SWAP" << endl;
			//printVec(nums);
		}
		
	}
	printVec(nums);
}

int	binarySearch(vector<int> nums, int key)
{
	const int NOT_FOUND = -1;
	int hi = nums.size() - 1, low = 0, mid;

	while (low <= hi)
	{
		mid = (hi + low) / 2;
		//cout << "hi = " << hi << " low " << low << endl;
		if (nums[mid] == key)
			return (mid);
		if (key > nums[mid])
			low = mid + 1;
		else
			hi = mid - 1;
	}
	return (NOT_FOUND);
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
