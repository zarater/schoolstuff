#include "list.h"
									/* divided in three sections.
									1. constructors and destructors
									2. stack function
									3. queue function
									*/


stack::stack()
{
	head = NULL;
}

stack::~stack()
{
	delete head;
}

queue:: queue()
{
	head = NULL;
}

queue :: ~queue()
{
	delete head;
}


							//******************end of constructors*********************\\


//implementation


bool stack :: isEmpty()
{
	return (head == NULL);
}

bool stack:: isFull()
{
	return false;
}


void stack :: initialStack()
{
	char_node *temp;

	while (head != NULL)
	{
		temp = head;
		head = head -> next;
		delete temp;
	}
}

int stack:: push(char letter, int letter_count)
{
	char_node* temp = new char_node;
	temp -> data = letter;
	temp -> next = head;
	head = temp;
	return 1;
}


int stack:: top() const
{
	if(!head) {return 0;}

	 head -> data;
	 return 1;

}

int stack:: pop()
{
	char_node *temp;
	if(!head){cout << "cannot remove from the stack" << endl; return 0;}
	if(head != NULL)
	{
		temp =  head;
		head = head -> next;
		delete temp;
	}

}

							//******************end of stack function*********************\\



							//******************end of queue function*********************\\