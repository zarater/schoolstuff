#include "prog4.h"

int main()
{
	//int main will have 4 main functions withing it. it will variables into the functions. after variables pass in, they will be looped until the user is satisfied with adding. 
	//there will be four main functions: add new information, look up event, look up all events, and exit the program. all functions will ask the user once more if they want to continue adding.

	//variable declerations
	// the file name is pre made based on assignment. the adding a .txt is in a function to be called.
	
	pointer event;
	int response;
	

	//function call

	event.alreadyin();
	do
	{
		cout << " Please type what you want to do: " << endl;
		cout << " Press 1 to add to an existing list. Press 2 to check for a particular event. press 3 to display all. press 4 to exit." << endl;
		
		cin >> response;
		cin.ignore();


		if (response == 1)// add to list
		{
			event.addtolist();
		}
		else if (response == 2)//look up a event
		{
			event.oneevent();
		}
		else if (response == 3)//look up all events
		{
			event.allevents();
		}
		else if (response == 4)//exit the program
		{
			return 0;

		}
	} while (event.ask() == true);
	return 0;
}

