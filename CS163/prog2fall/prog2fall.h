#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>


using namespace std;

const int SIZE = 100;// initialize static size

struct info// will have dynamic arrays
{
	info();//constructor default
	~info();//deconstructor


    char *group_name;//asks the group name
    int num_ofpeople;// how many people in the group
    char* specialseat_requirement;// is there a  special seat 
    char* coupons_emailandname;// contacted by email
};



struct node//makes a node struct
{
	node();
	~node();

    info * data;// calls the info to be passed
    node *next;
};



class stack // will add and remove at front
{
    public:
    stack();//constructor default 
    stack(int arraysize);// constructor

    ~stack();

    int receive_pass1(node * current, int  bottom);//receives info to initialize head and top index
    int push(node *&head, node *new_node);// will add to the list
    int pop();// removes from a list
    int displayone();// displays the list
    int peek();//peeks at first
    int file();

    private:
    node* head;// the list
    node* new_node;// recieves a list to pass to head in receive_pass function
    int max;// sets the max size in constructor
    int top_index;// incremental part of the lll of array
};



class queue //removes at the head and inserts at the tail
{
    public:
    queue();//constructor

    ~queue();//deconstructor

    int receive_pass2(node *current);//initializes head and new node
    int enqueue(node *&, node *);// adds to the list
    int dequeue();// removes from the list
    int display();//displays all 
    int peek();// peeks intot the list showing the first
    

    private:
    node* head;//the list 
    node *new_node;// passes to head from receive pass function
    //int ISIZE;
};


//classes
class manager// passes what client will input.
{
    public:
    manager();//constructor
    manager(int arraysize);
    ~manager();//deconstructor

    int in_main(char user[], int user2, char user3[], char user4[]);// recieves from client
    int new_list(node*);//makes a node in scope of stack and queue

    int displayallm(int response);// displays all
    int remove(int response);//needs a peek


    private: 
    node *head;// temp node that will be passed to stack and queue
    stack first_one;// stack class
    queue second_one;// queue class
    int MAX;// 
    int bottom;


};





//prototype
int question(manager &m);
int displayall(manager &m);
int remove(manager &m);
bool ask();

