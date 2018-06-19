#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

const int SIZE = 100;
const char filename[] = "words.txt";
/*
struct word_node
{
    char data;
    word_node* next;
}
*/

struct char_node
{
	
	char_node *next;
};


class queue//CLL
{
	public:
    //constructors
	queue();//default
    //deconstructors
	~queue();

    int enqueue(char_node*& head, char_node *&tail, char *dyn);//adds into an LLL. initializes tail.
    int dequeue(char_node *& tail);
    int peek()const;
	int display(char_node *head) const;

	private:
    struct char_node *head;
	struct char_node *tail;

};

struct node
{
	char_node* data;
	node*next
};
class stack //LLL of Arrays
{
	public:
    //constructors
	stack();//default
    //deconstructors
	~stack();

    bool isEmpty();//checks if the stack is empty
    bool isFull();//checks if the stack is full
    //void initialStack(); // initializes the stack.

    int push(char letter, int wordlength, int characterlength/*, char*& dyn*/);//will count and add
    int pop(char*& dyn);//removes character
    int top()const;//looks at the first
    int display() const;//displays all
    int pass_toLLL();

	private:
    struct char_node *queue_info;
    int Stack_top;
    int Max_size;//full amount of each word. 
    char *dyn;//dynamic array
};






class manager//manages and uses in the client
{
    public:
    void add_remove_text(char letter, int letter_count, int characterlength);
    void add_remove_word();

    private:
    bool toDelete();
    stack my_letters;
    queue my_words;
};

//prototypes
    int insert();
    //int ofile(int len, char user[]);
    //int ifile();
    int display_all();
    int remove_all();
    int edit();

    int user_response();
    bool ask();
