#include <iostream>
#include <cctype>
#include <cstring>


// const
const int MAX = 100;


//class and structs
struct artist //manages artist info 
{
	artist(); // constructor for allocating space.
	~artist();//deallocates space.

	char *artist_name;
	char *artist_topstory;
	char *artist_info;
	char *artist_genre;


};


struct song  //manages songs info
{	
	song(); // constructor for allocating space 
	~song(); // dealocates space
	char* title;
	int length;
	int num_of_views;
	int num_of_likes;

};

struct node_song // creates a Linear linked list by calling itself
{
	node_song(); //allocates
	~node_song(); // deallocates
	
	song *data;
	node_song *next;
};

struct node_artist // creates a LLL of node artist
{
	node_artist();//
	~node_artist();// does not deallocate head because i receive a seg fault of a null type 0x0 when troubleshoot

	artist *data; //head of a artist list
	node_song* data_song;//head of song list
	node_artist *next;
};



class record_label// manages action amongst the members and private members
{
	public:
	//constructor
	record_label();
	//destructor
	~record_label();

	//members

	int add_artist(char* artist, char *top_story, char* description, char* genre);// adds an artist


	int add_song(char* title, int length, int num_of_likes, int num_of_views, node_song*& head);//adds song to the correct place
        int add_song(char* title, int length, int num_of_likes, int num_of_views, node_artist *& head,  char* artist_name);//gets to correct artist
        int add_song(char* title, int length, int num_of_likes, int num_of_views, char *artist_name);//gets the infor from the client program"wrapper"
        
        

	int display_artist(char* artist);//displays artist info
	int displayall_song_byLikes(char * song);// displays song by likes

	int edit_views_likes(char artist[], char song[], int likes_or_views, int new_response);// edits the views and likes of a song

	int remove_all(int remove_number_m);// removes all songs depending on info inputed
	int sort();
	private:
		
	int count;// counts the traversal of a list
	node_artist* head;// uses artist to traverse a linear list. manger type struct to access other structs.
};

	
//functions
int questions(record_label &action);// asks what to do
//	inside questions~~~~~~~
	int songs(record_label & action);//prompts and adds song info to member in class
	int name(record_label & action);///prompts and adds artist info to member in class

//	~~~~~~ outside questions

int display();// promps to 
int edit(record_label & action); //prompts and sends info to member in class
int remove(record_label & action);//prompts and sends info to member in class
int whattodo();//promps which action to in main

bool ask();
bool ask_main();