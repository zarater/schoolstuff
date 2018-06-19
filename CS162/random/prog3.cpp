/*
Name: Raul Zarate
class: Computer Science
section: CS163
assignment number: Program 3
Date: 5/14/2017

Description of program:
This program will have a couple things in it. as the program cycles through the list of things user wanted to do this summer, it will ask six specific things from the user. 
the struct will ask those questions to the user. I will implement those functions with that will be needed to store the six items in external files and call them when done to the user
to read the results. 

foot note: since i have no idea why we need files to use this, i will first do it using strucks only. after i have. but before that i will implement the functions that i need first.

*/



#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

//constants used as array size
const int placesize = 30;
const int descsize = 100;
const int locationsize = 50;
const int datesize = 30;
const int question1size = 20;
const int question2size = 100;
const int sumsize = 100;
//structs
//will have six members. these members will have array size for input later.
struct summer 
{
	char nameofplace[placesize];//this array has a size for the function to ask place.
	char description[descsize];//this array has a size for the function to ask description.
	char location[locationsize];//this array has a size for the function to ask location.
	char dates[datesize];		//this array has a size for the function to ask dates.
	char question1[question1size];//this array has a size for the function to ask didyouattend.
	char question2[question2size];//this array has a size for the function to ask howoften.
};



//prototype functions

void info(summer ideas[]);
void turnitintofile(summer ideas[]);
bool ask();





int main()
{

//variable declerations
	summer ideas[sumsize];
	

//function call
	do
	{
		info(ideas);
		turnitintofile(ideas);
	} while (ask() == true);

	return 0;
}


//function implementation

void info(summer ideas[])
{

	cout << "Please type a Place wanted to visit in the summer!" << endl;// place where desired to go
	cin.get(ideas.nameofplace, placesize);
	cin.ignore(placesize, '\n');

	cout << "Please type the description of the place wanted to visit." << endl;// description of place
	cin.get(ideas.description,descsize);
	cin.ignore(descsize, '\n');

	cout << "Please type a the address of summer location" << endl;// description of location
	cin.get(ideas.location, locationsize);
	cin.ignore(locationsize, '\n');

	cout << "" << endl;// dates information
	cin.get(ideas.dates, datesize);
	cin.ignore(datesize, '\n');

	cout << "Have you been to this summer place?" << endl;// did you attend question
	cin.get(ideas.question1, question1size);
	cin.ignore(question2size, '\n');

	cout << "Have you many times have you attended?" << endl;// how many times did you attend
	cin.get(ideas.question2, question2size);
	cin.ignore(question2size, '\n');
}

void turnitintofile(summer ideas[])
{


}

bool ask()
{
	const int yesno = 4;
	int len;
	int i = 0;
	char userresponse[yesno];
	cout << "do you want to continue?" << endl;
	cin.get(userresponse, yesno - 1, '\n');
	cin.get(userresponse, yesno);
	len = strlen(userresponse);

	for (i; i < len; ++i)
	{
		userresponse[i] = toupper(userresponse[i]);
		if (userresponse == "Y" || userresponse == "YES")
			return true;

		else if (userresponse == "N" || userresponse == "NO")
			return false;
	}

}
