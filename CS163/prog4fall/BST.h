#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

using namespace std;

const int SIZE = 100;

struct  node
{
	node();
	~node();

	char *keywords;
	char *topic_names;//finds topic names
	char *websites;
	char *summarys;
	char *reviews;
	int ratings;
	
	int create(char keyword[], char topic_name[], char website[], char summary[], char review[], int rating);
	int copy(node &to_add);
	bool checkingf(char keyword[], node &checkn);

	node *left;
	node *right;

};


class bst
{
	public:
	bst();
	~bst();

	//adds based on website. will first receive from user.
	int insert(char keyword[], node &to_add);//wrapper
	int insert(char keyword[], node& to_add, node*&root);
	
	int retrieve(char user[], node &checkn);//wrapper
	int retrieve(char user[],node& checkn, node *root);//converts key into a int value and will retrieve all websites based on topic.

	int remove(char keyword[]);//wrapper keyword one
	int remove(char keyword[], node*& root);//removes one  website on keyword.

	int removeall(char topic_name[]);//wrapper topic name wrapper
	int removeall(char topic_name[], node*&root );//removes all based on topic name

	int display();//wrapper
	int displayall(node *root);

	private:
	node* root;
	int MAX_A;
	
};


/********************************* PROTOTYPES *************************/
int questions(node &to_add, node& checkn, bst& hashyfunc);//asks all prompts and is a wrapper for class member functions.
	int ask_retrieve(bst& bstfunc, node& checkn);//asks what to retrieve and display










