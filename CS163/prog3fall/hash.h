#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

using namespace std;

const int SIZE = 100;

struct info
{
	info();
	~info();

	char *topic_names;//finds topic names
	char *websites;
	char *summarys;
	char *reviews;
	int ratings;

	int create(char topic_name[], char website[], char summary[], char review[], int rating);
	int copy(info &to_add);
	bool checkingf(char user[], info &checkn);
	int display(info& checkn);


};

struct node
{
	//node();
	//~node();

	info data;
	node *next;

};


class hash
{
	public:
	hash();
	~hash();

	int hash_function(char  topic_name[]);
	int insert(char topic_name[], info& to_add);
	//adds based on website. will first receive from user.
	int retrieve(char user[],info& checkn);//converts key into a int value and will retrieve all websites based on topic.
	int edit(char user[], char newreviews[], int newratings); //modifies current topic based on seach for website. it will update rating and review.
	int remove();//removes all websites with a rating of one.
	int display(char user[]);//based on topic
	int displayall();
	int count(int index);// counts how many items in the bucket.

	private:
	node** hash_info;
	int MAX_A;
	//int index;
	
};


/********************************* PROTOTYPES *************************/
int questions(info &to_add, info& checkn, hash& hashyfunc);//asks all prompts and is a wrapper for class member functions.
	int ask_retrieve(hash& hashyfunc, info& checkn);//asks what to retrieve and display
int edit(hash& hashyfunc);//wrapper for the edit member
int remove(hash& hashyfunc);//wrapper that prompts for the remove function
int display(hash& hashyfunc);//wrapper for the display function











