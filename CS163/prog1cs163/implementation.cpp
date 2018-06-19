/#include "list.h"
//constructors 
/*
day:: day()
{

	userresponse = new char[SIZE];
	head = NULL;
}
*/
day:: day(/*char *userinputday*/)
{
	head = NULL;
	userresponse = new char[SIZE];
	filename = new char[strlen(/*userinputday*/"week")];//could not use unserinput to cread a txt file just yet...
	strcpy(filename, "week");
	strcat(filename, ".txt");
}

day ::~day()
{
node *temp;
	while (head)
	{
	temp = head;
	delete head;
	head = temp;
	}
}



int day:: searchtask(char *timetofind, char* daytofind, node*&headtemp)
{

	if (!headtemp)
	{
		if(ifile() == 0)
		{
			return 0;
		}
		else
		{
		cout << "sorry, no list." << endl;
		}
	}


	if(strcmp(headtemp->weekly.timeofactivity, timetofind)==0 && strcmp(headtemp -> weekly.dayofactivity, daytofind)==0)
	{
		if(strcmp(userresponse, headtemp->weekly.task)==0)
		{ 
			return 1;
		}
		else
		{
				headtemp = headtemp -> next;
				if(searchtask(timetofind, daytofind, headtemp)== 1)
				{
					return 1;

				}
				else
				return 0;
		}
	}
	if(headtemp -> next == NULL)
	{
		return 0;

	}
}




int day :: add_activity(char *newtask, char * newtimeofactivity, char* newdayofactivity, char *newduedate, int newhours)
{

	node *temp= new node;
	temp->weekly.task = new char[SIZE];
	temp->weekly.timeofactivity = new char[SIZE];
	temp->weekly.dayofactivity = new char[SIZE];
	temp->weekly.duedate = new char[SIZE];

	strcpy(temp->weekly.task, newtask);
	strcpy(temp->weekly.timeofactivity, newtimeofactivity);
	strcpy(temp->weekly.dayofactivity, newdayofactivity);
	strcpy(temp->weekly.duedate, newduedate);
	temp->weekly.hours = newhours;
	if(ofile(temp)==1)
	{return 1;}
	else 
	return 0;
}




int day :: ofile(node *&temp)
{
	node *  current = temp;
	ofstream file_out;
	file_out.open(filename, ios::app);//look into
	if(!file_out)
	{
		return 0;
	}
	else
	{
		file_out << current->weekly.task << ":" << current->weekly.timeofactivity << ":" 
			<< current -> weekly.dayofactivity << ":" << current->weekly.duedate << ":" << current -> weekly.hours << endl;
		current = current -> next;

	}
	file_out.clear();
	file_out.close();
	return 1;
}




int day :: ifile()
{ //used for display functions

	node * current = NULL;
	ifstream file_in;
	char buffer[200];
	file_in.open(filename); //change later with strcat function
	if(!file_in)
	{
		return 0;
	}
	else
	{
		if(file_in)
		{	
			
			while(file_in && !file_in.eof() && current)
			{
				node * current = new node;
				file_in.get(buffer, SIZE, ':');
				current -> weekly.task = new char[strlen(buffer+1)];
				strcpy(current -> weekly.task, buffer); 
				file_in.ignore(SIZE, ':');
				
				file_in.get(buffer, SIZE, ':');
				current -> weekly.timeofactivity = new char[strlen(buffer+1)];
				strcpy(current -> weekly.timeofactivity, buffer); 
				file_in.ignore(SIZE, ':');

				file_in.get(buffer, SIZE, ':');
				current -> weekly.dayofactivity = new char[strlen(buffer+1)];
				strcpy(current -> weekly.dayofactivity, buffer); 
				file_in.ignore(SIZE, ':');
			
				file_in.get(buffer, SIZE, ':');
				current -> weekly.duedate = new char[strlen(buffer+1)];
				strcpy(current -> weekly.duedate, buffer); 
				file_in.ignore(SIZE, ':');

				file_in >> current -> weekly.hours;
				file_in.ignore(SIZE, '\n');
				traversefunction(current);
			}
			file_in.clear();
			file_in.close();
			return 1;
		}
	}
}




int day:: traversefunction(node*&temp)// search by time.......
{
	node*current = temp;
	if(head == NULL)
	{head = temp;
	head -> next = NULL;
	return 0;}

	while (current -> next)
	{
		current = current -> next;

	}
	current -> next = temp;
	current = current -> next;
	current->next = NULL;
	return 1;
}








int day ::edit_activity(char* timetofind, char *daytofind, char *tasktoedit)
{

	node *current = head;

	if(!head)
	{
		if(ifile() == 0)
		{
			return 0;
		}
	}

	if(searchtask(timetofind, daytofind, current)==1)
	{
		delete [] current -> weekly.task;
		strcpy(current -> weekly.task, tasktoedit);
		return 1;
	}
	else
	{
		return 0;
	}
}



int day ::copy_activity(char *timetofind, char* daytofind, char *daytocopy)
{
	node* current = head;
	if(!head)
	{
		if(ifile() == 0)
		{
			return 0;
		}
	}
	if(searchtask(timetofind, daytofind, current)==1)
	{
		if(add_activity(current -> weekly.task, current -> weekly.timeofactivity, daytofind, current -> weekly.duedate, current -> weekly.hours)==1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
	

}



int day :: remove_activity(char *timetofind, char *daytofind)
{
	node *current = head;
	if(!current)
	{
		if(ifile() == 0)
		{
		return 0;
		}
	}
	if(searchtask(timetofind, daytofind, current)==1)
	{
		delete [] current -> weekly.task;
		delete [] current -> weekly.dayofactivity;
		delete [] current -> weekly.duedate;
		delete [] current;
		return 1;
	}
	else
	{
		return 1;
	}

}


int day:: display_all_activity(char * tasktofind, char * daytofind)
{
	node *current = head;

	if (!head)
	{
		if(ifile() == 0)
		{
			return 0;
		}
	}
	while(current)
	{
		if(strcmp(current->weekly.task, tasktofind)== 0 && strcmp(current -> weekly.dayofactivity, daytofind) == 0)
		{

			cout << "Task: " << current->weekly.task << "time of activity: " << current-> weekly.timeofactivity << "day of activity" << current->weekly.dayofactivity << "due date: " << current->weekly.duedate<< "hours it will take: " << current->weekly.hours << endl;
		}
		current = current -> next;
	}
}


int day :: display_week()
{
	node *current = head;
	if(!head)
	{
		if(ifile() == 0)
		{
			return 0;
		}
	}
	while(current)
	{
		cout << "Task: " << current->weekly.task << "time of activity: " << current-> weekly.timeofactivity << "day of activity" << current->weekly.dayofactivity << "due date: " << current->weekly.duedate<< "hours it will take: " << current->weekly.hours << endl;
		current = current -> next;
	}

	return 1;
}
