#include <iostream>	//cout

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
				std::cout << *(temp->data) << std::endl;
				temp = temp->next;
			}
			//print the last one
			std::cout << temp->data << std::endl;	
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

int		main()
{
	int* nums;
	nums = new int[10];
	nums[0] = 5;
	
	List* myNums = new List();
	myNums->insertFront(&nums[0]);
	myNums->print();
	
	std::cout << "helloworld\n";
}
