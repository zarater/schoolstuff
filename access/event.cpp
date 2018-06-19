/*

Name: Raul Zarate
class: Computer Science
section: CS163
assignment number: Program 3
Date: 5/14/2017

Description of program:
This program will have a couple things in it. as the program cycles through the list of things user wanted to do this summer,
it will ask six specific things from the user.the struct will ask those questions to the user.
I will implement those functions with that will be needed to store the six items in external files and call them when done to the user
to read the results.
The program will have four main functions in it. first, will add information or make a new txt file. second, will check if there is an event in it.
third, will read all. Finally, the fourth will exit the program . All main functions will loop through until user is done.


*/



#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;
class marina ()
{
	public:
	private
};
//constants used as array size
const int PLACESIZE = 30;
const int DESCSIZE = 100;
const int LOCATIONSIZE = 50;
const int DATESIZE = 30;
const int QUESTION1SIZE = 20;
const int QUESTION2SIZE = 100;
const int SUMSIZE = 100;
//structs
//will have six members. these members will have array size for input later.
struct summerplan
{
	char nameofplace[PLACESIZE];//this member is used to ask the place of event desired.
	char description[DESCSIZE];//this array member has space for a description of a place.
	char location[LOCATIONSIZE];//this array has a size to ask location.
	char dates[DATESIZE];		//this array has a size  to ask dates.
	char question1[QUESTION1SIZE];//this array has a size to ask didyouattend.
	char question2[QUESTION2SIZE];//this array has a size to ask howoften.
};



//prototype functions
// these functions are in main and ask the user what they want to do. it will then loop for a yes or no response to continue.


void addtolist(summerplan ideas[], int i, char filename[]);//add to a list function. it calls on three functions in it. : info, turnintofile, and already in.
void oneevent(summerplan ideas[], int i, char filename[]);// displays a event already in a a .txt file by asking the user for which event they want specifically.
void allevents(summerplan ideas[], int i, char filename[]);// displays al events.




  // functions needed to be used in order for the above functions to work.
  //these functions are used within the three main functions illustrated above.
void info(summerplan ideas[], int &i); // adds to a list with six questions to the user. that info works with turnintofile and already in. the user will be inputting into sturcts.
bool turnitintofile(summerplan ideas[], int i, char filename[]); //turns a array of structs into a txt file to be saved.
bool alreadyin(summerplan ideas[], int& i, char filename[]);//opens information in a txt file. it also returns a boolean result to check if new information needs to be added. if not, it will make a new file.
bool ask();// asks the user if they want to keep adding to the list.
void getfilename(char filename[]);// turnst file name into a .txt file.
void onscreen(summerplan[], int &j);// displays what has already been made to the user.






int main()
{
//int main will have 4 main functions withing it. it will variables into the functions. after variables pass in, they will be looped until the user is satisfied with adding. 
//there will be four main functions: add new information, look up event, look up all events, and exit the program. all functions will ask the user once more if they want to continue adding.

	//variable declerations
	char filename[12] = "summer-list";// the file name is pre made based on assignment. the adding a .txt is in a function to be called.
	summerplan ideas[SUMSIZE];// the structs ask the user to 
	char filename[12] = "summer-list";// the file name is pre made based on assignment. the adding a .txt is in a function to be called.
	summerplan ideas[SUMSIZE];// the structs ask the user to 
	int i = 0;//increment through ideas columns and also how many summer ideas there are in total
	getfilename(filename);

	//function call


	do
	{
		cout << " Please type what you want to do: " << endl;
		cout << " Press 1 to add to an existing list. Press 2 to check for a particular event. press 3 to display all. press 4 to exit." << endl;
		int response;
		cin >> response;
		cin.ignore();



		if (response == 1)// add to list
		{
			addtolist(ideas, i, filename);
		}
		else if (response == 2)//look up a event
		{
			oneevent(ideas, i, filename);
		}
		else if (response == 3)//look up all events
		{
			allevents(ideas, i, filename);
		}
		else if (response == 4)//exit the program
		{
			return 0;
		}
	} while (ask() == true);
	return 0;
}


//function implementation

// addtolist function adds to a list in existance or makes a new list. it will first check to see if there is a loop, then it will add to a list.
void addtolist(summerplan ideas[], int i, char filename[])
{
	if (!alreadyin(ideas, i, filename))//read whats in the file but if not..
	{
		cout << "Start adding into summer list." << endl;
	}

	do// this will loop unitl the user is done
	{
		info(ideas, i);// info asks six questions.
		++i;//i increments to tell the function how many events are in existance and to also proceed to the next variable.

	} while (ask() == true);


	turnitintofile(ideas, i, filename);//this function will turn it info in into a struct.
}



//this function will look up one event. it calls on a function onscreen and alreadyin. the alreadin function opens the .txt file and the onscreen displays which event.
void oneevent(summerplan ideas[], int i, char filename[])
{
	char userresponse[SUMSIZE];//initializes the size of array
	cout << " Please type an event in the existing list" << endl;
	cin.get(userresponse, 99, '\n');//expects user input.
	cin.ignore(100, '\n');

	alreadyin(ideas, i, filename);//opens the .txt file.
	for (int j = 0; j<i; ++j)// loops for the counter.
	{
		if (strcmp(ideas[j].nameofplace, userresponse) == 0)// compares the info in the file with the info the user input.
		{
			cout << "this is the info for the place: " << endl;
			onscreen(ideas, j);//displays all info
		}
	}

}



//all events will be displayed to the user. this function works similar to oneevent except it calls on all events instead of one.
void allevents(summerplan ideas[], int i, char filename[])
{

	cout << "all the events on file: " << endl;

	alreadyin(ideas, i, filename);
	int len;// initialize len
	len = i;//set len to the counter. len is the size of how many events in.
	for (int j = 0; j < len; ++j)
	{
		onscreen(ideas, j);//onscreen displays.
	}
}


//this function adds to a filename. its needed if there are multiple files but it does what it needs to to make the file name into a .txt file.
void getfilename(char filename[])
{
	strcat(filename, ".txt");//strcat concatinates the summer-list to .txt. it's used for multiple files, however, it does exactly what it needs to.

}


// this function ask six questions to the user. it is stored in arrays of structs.
void info(summerplan ideas[], int& i)
{

	cout << "Please type a Place wanted to visit in the summer!" << endl;// place where desired to go
	cin.get(ideas[i].nameofplace, PLACESIZE - 1);
	cin.ignore(PLACESIZE, '\n');

	cout << "Please type the description of the place wanted to visit." << endl;// description of place
	cin.get(ideas[i].description, DESCSIZE - 1);
	cin.ignore(DESCSIZE, '\n');

	cout << "Please type a the address of summer location" << endl;// description of location
	cin.get(ideas[i].location, LOCATIONSIZE - 1);
	cin.ignore(LOCATIONSIZE, '\n');

	cout << "What dates would you visit?" << endl;// dates information
	cin.get(ideas[i].dates, DATESIZE - 1);
	cin.ignore(DATESIZE, '\n');

	cout << "Have you been to this summer place?" << endl;// did you attend question
	cin.get(ideas[i].question1, QUESTION1SIZE - 1);
	cin.ignore(QUESTION1SIZE, '\n');

	cout << "Have you many times have you attended?" << endl;// how many times did you attend
	cin.get(ideas[i].question2, QUESTION2SIZE - 1);
	cin.ignore(QUESTION2SIZE, '\n');
}



//this function displays all information in the position of the counter. it waits to receive the counter and then displays it.
void onscreen(summerplan ideas[], int &j)
{
	cout << "\nPlan number: " << j + 1 << endl;
	cout << "Place: " << ideas[j].nameofplace << '\n'
		<< "Description" << ideas[j].description << '\n'
		<< "Location: " << ideas[j].location << '\n'
		<< "Dates: " << ideas[j].dates << '\n'
		<< "Summer place visitations: " << ideas[j].question1 << '\n'
		<< "visitation frequency: " << ideas[j].question2 << endl << endl;

}



//turns the array of structs into files. 
bool turnitintofile(summerplan ideas[], int i, char filename[])//turns info from a list into a file
{
	ofstream writeintotxt;
	int k = 0;// is a counter to incrememtn up to the limit, len.
	int len = i;// initializes len to be the amount of arrays of structs. the list 
	writeintotxt.open(filename);

	if (!writeintotxt)
	{
		cout << "Will not work.... loading...." << endl;
		return false;
	}
	else
	{
		//sends to .txt file
		for (k; k < len; ++k)
		{
			writeintotxt << ideas[k].nameofplace << "#"
				<< ideas[k].description << "#"
				<< ideas[k].location << "#"
				<< ideas[k].dates << "#"
				<< ideas[k].question1 << "#"
				<< ideas[k].question2 << '\n';

		}
		writeintotxt.close();
	}
	return true;
}



//opens the file and returns a true or false result. the file will open with position described by the counter.
bool alreadyin(summerplan ideas[], int &i, char filename[])
{
	ifstream alreadyintxt;
	alreadyintxt.open(filename);

	if (!alreadyintxt) {
		return false;
	}
	// get all info from .txt file.
	alreadyintxt.get(ideas[i].nameofplace, PLACESIZE, '#');
	alreadyintxt.ignore(100, '#');
	while (alreadyintxt && !alreadyintxt.eof())
	{
		alreadyintxt.get(ideas[i].description, DESCSIZE, '#');
		alreadyintxt.ignore(DESCSIZE, '#');
		alreadyintxt.get(ideas[i].location, LOCATIONSIZE, '#');
		alreadyintxt.ignore(LOCATIONSIZE, '#');
		alreadyintxt.get(ideas[i].dates, DATESIZE, '#');
		alreadyintxt.ignore(DATESIZE, '#');
		alreadyintxt.get(ideas[i].question1, QUESTION1SIZE, '#');
		alreadyintxt.ignore(QUESTION1SIZE, '#');
		alreadyintxt.get(ideas[i].question2, QUESTION2SIZE, '\n');
		alreadyintxt.ignore(QUESTION2SIZE, '\n');
		++i;
		alreadyintxt.get(ideas[i].nameofplace, PLACESIZE, '#');
		alreadyintxt.ignore(100, '#');
	}
	alreadyintxt.clear();
	alreadyintxt.close();
	return true;

}



//asks the user if they would like to continue in 8 different scenrios. if the user inputs anything besides the 8, it will be false automatically.
bool ask()
{
	const int yesno = 4;// expects a yes, no, YES, NO, Y, N, n, or y.
	int len;// will be initialized
	int i = 0;
	char userresponse[yesno];
	cout << "do you want to continue?" << endl;
	cin.get(userresponse, yesno, '\n');//asks user for a response
	cin.ignore(100, '\n');
	len = strlen(userresponse);// initializes len

	for (i; i < len; ++i)
	{
		userresponse[i] = (toupper(userresponse[i]));//upper cases all 
	}
	if ((strcmp(userresponse, "YES") == 0) || (strcmp(userresponse, "Y") == 0))
	{
		return true;
	}
	else if ((strcmp(userresponse, "NO") == 0) || (strcmp(userresponse, "N") == 0))
	{
		cout << "Thank you." << endl;
		return false;
	}
