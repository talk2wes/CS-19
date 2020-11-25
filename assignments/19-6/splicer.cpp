/* Wesley Johanson	Pengo: wjohanson	Talk2wes@gmail.com
 * Filename: splicer.cpp
 * Assignment 6: Splicer */

/* A public function named splice(string find, string replace) that takes two 
 * strings called find and replace. Do nothing if the find string is empty, 
 * or longer than one character. If the find string is exactly one character, 
 * replace each occurrence of that character in the string with a sequence 
 * of nodes from the replacement string. If the replacement string is empty, 
 * delete all of the found nodes from the list. New nodes that have been 
 * replaced are not subject to also being replaced -- only nodes that were 
 * present at the time of the command. For example if the list contains 
 * A-C-G-T-A-G (size 6) and you splice("A", "GAT") the resulting list would 
 * be G-A-T-C-G-T-G-A-T-G (size 10) */

 bool	List::splice(std::string find, std::string replace){
	return true;
 }

/* A public function named insert(string s) that inserts one or more new nodes 
 * to the start of the list. Do nothing if s is empty. Otherwise create one 
 * new node for each character in the string, inserting the characters in the 
 * string, one per node, into the list in the same order as the string. For 
 * example if you insert "ACGT" into a list that contains A-G (size 2), then 
 * the resulting list would be A-C-G-T-A-G (size 6) */

bool 	List::insert(std::string s){
	if (!s)
		return;
	

}

