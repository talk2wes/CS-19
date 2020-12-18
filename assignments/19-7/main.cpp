/* Wesley Johanson	Pengo: Wjohanso		talk2wes@gmail.com
 * Filename: main.c
 * Assignment 7: Six degrees of bacon */

#include "bacon.h"

using std::string;
using std::ifstream;
using std::cout;
using std::vector;

bool removeWord(vector<string>&, string);

bool	isAdjacent(string word1, string word2){
	int diffs = 0;
	if (word1.size() != word2.size()) return false;

	for (int i = 0 ; i < word1.size(); i++){
		if (word1[i] != word2[i]) diffs++;	
		//cout << "diffs = " << diffs << std::endl;
	}
	//if (diffs == 1) cout << word1 << "\t" << word2 << std::endl;
	return diffs == 1;
}

WNodePtr findSolutionNode(vector<vector<WNodePtr>*>& solutionSpace, string endWord){
	int lastColInd = solutionSpace.size() - 1;
	//cout << "last col = " << lastColInd << "\n";
	for (int i = 0; i < solutionSpace[lastColInd]->size(); i++){
		//cout << solutionSpace[lastColInd]->at(i)->word << "\n";
		if (endWord.compare(solutionSpace[lastColInd]->at(i)->word) == 0){
			return (solutionSpace[lastColInd]->at(i));
		}
	}
	return 0;
}

void 	printReverseSolution(WNodePtr bacon){
	if (bacon->link == 0){
		cout << bacon->word << "\n";
		return;
	}else{
		printReverseSolution(bacon->link);
		cout << bacon->word << "\n";
	}
}

void	printSolution(WNodePtr bacon){
	WNodePtr temp = bacon;
	while (temp != 0){
		cout << temp->word << "\n";
		temp = temp->link;
	}
}
bool	findAdjacentWords(vector<vector<WNodePtr>*>& solutionSpace,
						vector<string>* dictionary, 
						string endWord){
	bool solutionFound = false;
	for (int i = 0; i < solutionSpace.size(); i++){
		WNodePtrVec* newVector = new WNodePtrVec();
		//find all words in dictionary adj to words in i'th column
		//cout << "col = " << i << "\n";
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
			//cout << "col = " << solutionSpace.size() << "\n";
			//if (solutionFound){ cout << "solutionfound!!\n";}
			if (solutionFound) return true;
		}else //return if no adjacencies found in the last vector
			return false;
	}
	return false;
}

bool	hasWord(vector<string> dictionary, string word){
	for (int i = 0; i < dictionary.size(); i++)
		if (word.compare(dictionary[i]) == 0)
			return true;
	return false;
}
/*
bool	removeWord(vector<string>* dictionary, string word){
	for (int i = 0; i < dictionary->size(); i++){
		if (word.compare(dictionary->at(i)) == 0){
			dictionary->erase(dictionary->begin() + i);
			return true;
		}
	}
	return false;
}
*/

bool	removeWord(vector<string>& dictionary, string word){
	for (int i = 0; i < dictionary.size(); i++){
		if (word.compare(dictionary[i]) == 0){
			dictionary.erase(dictionary.begin() + i);
			return true;
		}
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
	//if -r option is made. Make sure the userInput word is IN THE DICTIONARY

	string startWord = userInput;
	string endWord = "bacon";
	//determine where to start and end
	/*
	string startWord = (flagIndex > -1) ? userInput : "bacon";
	string endWord = (flagIndex > -1 ) ? "bacon" : userInput;
	*/
	//do I need to remove the startword from the dictionary? 

	//Make the solutionspace and add the starting word
	vector<vector<WNodePtr>*>* solutionSpace = new vector<WNodePtrVec*>();
	vector<WNodePtr>* startVec = new vector<WNodePtr>();
	WNode* startNode = new WNode(startWord);
	startVec->push_back(startNode);
	solutionSpace->push_back(startVec);

	//remove the startword from the dictionary
	if (findAdjacentWords(*solutionSpace, dictionary, endWord)){
		WNodePtr bacon = findSolutionNode(*solutionSpace, endWord);
		printSolution(bacon);
		cout << "reverse SOlution! \n";
		printReverseSolution(bacon);
	}
	//cout << "start: " << startWord << "\nend: " << endWord << std::endl;
	//cout << "has startWord? : " << hasWord(*dictionary, startWord) << std::endl;
	//cout << "remove startWord? : " << removeWord(*dictionary, startWord) << std::endl;

	/*
	for (int i = 0; i < dictionary->size(); i++){
		if (isAdjacent(dictionary->at(i), startWord) == true)
			cout << "start: " << startWord << "\tadj: " << dictionary->at(i) << "\n";
	*/
	
	return 1;
}
