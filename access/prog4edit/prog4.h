/*
Name Raul Zarate
Class: Computer Science
section: CS163
Assignment Number: Program 4
Date: 5/14/ 2017

Description of Program:

This program's goal is to have a Dynamically allocated array and use the class object in order to create some space. After space has been created, re-size that array to fit the user space so that there isn't any floating unused memory space user isn't using. 

the program will be divided into three sections: the ".h," ".cpp," and ".cpp." The ".h" file will handle the Constant,Struct, Class, Prototype Definitons. main will be in  "main.cpp" and the final ".cpp" file will contain the implementation files of all the above.
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

// Constants
// They will have the sizes for arrays.
const int PLACESIZE = 30;
const int DESCSIZE = 100;
const int LOCATIONSIZE = 50;
const int DATESIZE = 30;
const int QUESTION1SIZE = 20;
const int QUESTION2SIZE = 100;
const int SUMSIZE = 100;
const int NEWSIZE = 100;
const char filename[16] = "Summer_List.txt";
const int YESNO = 4;
//Structs
// These members will have array size for input later.
// Will have six member: 

struct summerplan // summer plan will have be dynamically allocated.
{
	char nameofplace[PLACESIZE]; // This member is used to ask the place of event desired
	char description[DESCSIZE]; // this will carry the description array.
	char location[LOCATIONSIZE]; 
		// all these arrays are char arrays because user could input num and letters in it. for example, Feburary 10th, 10, 28, 2017.
	char dates[DATESIZE];// will carry the date of event.
	char question1[QUESTION1SIZE];// will ask if they attended before
	char question2[QUESTION2SIZE]; // will ask how often have they attendedf.
	
};



class pointer// will dynamically allocate the memory to the user.
{
	public:
		pointer(); // default constructor.
		~pointer();// destructor.
// prototype functions are instead placed here as members.
// the first three functions will carry the weight of the program. they will use the other functions as methods.

		void addtolist();// add a list in function. it callse on three functions in it. these fuctions are: info, turnintofile, and alreadyin.
		void oneevent(); // displays a event already in a .txt file by asking the user for which event ehy want specifically.
		void allevents(); // displays all events.

		// these functions are used in order for the above functions to work.
		// these functions are used within the three main function illustrated above.
		void info(); //adds to a list with six fquestions to the user.
		bool turnitintofile(); // turns a array of structs into a txt file to be saved.
		bool alreadyin(); //opens information in a txt file. it also returns a boolean result to check if new information needs to be added. if not, it will make a new file.
		bool ask();// asks the user if they want to keep adding to the list.
		bool asktoaddevent();//asks the user to add another event or not.	
		void onscreen(int j); // displays what has already been made to the user.
		void changespace();// addspace or recreates space. if the user input less events then the space will turn smaller. if the user needs more then 100 events it will add more.
	private:
		summerplan *ideas; // dynamically allocated space
		int totalsize; // this is a size to be added if the user input is bigger.
		int actualsize; // this is the size of array. it is replaced with i inside function as a counter.

};


	






