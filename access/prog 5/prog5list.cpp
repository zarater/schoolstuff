#include "prog5.h"

//function implementation

//constructor
//default if no arguments
pointer::pointer()// will initialize three variables. 
{
		head = NULL;
}

//constructor
summerplan :: summerplan()
{

	nameofplace = NULL;
	description = NULL;
	location  = NULL;
	dates  = NULL;
	question1 = NULL;
	question2 = NULL;
	

}


//destructor
pointer::~pointer()//deallocates memory that was previously reserved.
{
	node *temp = head;
	while (head)
	{
		head = head -> next;
		delete temp;
		temp = head;
	}
}

//deconstructor for summerplan struct
summerplan :: ~summerplan()
{
	if (nameofplace)
		delete [] nameofplace;

	if (description)
		delete [] description;

	if (location)
		delete [] location;

	if (dates)
		delete [] dates;

	if (question1)
		delete [] question1;

	if (question2)
		delete [] question2;

};

// asks to copy in place inside a function.
/*
void summerplan::copyfunction(summerplan event)
{

if (nameofplace)
	{delete [] nameofplace;}

	nameofplace = new char [strlen(event.nameofplace)+1];
	strcpy(nameofplace, event.nameofplace);

if (description)
	{delete [] description; }
	description = new char [strlen(event.description)+1];
	strcpy(description, event.description);

if (location)
	{delete [] location;}
	location = new char [strlen(event.location) +1];
	strcpy(location, event.location);

if (dates)
	{delete [] dates;}
	dates = new char [strlen(event.dates) +1];
	strcpy(dates, event.dates);

if (question1)
	{delete [] question1;}
	question1  = new char [strlen(event.question1) +1];
	strcpy(question1, event.question1);

if (question2)
	{delete [] question2;}
	question2  = new char [strlen(event.question2) +1];
	strcpy(question2, event.question2);
}
*/


//asks six qustions from the user. primes the pump.
void summerplan:: receive()
{
	
	/*
	char description[] = " Description";
	cout << "description" << description << endl;

	char location[] = "location";
	cout << "location" << endl;
	
	char dates[] = "dates";
	cout << "dates" << dates << endl;

	char question1[] = "question1";
	cout << "qu 1" << question1<< endl;

	char question2[] = "question2";
	cout << "qu 2" << question2 << endl;
	*/
	char userresponse[200];
	if (nameofplace)
		{delete [] nameofplace;}
		cout << "name of place? " << endl;
		cin.get(userresponse, 100, '\n');
		cin.ignore(100, '\n');
		nameofplace = new char [strlen(userresponse)+1];
		strcpy(nameofplace, userresponse);

	if (description)
		{delete [] description;}
		cout << "destination details?" << endl;
		cin.get(userresponse, 100,'\n');
		cin.ignore(100, '\n');
		description = new char [strlen(userresponse)+1];
		strcpy(description, userresponse);

	if (location)
		{delete [] location;}
		cout << "location?" << endl;
		cin.get(userresponse, 100, '\n');
		cin.ignore(100, '\n');
		location = new char [strlen(userresponse) +1];
		strcpy(location, userresponse);

	if (dates)
		{delete [] dates;}
		cout << "dates?" << endl;
		cin.get(userresponse, 100, '\n');
		cin.ignore(100, '\n');
		dates = new char [strlen(userresponse) +1];
		strcpy(dates, userresponse);

	if (question1)
		{delete [] question1;}
		cout << "have you been here before?" << endl;
		cin.get(userresponse, 100, '\n');
		cin.ignore(100, '\n');
		question1  = new char [strlen(userresponse) +1];
		strcpy(question1, userresponse);

	if (question2)
		{delete [] question2;}
		cout << "how many times?" << endl;
		cin.get(userresponse, 100,'\n');
		cin.ignore(100, '\n');
		question2  = new char [strlen(userresponse) +1];
		strcpy(question2, userresponse);	

}


//adds to a list from the user
void pointer::addtolist()
{
	cout << "add to list" << endl;
	do
	{

		node *current = new node;
		current -> data.receive();
		current -> next = head;
		head = current;
	
		cout << " do you want to keep adding events? " << endl;
	} while ( asktoaddevent() == true);

}



//this function will look up one event. 
//It calls on a function onscreen and alreadyin. 
void pointer::oneevent()
{
	int i = actualsize;// make int i into actualsize to use it in the function.
	char userresponse[SUMSIZE];//this asks the user to input something to check an existing list.
	node * current = head;
	node *previous = head;
	node *temp = head;


	if (!head)
	{
	cout << "nothing in the list. Please add" << endl;
	return;
	}


	cout << "Please input which event you want to look up or delete." << endl;
	cin.get(userresponse, 100, '\n');
	cin.ignore(100, '\n');



		while(current)
		{
			if (strcmp(current -> data.nameofplace, userresponse)==0)
			{
				cout << "This is the information for the place: " << endl;
				current -> data.onscreen(); // displays all info for that place.
				

				cout << "Do you want to delete this event? If you want to delete this type yes after being asked to continue." << endl;
				if (ask()==true)
				{
					//if (current == NULL)
					//{
						//cout << "nothing in the list to delete" << endl;
						//return;
					//}
					//if one,. deletes one item or in the last node.
					if (current-> next == NULL)
					{
						head = head -> next;
						head = NULL;
						delete previous;
					}
					/*
					if(current->next ==NULL)
					{
					current = current -> next;
					head = current;
					delete previous;
					head-> next = NULL;
					}
					*/
					/*previous = current;
					temp = current -> next;
					current = current -> next -> next;
					previous -> next = current;
					delete temp;*/
					//deletes in the middle
					///*
					//else if (current -> next != NULL)
					//{
					//if two
						//previous = current;
						//current -> next = current -> next -> next;
						//previous -> next = current -> next;
						//delete current;
						//current = current -> next;
					//}
						//*/
						/*

					*/
					//if middle qwer deletes e and w if while current 
					else if (current -> next -> next != NULL && current->next != NULL)
					{
						previous -> next = current;
						temp = current;
						current = current -> next;
						previous -> next = current;
						delete temp;

					}
					//if middle qwer deletes e and w if while current 
					else if (current -> next !=NULL && current -> next -> next ==NULL)
					{
						previous -> next = current;
						temp = current;
						current = current -> next;
						previous -> next = current;
						delete temp;

					}
				}
			
			}

			else if (strcmp(current ->data.nameofplace, userresponse)!=0)
			{
				cout << "No matching places exist. Please add or try again." << endl;
			}
			
			// this traverses and if it doesnt match it will continue
			// if there is a match it will traverse.
			// after function is done it will continue with the program.

			current = current -> next;	
		
			
		}
		cout << "If you want to continue the program say yes." << endl;
	}




//displays the list
void pointer::allevents()
{
	if (!head)
	{
	cout << " nothing in the list" << endl;
	
	return;
	}

	node *current = head;
	cout << "All the events on file: " << endl;
	while (current)
	{
		 current -> data.onscreen(); 
		current = current -> next;
	}

}






//this function displays all information in the position of the counter. it waits to receive the counter and then displays it.
void summerplan:: onscreen()
{
if (nameofplace==NULL)
	{
	return;
	}

	cout << "Place: " << nameofplace <<'\n'
		<< "Desciption: " << description << '\n'
		<< "Location: " << location << '\n'
		<< "Dates: " << dates << '\n'
		<< "Place Visitations: " << question1 << '\n'
		<< "Visitiation Frequency: " << question2 << '\n';
}







//asks user if they would like to continue in 8 different scenerios of yes and no.

bool pointer::ask()
{
	int len;// will be initialized
	int i = 0;
	char userresponse[YESNO];
	cout << "do you want to continue?" << endl;
	cin.get(userresponse, YESNO, '\n');//asks user for a response
	cin.ignore(100, '\n');
	len = strlen(userresponse);// initializes len to use in the loop

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
	return false;
}




//asks the user to add an event.
bool pointer::asktoaddevent()
{
	int len;// will be initialized
	int i = 0;// starts at 0 for the loop below.
	char userresponse[YESNO];// user needs to input.
	cout << "Do you want to continue adding events?\n Type yes to continue. If you don't wish adding events press no or any button to continue the program instead." << endl;
	cin.get(userresponse, YESNO, '\n');//asks user for a response
	cin.ignore(100, '\n');
	len = strlen(userresponse);// initializes len to use in the loop

	for (i; i < len; ++i)
	{
		userresponse[i] = (toupper(userresponse[i]));//upper cases all 
	}
	if ((strcmp(userresponse, "YES") == 0) || (strcmp(userresponse, "Y") == 0))
	{
		cout << "Pleas keep adding events" << endl;
		return true;
	}
	else if ((strcmp(userresponse, "NO") == 0) || (strcmp(userresponse, "N") == 0))
	{
		cout << "Press if you with to conitnue the program." << endl;
		return false;
	}
	return false;
}

