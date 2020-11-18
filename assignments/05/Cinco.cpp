#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>


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
		std::cout << temp << "\n";
	}
	file.close();

}

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
};

void	Cinco::play(){
	
}

Cinco::Cinco(std::string filename){
	dict = new Dictionary((char*) filename.c_str());
	cheated = false;
	//secret = dict.getLegalSecretWord();
	//numOfGuesses = 0;
}

Cinco::~Cinco(){
	delete[] dict;
	dict = NULL;
}

int	main(int argc, char** argv){

	class Cinco* game;
	if (argc > 1)
		game = new Cinco(argv[1]);
	else
		game = new Cinco();
	game->play();
	
}
