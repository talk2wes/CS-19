#include <cstdlib>
#include <iostream>	//cout
#include <istream>
#include <ostream>
#include <string>

class LinkNode
{
	friend class List;

	public:
		LinkNode()
		{
			next = 0;
			data = 0;
		}

		~LinkNode() 
		{
			if (data)
				delete data;
			data = 0;
		}

	private:
		LinkNode* 	next;
		int*		data;
};

class List
{
	public:
		List() { first = 0; }
		bool isEmpty() { return (first == 0); }
		void print() 
		{
			LinkNode* temp = first;
			while (temp->next)
			{
				std::cout << *(temp->data) << " ";
				temp = temp->next;
			}
			//print the last one
			std::cout << *(temp->data) << std::endl;	
		}

		void insertFront(int* n)
		{
			//make a new node
			LinkNode* newNode = new LinkNode();
			newNode->data = n;

			//point to new node if empty
			if (isEmpty()) { first = newNode; return; }

			//make new node the head
			newNode->next = first;

			//make the list point to the new head 
			first = newNode;
		}

		//Reverses the order of the linked list. Convention is the LL is
		//in order of left to right. Head->...->0
		void reverse()
		{
			LinkNode* left;
			LinkNode* right;

			//ignore empty lists & lists of size one 
			if ( !first || !(first->next) ) 
				return;

			//LinkedList setup: left->first->(other nodes) 
			left = first;
			first = left->next;
			left->next = 0;
			
			//2+ nodes loop
			while (true)
			{
				if (first->next == 0)
				{//if there are no more nodes on the right
					first->next = left;
					return;
				}else 
				{//for nodes of 3+ nodes, this will run this 
					right = first->next;
					first->next = left;
					left = first;
					first = right;
				}
			}
		}
		
		//Sorts the linklist into descending order
		LinkNode* selectionSort(LinkNode* head)
		{
			LinkNode *temp = head;
			LinkNode *newHead = 0;
			return (newHead);
		}


		void insertBack(int* n)
		{
			//make a new node
			LinkNode* newNode = new LinkNode();
			newNode->data = n;

			//point to the new node if empty 
			if (isEmpty()) { first = newNode; return; }

			//find the last node
			LinkNode* lastNode = first;
			while (lastNode->next)
				lastNode = lastNode->next;

			//make the lastnode in the list point to new node
			lastNode->next = newNode;
		}

	private:
		LinkNode* first;
};


using std::cout;
int		main(int argc, char** argv)
{
	List* myNums = new List();	
	std::string temp = "";
	int flip = 1;
	while (std::cin >> temp)
	{
		if (flip == 1)
			myNums->insertFront(new int(stoi(temp)));
		else
			myNums->insertBack(new int(stoi(temp)));
		flip *= -1;
		myNums->print();
		myNums->reverse();
		myNums->print();
	}
	std::cout << "titties\n";
}
