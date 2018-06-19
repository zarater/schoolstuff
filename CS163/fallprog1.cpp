#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

// const
const int MAX = 100;


//class and structs
struct artist 
{
	artist();
	~artist();

	char *artist_name;
	char *artist_topstory;
	char *artist_info;
	char *artist_genre;


};


struct song 
{	
	song();
	~song();
	char* title;
	int length;
	int num_of_views;
	int num_of_likes;

};

struct node_song
{
	node_song();
	~node_song();
	
	song *data;
	node_song *next;
};

struct node_artist
{
	node_artist();
	~node_artist();

	artist *data; 
	node_song* data_song;//head of song list
	node_artist *next;
};



class record_label
{
	public:
	//constructor
	record_label();
	//destructor
	~record_label();

	//members

	int add_artist(char* artist, char *top_story, char* description, char* genre);


	int add_song(char* title, int length, int num_of_likes, int num_of_views, node_song*& head);//adds song to the correct place
        int add_song(char* title, int length, int num_of_likes, int num_of_views, node_artist *& head,  char* artist_name);//gets to correct artist
        int add_song(char* title, int length, int num_of_likes, int num_of_views, char *artist_name);//gets the infor from the client program"wrapper"
        
        

	int display_artist(char* artist);
	int displayall_song_byLikes(char * song);

	int edit_views_likes(char artist[], char song[], int likes_or_views, int new_response);

	int remove_all(int remove_number_m);
	int sort();
	private:
		
	int count;
	node_artist* head;
};

	
//functions
int questions(record_label &action);
//	inside questions~~~~~~~
	int songs(record_label & action);
	int name(record_label & action);
	int edit(record_label & action);
	int remove(record_label & action);

//	~~~~~~ outside questions

int display();
int edit(record_label& action);
int remove(record_label& action);
int whattodo();

bool ask();
bool ask_main();

int main()
{
	record_label action;

do{
	int task = whattodo();
	if(task==0)
	questions(action);

	else if(task ==1)
	display();

	else if(task == 2)
	edit(action);
	else if(task == 3) remove(action); 
	
	else
	return 0;
}while(ask_main()==true);

}

//implementation

// ************************ start questions function
int questions(record_label & action)
{
	do{

		name(action);// has a LLL

		// has a separate LLL
		songs(action);
		//class function
		//add these to LLL.
	}while(ask()== true);
	return 1;
}


int name(record_label &action)
{
	
	char *artist = new char[MAX];
	char *top_story = new char[MAX];
	char *description = new char[MAX];
	char *genre = new char[MAX];


	do{
	cout << "what is the name of the artist?" << endl;
	cin.get(artist, MAX, '\n');
	cin.ignore(MAX, '\n');

	// insert in a LLL by passing it into object

	cout<< "what is the top story for this artist?" << endl;
	cin.get(top_story, MAX, '\n');
	cin.ignore(MAX, '\n');
	//insert in a LLL
		// class int artist_topstory();

	cout << "when did the artist join?" << endl;
	cin.get(description, MAX, '\n');
	cin.ignore(MAX, '\n');

	cout << "what genre?" << endl;
	cin.get(genre, MAX, '\n');
	cin.ignore(MAX, '\n');
	//insert in a LLL process by going into class member
	action.add_artist(artist, top_story, description, genre);
	cout << "do you want to add another artist? press y for yes and n for no after asked to continue." << endl;
	delete [] artist;
	delete []top_story;
	delete [] description;
	delete [] genre;
	}while(ask() == true);

	return 1;
}

int songs(record_label& action)
{
	char* title = new char[MAX];
	char* artist = new char[MAX];
	int length; 
	int num_of_views; 
 	int num_of_likes;

	cout << "Title of Song?" << endl;
	cin.get(title, MAX, '\n');
	cin.ignore(100, '\n');

	cout << "Length of Song?" << endl;
	cin >> length;
	cin.ignore(100,'\n');

	cout << "Number of Views?" << endl;
	cin >> num_of_views;
	cin.ignore(100,'\n');

	cout << "Number of Likes?" << endl;
	cin >> num_of_likes;
	cin.ignore(100,'\n');
	
	cout << "what is the artist" << endl;
	cin.get(artist, 100, '\n');
	cin.ignore(100, '\n');

	action.add_song(title, length, num_of_likes, num_of_views, artist);
	return 1;
	//insert into a LLL process
}

	// ************************************** end of questions function

//************************************** start of display function *******
int display()
{
	char* artist_char;
	char* song_char;
	char* buffer = new char[MAX];
	record_label action;// all is accessed from struct artist_node
	artist name;
	song title;
	cout << "Do you want to display artists or song for an artist? Type a for artist or s for song." << endl;
	cin.get(buffer, MAX, '\n');
	cin.ignore(MAX,'\n');

	if(strcmp(buffer, "a")== 0)
	{
		cout << "which artist?" << endl;
		cin.get(buffer, MAX,'\n');
		cin.ignore(MAX, '\n');
		if(strcmp(name.artist_name, buffer)==0)
		{
			artist_char = buffer;
			action.display_artist(artist_char);
			delete [] buffer;
		}
		

	}
	else
	{
		cout << "which song for an artist?" << endl;
		cin.get(buffer, MAX,'\n');
		cin.ignore(MAX, '\n');
		if(strcmp(name.artist_name, buffer)==0)
		{
			song_char = buffer;
			action.displayall_song_byLikes(song_char);
			delete [] buffer;
		}
	
	}
	return 1;
}

// end of display function


int edit(record_label &action)
{
	char artist[100];
	char song[100];
	char likes_or_views;
	int new_response;

	cout << " to edit song of an artist, which artist of the song?" << endl;
	cin.get(artist, 100, '\n');
	cin.ignore(100, '\n');

	cout << "which song do you want to edit from the artist?" << endl;
	cin.get(song, 100, '\n');
	cin.ignore(100, '\n');

	cout << "do you want to change likes or views?(l or v)" << endl;
	cin >> likes_or_views;

	 cout << "what is the new amount" << endl;
	 cin >> new_response;
	
	action.edit_views_likes(artist, song, likes_or_views, new_response);
	return 1;
}


int remove(record_label &action)
{
	int remove_number_m;
	cout << "to remove a songs that are less then the amount wanted, type in a number that must be met" << endl;
	cin >> remove_number_m;
	action.remove_all(remove_number_m);
	return 1;

}



bool ask()
{
	char *buffer = new char[MAX];
	cout << "do you want to add another?" << endl;
	cin.get(buffer, MAX, '\n');
	cin.ignore(MAX, '\n');
	int len = strlen(buffer);

	for(int i = 0; i<len; ++i)
	{
		buffer[i] = toupper(buffer[i]);
	}

	if(strcmp(buffer,"YES")==0 || strcmp(buffer,"Y")==0)
	{return true;}
	return false;
}


bool ask_main()
{
	char *buffer = new char[MAX];
	cout << "do you want to continue with another action?" << endl;
	cin.get(buffer, MAX, '\n');
	cin.ignore(MAX, '\n');
	int len = strlen(buffer);

	for(int i = 0; i<len; ++i)
	{
		buffer[i] = toupper(buffer[i]);
	}

	if(strcmp(buffer,"YES")==0 || strcmp(buffer,"Y")==0)
	{return true;}
	return false;
}

int whattodo()
{
	int answer;
	cout << "please type what you want to do. 0 to add artist, 1 to display, 2 to edit, 3 to remove" << endl;
	cin >> answer;
	cin.ignore(100, '\n');
	return answer;
}
//********************************************************struct***********************************
// constructor

artist:: artist()
{
	artist_name = NULL;
	artist_topstory	= NULL;
	artist_info	= NULL;
	artist_genre	= NULL;
}
song::song()
{
	title = NULL;
}
	
node_song:: node_song()
{
	data = NULL;
}
node_artist:: node_artist()
{
	data = NULL;
}

// deconstructor
artist :: ~artist()
{	
	if(artist_name)
	{
		delete artist_name;
		artist_name= NULL;
	}

	if(artist_topstory)
	{
		delete artist_topstory;
		artist_topstory = 0 ;
	}
	if(artist_info)
	{
		delete artist_info;
		artist_info = 0 ;
	}
	if(artist_genre)
	{
		delete artist_genre;
		artist_genre = 0 ;
	}

}
song::~song()
{
	if(title)
	delete[] title;
}

node_song::~node_song()
{
	if(data)
	delete [] data;
}
node_artist:: ~node_artist()
{
	if(data)
	delete [] data; 
}


//********************************************************class*************************************




//constructor
record_label:: record_label()
{
	head = NULL;
	count = 0;
}
//destructor
record_label:: ~ record_label()
{	
	
	/*
	node_artist *temp = head-> next;
	delete head;
	head = temp;
	node_artist *temp;
	//node *temp;
	while (head)
		{
			node_song song_temp;
		while(head->data_song)
		{
			song_temp = head -> data_song-> next;
			
			delete [] head-> data_song -> data -> title;
			delete [] head -> 
			
			

		}

	}
*/
}

//members of class



int record_label:: add_artist(char* artist1, char * top_story, char* description, char* genre) //
{
	node_artist* temp = new node_artist;
	temp -> data = new artist;
	if(head==NULL)
	{

		cout << "blah" <<endl;
		temp -> data->artist_name = artist1;
		temp -> data -> artist_topstory = top_story;
		temp -> data -> artist_info = description;
		temp -> data -> artist_genre = genre;

		temp -> next = head;
		head = temp;
		head -> next = NULL;
		count =count +1;
		return 1;
		
	}

	while(head != NULL)
	{
		temp -> data->artist_name = artist1;
		temp -> data -> artist_topstory = top_story;
		temp -> data -> artist_info = description;
		temp -> data -> artist_genre = genre;

		head = temp;
		head = head -> next;
		head ->next = NULL;
		count = count +1;
	}
	return 1;
}
 
int record_label ::add_song(char* title, int length, int num_of_likes, int num_of_views, char *artist_name)//gets the infor from the client program"wrapper"
{
    return add_song(title, length, num_of_likes, num_of_views, head, artist_name);
}
int record_label:: add_song(char* title, int length, int num_of_likes, int num_of_views, node_artist *& head, char* artist_name)//gets to correct artist
{
    node_artist *current = head;
    //traverse the artist list
    //current ==null for while loop 
    //in case there isnt an artist in the list.
    while((current != NULL) && (strcmp(current ->data -> artist_name, artist_name)!=0))
    {
        
        
        current = current -> next;
    }
    if(current == NULL)
    {
        return 0;
    }
    else 
    {
        return add_song(title, length, num_of_likes, num_of_views, current -> data_song);
    }
    
}

int record_label:: add_song(char *title, int length, int num_of_likes, int num_of_views, node_song *& head)
{	
	
	node_song *current = head;
        node_song *temp = new node_song;
        temp -> next = NULL;
        //fill it up
        temp -> data = new song;
        temp -> data ->title = new char [strlen(title)+1];
        strcpy(temp -> data -> title, title);//TODO Fill the rest of the linked list
        
        
        
	if((head==NULL) || (head->data-> num_of_likes < num_of_likes))
	{
            
            temp -> next = head;
            
            head = temp;
            temp = NULL;

		
		return 0;
	}

	while( (current-> next != NULL) && (current -> next -> data -> num_of_likes < temp -> data -> num_of_likes)  )//while not in the end of the list and curreent next data is smaller then temp data
        {
            
            current = current -> next;
            
        }
        
        //connect it up
        
        
        temp -> next = current -> next;
        current -> next = temp;
        
        
        temp = NULL;        
	return 1;
}

int record_label:: display_artist(char* artist)
{
	//search artist
	
	node_artist *current = head;
	if(head==NULL){cout << "nothing to display" << endl; return 0;}

	//while(current != NULL)
	//{
	if(strcmp(head-> data ->artist_name, artist)== 0)
	{
		cout << current-> data -> artist_name <<  current-> data -> artist_genre <<current -> data -> artist_info << current -> data -> artist_topstory << endl;
		
		//current = current -> next;
	}
	//}
	delete [] artist;
	return 1;

}



int record_label:: displayall_song_byLikes(char *song)
{
	node_artist *current = head;
	int compare_likes;
	if(head==NULL){cout << "nothing to display" << endl; return 0;}
	if(strcmp(current->data_song -> data -> title, song)== 0)
	{
		
		//sort();
		while(current != NULL)
		{
			
			if(current -> data_song -> data -> num_of_likes > compare_likes)
			{
				current -> data_song -> data ->num_of_likes = compare_likes;
			}
			if(compare_likes > current -> data_song -> data -> num_of_likes)
			{
				//current -> data_song;
			}
	/*		else if(current -> data_song -> likes < compare_likes)
			{
				//current -> data_song -> likes = compare_likes;
			}*/

			current = current -> next;
		
		}
		cout << current-> data_song -> data -> title <<  current-> data_song -> data ->length  <<current -> data_song -> data -> num_of_views << current -> data_song -> data ->num_of_likes << endl;
	}
		//current = current -> next;
	delete [] song;
	return 1;
}

int record_label:: edit_views_likes(char artist[], char song[], int likes_or_views, int new_response)
{
		{
		if(toupper(likes_or_views)== 'V' )
		{

		}
		else if( toupper(likes_or_views) == 'L')
		{
			//TODO 
		

		}
	}

	return 1;
}


int record_label:: remove_all(int remove_number_m) 
{


	return 1;
} 
