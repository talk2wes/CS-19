/* Wesley Johanson	Pengo: Wjohanso		talk2wes@gmail.com
 * Filename: main.c
 * Assignment 7: Six degrees of bacon 
 *
 * working and tested!!!!*/

#include "bacon.h"

using std::string;
using std::ifstream;
using std::cout;
using std::vector;

//prototype 
bool removeWord(vector<string>&, string);

//returns true if words differ by one character
bool	isAdjacent(string word1, string word2){
	int diffs = 0;
	if (word1.size() != word2.size()) return false;

	for (int i = 0 ; i < word1.size(); i++)
		if (word1[i] != word2[i]) diffs++;	
	return diffs == 1;
}

//finds the node that contains "bacon" in the last col of the solution space 
WNodePtr findSolutionNode(vector<vector<WNodePtr>*>& solutionSpace, string endWord){
	int lastColInd = solutionSpace.size() - 1;
	for (int i = 0; i < solutionSpace[lastColInd]->size(); i++)
		if (endWord.compare(solutionSpace[lastColInd]->at(i)->word) == 0)
			return (solutionSpace[lastColInd]->at(i));
	return 0;
}

//recursively finds the first word and then prints path in reverse
void 	printReverseSolution(WNodePtr bacon){
	if (bacon->link == 0){
		cout << bacon->word << "\n";
		return;
	}else{
		printReverseSolution(bacon->link);
		cout << bacon->word << "\n";
	}
}

//prints the path, starting from bacon
void	printSolution(WNodePtr bacon){
	WNodePtr temp = bacon;
	while (temp != 0){
		cout << temp->word << "\n";
		temp = temp->link;
	}
}

/*finds all adjacent words in the i'th vector, stores them in a new vector
 *and then adds that vector to the solution space*/
bool	findAdjacentWords(vector<vector<WNodePtr>*>& solutionSpace,
						vector<string>* dictionary, 
						string endWord){
	bool solutionFound = false;
	for (int i = 0; i < solutionSpace.size(); i++){
		WNodePtrVec* newVector = new WNodePtrVec();
		for (int j = 0; j < solutionSpace[i]->size(); j++){
			//find all words adj to word at [i,j]
			for (string word : *dictionary){
				if (isAdjacent(word,solutionSpace[i]->at(j)->word)){
					//make a new node with word
					WNodePtr newNode = new WNode(word);
					//link the newnode to the word 
					newNode->link = solutionSpace[i]->at(j);
					//add  the node to the vector
					newVector->push_back(newNode);
					//remove word from dictionary
					removeWord(*dictionary, word);
					if (word.compare(endWord) == 0)
						solutionFound = true;
				}
			}
		}
		//Add vector to solutionSpace if words were found
		if (newVector->size() > 0){
			solutionSpace.push_back(newVector);
			if (solutionFound) return true;
		}else //return if no adjacencies found in the last vector
			return false;
	}
	return false;
}

//returns true if the word is found in the dictionary 
bool	hasWord(vector<string> dictionary, string word){
	for (int i = 0; i < dictionary.size(); i++)
		if (word.compare(dictionary[i]) == 0)
			return true;
	return false;
}

//removes the word from the dictionary 
bool	removeWord(vector<string>& dictionary, string word){
	for (int i = 0; i < dictionary.size(); i++){
		if (word.compare(dictionary[i]) == 0){
			dictionary.erase(dictionary.begin() + i);
			return true;
		}
	}
	return false;
}

//checks if the user input is a valid word to start with
bool	inputValid(string word, vector<string> dictionary){
		if (word.size() != 5){
			cout << "choose a 5 letter word\n";
			return false;
		}
		if (hasWord(dictionary, word) == false){
			cout << "word not known (aka not in dictionary)\n";
			return false;
		}
		return true;
}


/* Determines if the flag option was used on the command-line. 
 * Sets flagIndex to the index of argv that the flag string is stored in.
 * returns the index of argv that has the file name string.*/
int	flagOption(int argc, char** argv, string& flag, int& flagIndex){
	if (argc < 2 && argc > 3) return -1; //Error: undefined arguments
	if (argc == 3){
		if (flag.compare(argv[1]) == 0) flagIndex = 1;
		else if (flag.compare(argv[2]) == 0) flagIndex = 2;
		if (flagIndex == -1) return -1; //Error: incorrect flag option 
	}
	int fileIndex = (flagIndex == 1) ? 2 : 1;
	return fileIndex;
}


int	main(int argc, char** argv){
	string flag = "-r";	
	int flagIndex = -1; //default = -1 = no flag was used
	ifstream dictionaryFile;
	string temp;
	vector<string>* dictionary = new vector<string>();
	string startWord; //word to start search from
	string endWord = "bacon"; //word to end search on 
	/*solution space is the matrix (aka vector of vectors) where all of the 
	 *adjacent words are stored and linked to each other*/
	vector<vector<WNodePtr>*>* solutionSpace = new vector<WNodePtrVec*>();
	//first vector in solutionSpace with the starting word for search
	vector<WNodePtr>* startVec = new vector<WNodePtr>(); 
	WNode* startNode = new WNode();
/*
	if (argc < 2 && argc > 3) return -1; //Error: undefined arguments
	if (argc == 3){
		if (flag.compare(argv[1]) == 0) flagIndex = 1;
		else if (flag.compare(argv[2]) == 0) flagIndex = 2;
		if (flagIndex == -1) return -1; //Error: incorrect flag option 
	}
	int fileIndex = (flagIndex == 1) ? 2 : 1;
	*/
	//determines if the flag option was used
	int fileIndex = flagOption(argc, argv, flag, flagIndex);

	//open the file
	dictionaryFile.open(argv[fileIndex]);
	if (dictionaryFile.fail()) return -1; //error opening file
	
	//read the file into the dictionary
	while (dictionaryFile >> temp)
		dictionary->push_back(temp);
	
	//Program initial output
	cout << "Six Degrees of Bacon. Solution by Wesley Johanson\n";
	cout << "Wesley Johanson, talk2wes@gmail.com, pengo: wjohanso\n";
	cout << "Your word?";

	//Get the starting word from the user
	std::cin >> startWord;
	while (inputValid(startWord, *dictionary) == false){ 
		cout << "Your word?";
		std::cin >> startWord;
	}

	//Initialize the solutionspace and add the starting word
	startNode->word = startWord;
	//WNode* startNode = new WNode(startWord);
	startVec->push_back(startNode);
	solutionSpace->push_back(startVec);

	//find all adjacencies, until bacon found or no solution
	if (findAdjacentWords(*solutionSpace, dictionary, endWord)){
		//Solution was found
		WNodePtr bacon = findSolutionNode(*solutionSpace, endWord);
		if (flagIndex == -1)
			printSolution(bacon);
		else
			printReverseSolution(bacon);
	}else{ 
		//No solution found
		if (flagIndex > -1 )
			cout << "no path from " << startWord << " to " << endWord << "\n";
		else
			cout << "no path from " << endWord << " to " << startWord << "\n";
	}
	return 1;
}
