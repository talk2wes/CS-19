#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

//I need to make sure that the input is NOT CASE SENSITIVE

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
		//length of all words in dictionary ^^ 
};

Dictionary::Dictionary(char* filename){
	srand(time(0));
	std::fstream file;
	
	std::cout << "test 999\n";
	//should us a try-catch statement incase the file doesn't open 
	if (strcmp(filename, "")){
		std::cout << "custom filename\n";
		file.open(filename);
	}else{
		std::cout << "default filename\n";
		file.open(DEFAULT_FILENAME);
	}
	
	std::string temp = "";
	while (file >> temp){
		words.insert(temp);	
		std::cout << temp << "\n";
		if (this->isLegalSecretWord(temp))
			secrets.push_back(temp);
	}
	file.close();
}

bool	Dictionary::validWord(std::string word){ return (words.count(word)); }

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

std::string	Dictionary::getLegalSecretWord(){ return (secrets[rand() % secrets.size()]); }

// CINCO CLASS 

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
};

void	Cinco::play(){
	//STOP 
	
}

Cinco::Cinco(std::string filename){
	dict = new Dictionary((char*) filename.c_str());
	cheated = false;
	secret = dict->getLegalSecretWord();
	numOfGuesses = 0;
}

Cinco::~Cinco(){
	delete[] dict;
	dict = NULL;
}

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

int 	Cinco::countInPlaceLetters(std::string guess){
	int total = 0;
	for (int i = 0; i < WORD_LENGTH; i++)
		total = (guess[i] == secret[i]) ? total + 1 : total;
	return total;
}


int	main(int argc, char** argv){

	class Cinco* game;
	if (argc > 1)
		game = new Cinco(argv[1]);
	else
		game = new Cinco();
	game->play();
	
}
