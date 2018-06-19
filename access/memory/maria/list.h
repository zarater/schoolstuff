//Maria Yates
//CS 162 Program 3
//This is the .h file for program three. This will contain the struct definition and function prototypes.

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

//*****************************************
//STRUCT DEFINITION
//*****************************************

struct activity
{
	char name[50];
	char description[50];
	char location[50];
	char date[20];
	char attended_last_year[15];
	int desire_to_go; //rating of desire to go from 1 to 10 with 1 being REALLY want to go
};

//*****************************************
//FUNCTION PROTOTYPES
//*****************************************

//loads in the data from external file
void load_from_file(activity summer_list[], int & i);

//exports data to external file
void export_to_file(activity summer_list[], int i);

//gets a new activity from the user
void new_activity(activity summer_list[], int & i);

//search for an existing activity
void activity_search(activity summer_list[], int i);

//display all activities
void display_all(activity summer_list[], int i);
