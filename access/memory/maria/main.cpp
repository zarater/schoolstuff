//Maria Yates
//CS 162 Program 3
//This is the main.cpp file which contains the main function where all of the functions listed in .h will be called.
//This program is designed to keep a list of activities the user is interested in doing this summer.
//The program will give the user the option to add an item to the list, search for an activity, display everything, and quit
//the program. All of the activities will be stored in an external file so the list can be accessed at a later time.

#include "list.h"

using namespace std;

int main()
{
	//***********************
	//VARIABLES
	//***********************

	activity summer_list[100];
	int i = 0; //keeps track of number of items in the list of activities
	int response = 0; //user response 

	//**********************
	//FUNCTION CALLS
	//**********************
	
	load_from_file(summer_list,i);

	cout << "Main menu" << endl;
	cout << "Enter the number of the option you would like to choose: " << endl;
	cout << "1 - Add a new activity to the list" << endl;
	cout << "2 - Search for an existing activity" << endl;
	cout << "3 - Display all existing activities" << endl;
	cout << "4 - Exit the program" << endl;
	cin >> response;
	cin.ignore();

//	do
//	{
//	while(4 != response)
//	{
		
		if(1 == response)
		{
			new_activity(summer_list,i);
		}
	
		if(2 == response)
		{
			activity_search(summer_list,i);
		}

		if(3 == response)
		{
			display_all(summer_list,i);
		}
		
	/*	cout << "Main menu" << endl;
		cout << "Enter the number of the option you would like to choose: " << endl;
		cout << "1 - Add a new activity to the list" << endl;
		cout << "2 - Search for an existing activity" << endl;
		cout << "3 - Display all existing activities" << endl;
		cout << "4 - Exit the program" << endl;
		cin >> response;
		*/
//	}
	


//	}while(1 == response || 2 == response || 3 == response);


	export_to_file(summer_list,i);	
	
	return 0;
}
	
