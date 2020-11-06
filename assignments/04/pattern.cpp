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
	else
		return -1;
}

// Opens & reads file into array. Returns the index of the most simliar string
int		main(int argc, char** argv)
{
	const static std::string FILENAME = "patterns.txt";
	std::string 	strArr[32];
	std::string 	tempStr = "";
	

	int i = 0;
	strArr[i++] = "00000000000000000000000000000000";
	strArr[i++] = "01010101010101010101010101010101";
	strArr[i++] = "00110011001100110011001100110011";
	strArr[i++] = "01100110011001100110011001100110";
	strArr[i++] = "00001111000011110000111100001111";
	strArr[i++] = "01011010010110100101101001011010";
	strArr[i++] = "00111100001111000011110000111100";
	strArr[i++] = "01101001011010010110100101101001";
	strArr[i++] = "00000000111111110000000011111111";
	strArr[i++] = "01010101101010100101010110101010";
	strArr[i++] = "00110011110011000011001111001100";
	strArr[i++] = "01100110100110010110011010011001";
	strArr[i++] = "00001111111100000000111111110000";
	strArr[i++] = "01011010101001010101101010100101";
	strArr[i++] = "00111100110000110011110011000011";
	strArr[i++] = "01101001100101100110100110010110";
	strArr[i++] = "00000000000000001111111111111111";
	strArr[i++] = "01010101010101011010101010101010";
	strArr[i++] = "00110011001100111100110011001100";
	strArr[i++] = "01100110011001101001100110011001";
	strArr[i++] = "00001111000011111111000011110000";
	strArr[i++] = "01011010010110101010010110100101";
	strArr[i++] = "00111100001111001100001111000011";
	strArr[i++] = "01101001011110011001011010010110";
	strArr[i++] = "00000000111111111111111100000000";
	strArr[i++] = "01010101101010101010101001010101";
	strArr[i++] = "00110011110011001100110000110011";
	strArr[i++] = "01100110100110011001100101100110";
	strArr[i++] = "00001111111100001111000000001111";
	strArr[i++] = "01011010101001011010010101011010";
	strArr[i++] = "00111100110000111100001100111100";
	strArr[i++] = "01101001100101101001011001101001";
	/*
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
	fin.close();
	*/	
	tempStr = "";
	while (std::cin >> tempStr)
	{
		int index = findIndex(strArr, tempStr);
		if (index == -1)
			std::cout << "error\n";
		else
			std::cout << index << "\n";
	}
}

