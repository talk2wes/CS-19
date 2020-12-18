/* Wesley Johanson	Pengo: Wjohanso		talk2wes@gmail.com
 * Filename: main.c
 * Assignment 7: Six degrees of bacon */

#include "bacon.h"

using std::string;
using std::ifstream;
using std::cout;
using std::vector;

bool	isAdjactent(string word1, string word2){

	if (word1.size() != word2.size()) return false;

	return true;
}

void	findAdjacentWords(vector<vector<WNodePtr>*>& solutionSpace,
						vector<string>& dictionary){

	
}

bool	removeWord(vector<string>& dictionary, string word){
	for (int i = 0; i < dictionary.size(); i++){

	}
	return false;
}

int	main(int argc, char** argv){
	
	//Determine if flag option is used 
	string flag = "-r";	
	int flagIndex = -1;
	//cout << "preflag\n";
	if (argc < 2 && argc > 3) return -1; //Error: undefined arguments
	if (argc == 3){
		if (flag.compare(argv[1]) == 0) flagIndex = 1;
		else if (flag.compare(argv[2]) == 0) flagIndex = 2;
		if (flagIndex == -1) return -1; //Error: incorrect flag option 
	}
	int fileIndex = (flagIndex == 1) ? 2 : 1;
	//cout << "command line arguments are valid\n";

	//open the file
	ifstream fin;
	fin.open(argv[fileIndex]);
	if (fin.fail()) return -1; //error opening file
	//cout << "file was opened successfully\n";
	
	//read the file into the dictionary
	vector<string>* dictionary = new vector<string>();
	string temp;
	while (fin >> temp)
		dictionary->push_back(temp);
	//test that I loaded the dictionary
	/*
	for (int i = 0; i < dictionary.size(); i++)
		cout << dictionary[i] << std::endl;
	*/
	
	//Program initial output
	cout << "Six Degrees of Bacon. Solution by Wesley Johanson\n";
	cout << "Wesley Johanson, talk2wes@gmail.com, pengo: wjohanso\n";
	cout << "Your word?";
	string userInput;
	std::cin >> userInput;
	//MAKE THIS LOWER CASE AND CHECK FOR NON_ALPHA CHARACTERS. Ask again if invalid

	//determine where to start and end
	string startWord = (flagIndex > -1) ? userInput : "bacon";
	string endWord = (flagIndex > -1 ) ? "bacon" : userInput;
	//do I need to remove the startword from the dictionary? 

	//Make the solutionspace and add the starting word
	vector<vector<WNodePtr>*>* solutionSpace = new vector<WNodePtrVec*>();
	vector<WNodePtr>* startVec = new vector<WNodePtr>();
	WNode* startNode = new WNode(startWord);
	startVec->push_back(startNode);
	solutionSpace->push_back(startVec);

	//remove the startword from the dictionary

	
	findAdjacentWords(*solutionSpace, *dictionary);
	cout << "start: " << startWord << "\nend: " << endWord << std::endl;
	

	
	return 1;
}
