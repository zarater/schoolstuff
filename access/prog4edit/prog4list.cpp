#include "prog4.h"

//function implementation

//constructor

pointer::pointer()// will initialize three variables. 
{
	ideas = new summerplan[100];// this is the dynamically allocated space
	totalsize = 100;// this is the total size that if the array is smaller will add to the array size
	actualsize=0; // this will initialize the size for i and also resize the space if array is too big.

}




//destructor
pointer::~pointer()//deallocates memory that was previously reserved.
{
	if (ideas)
		delete [] ideas;
}




void pointer::addtolist()
{
	int i = actualsize;
	do
	{
		info();//info asks six questions.
		++i; // increments to tell the function how many events are in existince and to also proceed to the next variable.
	//	changespace ();//changes space based on the amount the userinputs.
	
	} while ( asktoaddevent() == true);

	actualsize = i;// this is the actual size of the user input.
	turnitintofile();//this function will turn info into the .txt file using ofstream.
}




//will check if change the dynamic space if to new amount everytime the user inputs a new event. it also adds an extra amount of space incase the user inputs above 100 events.
void pointer::changespace()
{
	
		if (actualsize >= totalsize)//create new space to for the user if it is 
		{
			summerplan* newspace = new summerplan[totalsize+100];
			for (int cycle = 0; cycle < actualsize; ++cycle)//copies information to new array if its array is bigger then totalsize
			{
				newspace[cycle] = ideas[cycle];
			}
			//free old memory
			delete [] ideas;//delets old.
			ideas = newspace;//adds new
			totalsize = totalsize + 100;
		}
		if (actualsize < totalsize)
		{
			totalsize=actualsize;
			ideas[totalsize];	
		}	
}




//this function will look up one event. it calls on a function onscreen and alreadyin. the alreadyin function opens the .txt file and the onscreen displays which event.
void pointer::oneevent()
{
	int i = actualsize;// make int i into actualsize to use it in the function.
	char userresponse[SUMSIZE];//this asks the user to input something to check an existing list.
	if(alreadyin()==false)
		{
			cout << "Please add an event before checking an event." << endl;
			return; 
		}
	if(alreadyin()==true)
	{
	cout << "Please type an event in the existing list" << endl;
	cin.get(userresponse, SUMSIZE-1, '\n'); //expects user input.
	cin.ignore(100, '\n');
		
	for (int j = 0; j< i; ++j) // loops for the counter.
	{	
		if (strcmp(ideas[j].nameofplace, userresponse)!=0)
		{
			cout << "No matching places exist. Please add or try again." << endl;
		}
		else if (strcmp(ideas[j].nameofplace, userresponse)==0)// if it is true, it will initiate that the information at position j. j will be searching the position of name of place until userresponse and nameof place is 0.and when it is 0 it will then display that place at j.

		{
			cout << "This is the information for the place: " << endl;
			onscreen(j); // displays all info for that place.
		}
		
	}
	}
}




void pointer::allevents()
{
	int i = actualsize; // uses int i so that it doesnt change actual size. and uses i inside the function but at the end actualsize will be changed.
	cout << "All the events on file: " << endl;
	int len; //  len will be used inside the loop max length.
	len = i; // passes  i length size
	if(alreadyin()==false)
	{
		cout << "Please add an event before checking all events." << endl;
		return;
	} 
	//if(alreadyin()==true)
	//{
	for ( int j = 0; j < len; ++j)
	{
		onscreen(j); // onscreen displays all at the position described.
	}
	//}
}




// this function asks six questions to the user. it is stored in the dynamic arrays.
void pointer::info()
{
	int i = actualsize;
	cout << "Please type a place wanted to visit in the summer!" << endl; // place where desired to go
	cin.get (ideas[actualsize].nameofplace, PLACESIZE-1);
	cin.ignore(PLACESIZE, '\n');

	cout << "Please type a description of the place wanted to  visit in the summer!" << endl; // description of  where desired to go
	cin.get (ideas[actualsize].description, DESCSIZE - 1);
	cin.ignore(DESCSIZE, '\n');


	cout << "Please type the address of summer location wanted to visit in the summer!" << endl; // place where desired to go
	cin.get (ideas[actualsize].location, LOCATIONSIZE - 1);
	cin.ignore(LOCATIONSIZE, '\n'); 

	cout << "What dates would you visit?" << endl; // dates information. this information could be any type of input. 
	cin.get (ideas[actualsize].dates, DATESIZE - 1);
	cin.ignore(DATESIZE, '\n');


	cout << "Have you been to this summer place?" << endl;// asks the user if they have been to the event before.
	cin.get (ideas[actualsize].question1, QUESTION1SIZE - 1);
	cin.ignore(QUESTION1SIZE, '\n');


	cout << "How many times have you attended this summer place?" << endl; // // asks the user how many times they have been here. this will take any size incase user would like to input more information about how many times they have been.
	cin.get (ideas[actualsize].question2, QUESTION2SIZE-1);
	cin.ignore(QUESTION2SIZE, '\n');
	++actualsize;
}




//this function displays all information in the position of the counter. it waits to receive the counter and then displays it.
void pointer:: onscreen(int j)
{
	cout << "\nPlan Number: " << j+1 << endl;
	cout << "Place: " << ideas[j].nameofplace <<'\n'
		<< "Desciption: " << ideas[j].description << '\n'
		<< "Location: " << ideas[j].location << '\n'
		<< "Dates: " << ideas[j].dates << '\n'
		<< "Place Visitations: " << ideas[j].question1 << '\n'
		<< "Visitiation Frequency: " << ideas[j].question2 << '\n';
}



//turns the array of structs into files.
bool pointer::turnitintofile()
{
	ofstream writeintotxt;
	int i = actualsize;
	int k = 0;//is a counter to increment up to the limit, len.
	int len = i;// initialize len to be the amount of arrays of structs.
	writeintotxt.open(filename);

	if(!writeintotxt)
	{
		cout<< "Will not work... loading...." << endl;
		return false;
	}
	else
	{
		//sends to .txt file
		for(k; k< len; ++k)
		{
			writeintotxt << ideas[k].nameofplace << "#"
				<< ideas[k].description << "#"
				<< ideas[k].location << "#"
				<< ideas[k].dates << "#"
				<< ideas[k].question1 << "#"
				<< ideas[k].question2 << '\n';
		}
		writeintotxt.clear();
		writeintotxt.close();
	}
	return true;
}
	

		

//extracts that information to the dynamic array. it also is a bool result so that it could check whether or it exists already or not.
bool pointer::alreadyin()
{
	int i = 0;//temporarily assigns i to use as local variable 
	ifstream alreadyintxt;
	alreadyintxt.open(filename);

	if (!alreadyintxt)
	{
		return false;
	}
	//get all info from .txt file.
	alreadyintxt.get(ideas[i].nameofplace, PLACESIZE, '#');
	while (alreadyintxt && !alreadyintxt.eof())
	{
		alreadyintxt.ignore(100, '#');
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
	}
	actualsize=i;//i gets re sent back to actualsize
	alreadyintxt.clear();
	alreadyintxt.close();
	return true;

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

