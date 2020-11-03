// Wesley Johanson	Pengo: wjohanso		Talk2wes@gmail.com
// Filename: pattern.cpp
// Assignment 4: Pattern Matching

#include <iostream> 
#include <fstream>
static const int MAX_DIF = 7;		//Minimum str difference to be a match

// Counts the number of different characters that differ in the two strings
int		findDiff(std::string str, std::string userInput)
{
	int diff = 0;
	for (int i = 0; i < str.length(); i++)
		if (str[i] != userInput[i])
			diff++;
	return diff;
}	

// Finds the index of the string that is most simliar to userInput
int		findIndex(std::string strArr[], std::string userInput)
{
	int smallestDiff = 10000;
	int smallestInd = -1;

	//determine if the input is of the correct specifications
	if (userInput.length() != 32) 
		return -1;
	for (int i = 0; i < userInput.length(); i++)
		if (userInput[i] < '0' || userInput[i] > '1')
			return -1;
	
	//Find the most similar string
	for (int i = 0; i < strArr->length(); i++)
	{
		int diff = findDiff(strArr[i], userInput);
		if (diff < smallestDiff)
		{
			smallestInd = i;
			smallestDiff = diff;
		}
	}

	//Check if difference is below the exclusion thresold
	if (smallestDiff <= MAX_DIF)
		return smallestInd;
	return -1;
}

// Opens & reads file into array. Returns the index of the most simliar string
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
	
	tempStr = "";
	while (std::cin >> tempStr)
	{
		int index = findIndex(strArr, tempStr);
		if (index == -1)
			std::cout << "error\n";
		else
			std::cout << index << "\n";
	}
	fin.close();
}

