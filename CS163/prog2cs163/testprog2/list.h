#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;

const int SIZE = 100;
const char filename[] = "words.txt";


struct char_node
{
    char *data;
	char_node *next;
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
    void initialStack(); // initializes the stack.
    int push();//will count and add
    int pop();//removes character
    int top()const;//looks at the first
    int display() const;//displays all

	private:
	char_node* head;
};


class queue//CLL
{
	public:
    //constructors
	queue();//default
    //deconstructors
	~queue();

    int enqueue();//adds at the end
    int dequeue();
    int peek()const;
    int display()const;

	private:
	char_node *head;

};




class manager//manages and uses in the client
{
    public:
    void add_newtext(char *letter, int letter_count);
    void display_alltext();

    private:
    stack my_letters;
    queue my_words;


};

//prototypes
    int insert();
    int ofile(int len, char user[]);
    int ifile();
    int display_all();
    int remove_all();
    int edit();

    int user_response();
    bool ask();
