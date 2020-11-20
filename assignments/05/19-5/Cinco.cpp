/* Wesley Johanson	Pengo: wjohanso		talk2wes@gmail.com
 * Filename: Cinco.cpp
 * Assignment 5: Cinco game 
 * 
 * Status: working and tested.
 */

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

/**
 * This program runs a game called Cinco. A game where the computer guess a 
 * random five letter word and the user has to guess what that word is.
 */

/* The dictionary class stores words from file into a set. Secret words are 
 * of length 5 and have no repeating characters & are stored into a vector */
class Dictionary{
	public:
		Dictionary(char* filename);
		bool				validWord(std::string word);
		std::string 			getLegalSecretWord();
	private:
		bool			isLegalSecretWord(std::string word);
		std::set<std::string> 		words;
		std::vector<std::string> 	secrets;
		const std::string DEFAULT_FILENAME = "cinco-words.txt";
		const int 		WORD_LENGTH = 5; 
};

//Default Constructor
Dictionary::Dictionary(char* filename){
	srand(time(0));
	std::fstream file;
	
	if (strcmp(filename, "")){
		file.open(filename);
	}else{
		file.open(DEFAULT_FILENAME);
	}
		
	std::string temp = "";
	while (file >> temp){
		words.insert(temp);	
		if (this->isLegalSecretWord(temp))
			secrets.push_back(temp);
	}
	file.close();
}

// Determines if the word passed is an element of the set of words in dictionary
bool	Dictionary::validWord(std::string word){ return (words.count(word)); }

// Determines if word a valid secret word. A secret word is an element of the
// set, has length 5 and no repeating characters. 
bool	Dictionary::isLegalSecretWord(std::string word){
	if (word.length() != WORD_LENGTH)
		return false;
	for (int i = 0; i < WORD_LENGTH; i++){
		for (int j = 0; j < WORD_LENGTH; j++){
			if (i != j && word[i] == word[j])
				return false;
		}
	}
	return true;
}

// Returns a randomly selected secret word
std::string	Dictionary::getLegalSecretWord(){ 
	return (secrets[rand() % secrets.size()]); 
}

//Class that uses dictionary and runs the game
class Cinco{
	public:
		Cinco(std::string filename = "");
		~Cinco();
		void		play();
	private:
		int		countMatchingLetters(std::string);
		int		countInPlaceLetters(std::string);
		Dictionary*	dict;
		int		numOfGuesses;
		bool		cheated;
		std::string	secret;
		const int	WORD_LENGTH = 5;
		std::string*	toLower(std::string*);
};

//converts string to lowercase 
std::string*	Cinco::toLower(std::string* word){
	std::string* lowercase = new std::string();

	
	for (int i = 0; i < WORD_LENGTH; i++){
		if ((*word)[i] >= 'A' && (*word)[i] <= 'Z')
			(*word)[i] = (*word)[i] + ('z' - 'Z');

	}
	return word;
}

// Main game loop
void	Cinco::play(){
	std::cout << "CS19: Cinco! Assignment 5\nby Wesley Johanson\n"
		<< "I'm thinking of a five letter word...\nyour guess? ";
	std::string myGuess =  "";
	while (std::cin >> myGuess){
		myGuess = *(toLower(&myGuess));
		if (dict->validWord(myGuess)){ // valid words
			numOfGuesses++;
			if (countInPlaceLetters(myGuess) == WORD_LENGTH){
				std::cout << "Correct! You got it in " 
				<< numOfGuesses << " guesses.\n";
				if (cheated)
					std::cout << "but only by cheating\n";
				return ; //correct guess
			}
			std::cout << "Matching: " << 
				countMatchingLetters(myGuess) << "\n" << 
				"In-Place: " <<
				countInPlaceLetters(myGuess) << "\n";
		}else{ // invalid words
			if (myGuess.compare("xxxxx") == 0){
				numOfGuesses++;
				std::cout << "Secret word : " << secret << "\n";
				cheated = true;
			}else{
				std::cout << "I don't know that word\n";
			}
		}
		std::cout << "your guess? ";
	}
}

// Default Constructor
Cinco::Cinco(std::string filename){
	dict = new Dictionary((char*) filename.c_str());
	cheated = false;
	secret = dict->getLegalSecretWord();
	numOfGuesses = 0;
}

// Destructor
Cinco::~Cinco(){
	delete[] dict;
	dict = NULL;
}

// Returns the number of letters that are elements of both 
// 'guess' and the secret word
int	Cinco::countMatchingLetters(std::string guess){
	int diffs = 0;
	int lettersInAlphabet = 26;
	bool alphabet[lettersInAlphabet];
	
	for (int i = 0; i < lettersInAlphabet; i++)
		alphabet[i] = false;

	if (secret.length() != WORD_LENGTH)
		return -1;

	for (int i = 0; i < lettersInAlphabet; i++)
		for (int j = 0; j < lettersInAlphabet; j++)
			if (secret[i] == guess[j])
				alphabet[secret[i] - 'a'] = true;
	for (int i = 0; i < lettersInAlphabet; i++)
		diffs = alphabet[i] ? diffs + 1 : diffs;
	return diffs;
}

// Returns the number of in place characters that both 'guess' and secret
// have.
int 	Cinco::countInPlaceLetters(std::string guess){
	int total = 0;
	for (int i = 0; i < WORD_LENGTH; i++)
		total = (guess[i] == secret[i]) ? total + 1 : total;
	return total;
}

//Main function just to initiate the program. Command line argument can be 
//passed to use other text files as dictionaries. 
int	main(int argc, char** argv){

	class Cinco* game;
	if (argc > 1)
		game = new Cinco(argv[1]);
	else
		game = new Cinco();
	game->play();
	
}
