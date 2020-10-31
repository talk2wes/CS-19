#include <iostream> 
#include <fstream>
static const int MIN_DIF = 7;	//Minimum difference to be a match

int		findDiff(std::string strArr[], std::string userInput)
{
	int diff = 0;
	//for the length of the string
		//compare each value incrementing the diff conditionally
	return -1; //dummy value
}

int		findIndex(std::string strArr[], std::string userInput)
{
	int diff = findDiff(strArr, userInput);

	return -1; // dummy value
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
	i = 0;
	while (i < 32) 
		std::cout << "strArr:"<< strArr[i++] << std::endl;

	//Keep running each cin input into the program until EOF 
	tempStr = "";
	while (std::cin >> tempStr)
	{
		int index = findIndex(strArr, tempStr);
		/*
		if (index == -1)
			std::cout << "error\n";
		else
			std::cout << i << "\n";
		*/
	}

	fin.close(); //DON'T CLOSE THE FILE UNTIL THE END DUMBASS >.>
}

