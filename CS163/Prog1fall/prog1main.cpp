#include "prog1.h"

using namespace std;

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

}//implementation

// ************************ start questions function
int questions(record_label & action)// will ask artist and song information and place it in member class for traversal.
{
	do{

		name(action);// passes to LLL

		songs(action);//attempts to add a song and passes to LLL
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

		//asks the user questions and fills dynamically
	cout << "what is the name of the artist?" << endl;
	cin.get(artist, MAX, '\n');
	cin.ignore(MAX, '\n');


		//asks the user questions and fills dynamically
	cout<< "what is the top story for this artist?" << endl;
	cin.get(top_story, MAX, '\n');
	cin.ignore(MAX, '\n');
		// class int artist_topstory();
		//asks the user questions and fills dynamically

	cout << "when did the artist join?" << endl;
	cin.get(description, MAX, '\n');
	cin.ignore(MAX, '\n');

		//asks the user questions and fills dynamically
	cout << "what genre?" << endl;
	cin.get(genre, MAX, '\n');
	cin.ignore(MAX, '\n');
	//insert in a LLL process by going into class member
	action.add_artist(artist, top_story, description, genre);
	cout << "do you want to add another artist? press y for yes and n for no after asked to continue." << endl;
	//dealocates the space for the dynamica memory soon as its done.
	delete [] artist;
	delete []top_story;
	delete [] description;
	delete [] genre;
	}while(ask() == true);

	return 1;
}

int songs(record_label& action)// prompst the user and adds to class function
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

	action.add_song(title, length, num_of_likes, num_of_views, artist);// receives the arrays
	return 1;
	//insert into a LLL process
}

	// ************************************** end of questions function

//************************************** start of display function *******
int display()// prompts to display songs
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


int edit(record_label &action)//prompts and adds to the member class edit by views and likes
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


int remove(record_label &action)//prompts to delete m amount that is inputed by user
{
	int remove_number_m;
	cout << "to remove a songs that are less then the amount wanted, type in a number that must be met" << endl;
	cin >> remove_number_m;
	action.remove_all(remove_number_m);
	return 1;

}



bool ask()//asks to add 
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
	{
		delete [] buffer;
		return true;
	}

		delete [] buffer;
	return false;
}


bool ask_main() //asks to continue with a certain action similar to ask()
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
	{
		delete [] buffer;
		return true;
	}
		delete [] buffer;
	return false;
}

int whattodo()//asks what exactly to do inside int main
{
	int answer;
	cout << "please type what you want to do. 0 to add artist, 1 to display, 2 to edit, 3 to remove" << endl;
	cin >> answer;
	cin.ignore(100, '\n');
	return answer;
}