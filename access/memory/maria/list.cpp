//Maria Yates
//CS 162 Program3
//This is the .cpp file that contains function implementation. This is where the code for the prototypes will be.

#include "list.h"

using namespace std;
const char outfile[] = "summer_list.txt";
void load_from_file(activity summer_list[], int & i)
{
	//const char outfile[] = "summer_list.txt";
	//const int MAX = 255; //for reading in characters from a file
	ifstream in_file; //equivalent of cout for reading from a file.

	in_file.open("summer_list.txt");


	if(in_file) //checks to see if opening file was successful
	{
		//priming the pump
		in_file.get(summer_list[i].name,50,'#');
		in_file.ignore(100,'#');
		
		while(in_file && !in_file.eof())
		{
			in_file.get(summer_list[i].description,50,'#');
			in_file.ignore(100,'#');

			in_file.get(summer_list[i].location,50,'#');
			in_file.ignore(100,'#');
	
			in_file.get(summer_list[i].date,20,'#');
			in_file.ignore(100,'#');

			in_file.get(summer_list[i].attended_last_year,15,'#');
			in_file.ignore(100,'#');

			in_file >> summer_list[i].desire_to_go;
			in_file.ignore(100,'\n');

			++i;

			in_file.get(summer_list[i].name,50,'#');
			in_file.ignore(100,'#');
		}
	}
	
	in_file.close();
	in_file.clear();
}

void export_to_file(activity summer_list[], int i)
{
	//const char outfile[] = "summer_list.txt";
	//const int MAX = 255; //for reading in characters from a file
	ofstream out_file; //equivalent of cin for writing to external file

	out_file.open(outfile/*, ios::app*/);
	if(!out_file)
	{
		cout << "there is no file" << endl;
		return;
	}
	else
	{
		for(int j = 0; j<i; ++j)
		{
			out_file << summer_list[j].name << '#' 
			 << summer_list[j].description << '#' 
			 << summer_list[j].location << '#' 
			 << summer_list[j].date << '#' 
			 << summer_list[j].attended_last_year << '#' 
			 << summer_list[j].desire_to_go << '\n';
		}
	}
	
	out_file.close();
	out_file.clear();
}

void new_activity(activity summer_list[], int & i)
{
	//checks to see if array is empty, if not append new activityat the end
	/*if( i != 0)
	{
		i = i + 1;
	}*/
	cout << "Enter the name of the activity: " << endl;
	cin.get(summer_list[i].name,50);
	cin.ignore(50,'\n');

	cout << "Enter a short description: " << endl;
	cin.get(summer_list[i].description,50);
	cin.ignore(50,'\n');

	cout << "Enter the location: " << endl;
	cin.get(summer_list[i].location,50);
	cin.ignore(50,'\n');

	cout << "Enter the date: " << endl;
	cin.get(summer_list[i].date,20);
	cin.ignore(20,'\n');

	cout << "Did you attend last year? " << endl;
	cin.get(summer_list[i].attended_last_year,15);
	cin.ignore(15,'\n');

	cout << "Rating of desire to go from 1-10 (1 really want to go): " << endl;
	cin >> summer_list[i].desire_to_go;
	cin.ignore(100,'\n');

	++i; //counter for struct array
}




void activity_search(activity summer_list[],int i)
{
	char name[50];

	cout << "Enter the name of the activity: ";
	cin.get(name,50,'\n');
	cin.ignore(100,'\n');

	load_from_file(summer_list, i);

	for(int j=0; j<i; ++j)
	{
		if(strcmp(summer_list[j].name, name)==0)
		{
			cout << summer_list[j].name << endl;
			cout << summer_list[j].description << endl;
			cout << summer_list[j].location << endl;
			cout << summer_list[j].date << endl;
			cout << summer_list[j].attended_last_year << endl;
			cout << summer_list[j].desire_to_go << endl;
		}
		else
		{
			cout << "activity not in file. please type a valid name." << endl;
		}
		
		++j;
	}
	
}

void display_all(activity summer_list[], int i)
{
	for(int j=0; j<i; ++j)
	{
		cout << summer_list[j].name << endl;
		cout << summer_list[j].description << endl;
		cout << summer_list[j].location << endl;
		cout << summer_list[j].date << endl;
		cout << summer_list[j].attended_last_year << endl;
		cout << summer_list[j].desire_to_go << endl;
	}
}

