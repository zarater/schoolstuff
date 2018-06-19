#include "prog1.h"

using namespace std;


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
record_label:: ~ record_label()//space is deallocated inside the structs seg faults if deallocate head
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



int record_label:: add_artist(char* artist1, char * top_story, char* description, char* genre) //adds a temp to be inserted in a LLL to display
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

int record_label:: add_song(char *title, int length, int num_of_likes, int num_of_views, node_song *& head)//inserts in a linked list
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

int record_label:: display_artist(char* artist)//displays artist
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



int record_label:: displayall_song_byLikes(char *song)//displays songs of artist by likes
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

int record_label:: edit_views_likes(char artist[], char song[], int likes_or_views, int new_response)// edits a linked list
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


int record_label:: remove_all(int remove_number_m) //removes from linked list 
{


	return 1;
} 
