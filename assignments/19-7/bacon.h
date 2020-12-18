/* Wesley Johanson	Pengo: wjohanso		talk2wes@gmail.com
 * Filename: Makefile 
 * Assignment 7: Six degrees of bacon */


#ifndef W_NODE__H
#define W_NODE__H

#include <string> 
#include <fstream>
#include <iostream> 
#include <vector>

// "Linkable" (to create a trace) string (a word) 
struct WNode{
  WNode(std::string s=""){word = s; link = 0;}
  std::string word;
  WNode *link;
};

// example typedefs:
typedef WNode* WNodePtr;    
typedef std::vector<WNodePtr> WNodePtrVec;


#endif
