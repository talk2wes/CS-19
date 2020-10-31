#include <iostream> 
#include <fstream>
static const int MIN_DIF = 7;	//Minimum difference to be a match

int		findDiff(std::string str, std::string userInput)
{
	int diff = 0;
	for (int i = 0; i < str.length(); i++)
		if (str[i] != userInput[i])
			diff++;
	return diff;
}	

/*
	//std::cout << "FIND DIFF ::::::\n";
	int diff = 0;
	int smallest = 1000;
	int smallestInd = -1;
	for (int i = 0; i < strArr->length(); i++)
	{
		diff = 0;
		//std::cout << "\nstrArr[" << i << "]=\t" << strArr[i] <<std::endl;
		//std::cout << "userInput=\t" << userInput << std::endl;
		for (int j = 0 ; j < strArr[i].length(); j++)
			if (strArr[i][j] != userInput[j])
				diff++;
		//std::cout << "diff:" << diff << std::endl;
		if (diff < smallest)
		{
			smallest = diff;
			smallestInd = i;
		}
	}
	//std::cout << "smallestInd:" << smallestInd << std::endl;
	if (smallest <= MIN_DIF)
		return smallestInd;
	return -1;
}
*/

int		findIndex(std::string strArr[], std::string userInput)
{
	int smallestDiff = 10000;
	int smallestInd = -1;
	for (int i = 0; i < strArr->length(); i++)
	{
		int diff = findDiff(strArr[i], userInput);
		//std::cout << "diff[" << i << "] =\t" << diff << std::endl;
		if (diff < smallestDiff)
		{
			//std::cout << "NEW SMALLEST FOUND\n";
			smallestInd = i;
			smallestDiff = diff;
		}
	}
	if (smallestDiff <= MIN_DIF)
		return smallestInd;
	return -1;
}

int		main(int argc, char** argv)
{
	const static std::string FILENAME = "patterns.txt";
	std::string 	strArr[32];
	std::string 	tempStr = "";
	std::ifstream 	fin;
	std::ofstream 	fout;

	//open the file 
	fin.open(FILENAME);
	if (fin.fail())
		std::cout << "Failed to open file \"" << FILENAME << "\"";

	//Store the file into an array
	int i = 0;
	while (fin >> tempStr)
		strArr[i++] = tempStr;
	
	//testing that I actually have it in an array;
	/*
	i = 0;
	while (i < 32) 
		std::cout << "strArr:"<< strArr[i++] << std::endl;
	*/

	//Keep running each cin input into the program until EOF 
	tempStr = "";
	while (std::cin >> tempStr)
	{
		int index = findIndex(strArr, tempStr);
		if (index == -1)
			std::cout << "error\n";
		else
			std::cout << index << "\n";
	}

	fin.close(); //DON'T CLOSE THE FILE UNTIL THE END DUMBASS >.>
}

