#include "list.h"
									/* divided in three sections.
									1. constructors and destructors
									2. stack function
									3. queue function
									*/
							/******************start of CONSTRUCTOR & destructor *********************/
/*
manager:: manager(){}
manager:: ~manager(){}
*/
stack::stack()
{
	queue_info = NULL;
	dyn = new char [SIZE];
	Stack_top = 0;// initilized to 0 will change based on wordlength
	Max_size = 5;//dynamic array cannot be greater then five
}

stack::~stack()
{
	delete queue_info;
	delete [] dyn;
	Stack_top = 0;
	Max_size = 5;

}

queue :: queue()
{
	head = NULL;
	tail = NULL;


}

queue :: ~queue()
{
	delete head;
	delete tail;
}


							/******************start of STACK *********************/


//implementation

/*
void stack :: intitialStack()
{
	Stack_top =0;
}
*/


bool stack :: isEmpty()
{
	return (Stack_top == 0);
}

bool stack:: isFull()
{
	return (Stack_top == Max_size);
}

int stack :: push(char letter, int wordlength, int characterlength /*,char *&dyn*/)//does dyn need to be passed by reference?
{
	int word_length=wordlength;
	Stack_top = characterlength;//initializes Stack top to always change in position in array

	if(isFull() == false)//!isFull..
	{
		dyn[Stack_top] = letter; //strcpy(dyn[Stack_top], userletter);
		if(word_length > 0 && Stack_top == 0){pass_toLLL();}// passes to LLL if new word.
	}
		
	cout << "word length: " << word_length << endl;
	return word_length;//just needs to return true. no reason to have word_length returned.
}

	
	
int stack :: pop(char*&dyn)
{

	if(isEmpty()== false)//is empty returns true.!isEmpty
	{
		Stack_top--;//deleting up to null by one character. it wont underflow because not deleting more then one.
	}
else 
	cout << "nothing in the list to delete." << endl;
	return 1;
	
} 
int stack :: top() const
{
	if(Stack_top != 0)
	{
		dyn[Stack_top-1];//displays the top of the stack. 
		return 1;
	}
	else
		return 0;//if the user inputs nothing and cant check the list
}
int stack :: display()const
{
	if(isEmpty() == true){ cout << "nothing to display" << endl; return 0;}

	cout << "characters so far: " << dyn << endl;
	return 1;
}
int stack :: pass_toLLL()
{
	if(!head)
	{
		char_node * temp = new char_node;
		temp -> data = dyn;
		temp -> next = NULL;
		head = temp;
		return 0;
	}
		char_node *temp = new char_node;
		temp -> data = dyn;
		temp -> next = head;
		if(head.push(letter, wordlength, charachterlength)/*returns wordlength*/== 0){tail = head;}//a tail for CLL. stays at the tail of the list.[]->[]->[]->
		else if(head.push(letter, wordlength, characterlength) > 0) {tail -> next = head;}// now it becomes a CLL.
		head = temp;


	return 1;
}






							/******************QUEUE  functions*********************/
int queue:: enqueue(char_node *&head, char_node*&tail, dyn)
{
//will recieve an array dynamically from client. 
//will change array into a data for a cll.
//cll will then add per each array
//all wiil be handled in manager class
//all issues will traversal will be implemented in the queue functions.
	if(!head){return 0;}
	
	return 1;

}

int queue:: dequeue(char_node*& tail)
{
	return 1;
}

int queue :: display(char_node *head) const
{

	if(!head){ cout <<  return 0;}
	cout << head -> data << endl;
	display(head -> next);
	return 1;
}


						/******************start of MANAGER class*********************/
void manager :: add_remove_text(char letter, int wordlength, int characterlength)//arguments are from the client insert function
{
	//pass to push

	//char userletter[SIZE];// +1 for null strcat may allocate the null auto
	//userletter[characterlength] =letter;//waiting to be passed so that it will be char *dynm ** one letter inserted at a time**
	my_letters.push(letter, wordlength, characterlength/*, dyn*/);
	my_letters.display();
	if(toDelete() == true){my_letters.pop(dyn);}//asks to delete if true it will delete a stack
}
/*
void manager :: add_remove_word()
{
	char_node temp;
    my_letters.pass_toLLL(temp);
	queue.enqueue(temp);
}
*/
bool manager :: toDelete()
{
	char userresponse[SIZE];
	cout << "do you want to delete"<< endl;

	cin.get(userresponse,100, '\n');//asks user for a response
	cin.ignore(100, '\n');
	int len = strlen(userresponse);// initializes len
	for (int i; i < len; ++i)
	{userresponse[i] = (toupper(userresponse[i]));}//upper cases all 

	if ((strcmp(userresponse, "YES") == 0) || (strcmp(userresponse, "Y") == 0)){return true;}

	else if ((strcmp(userresponse, "NO") == 0) || (strcmp(userresponse, "N") == 0))	
	{cout << "Thank you." << endl;	return false;}

	return false;
}



							/******************END of manager function*********************/
