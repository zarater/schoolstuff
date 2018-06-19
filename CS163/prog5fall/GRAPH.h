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
	char* tasks;
	
	int create(char task[]); 
	int copy(info &to_add);
	int compare(char key_value[]);
	//int display();
};



struct vertex 
{
	info *a_info;
	struct  node* head;
};



struct node
{
	vertex* adjacent;
	node *next;

};



class table 
{
	public:

	table();
	~table();

	int insert_vertex(info& to_add);
	int find_location(char key_value[]);
	int insert_edge(char current_vertex[], char to_attach[]);
	int display_adjacent(char key_value[]);
	int displayall();

	private:

	vertex* adjacency_list;
	int list_size;
};




/********************************* PROTOTYPES *************************/











