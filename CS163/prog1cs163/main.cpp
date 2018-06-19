#include "list.h"

day activity;

int main ()
{
	//char userinputday[SIZE];
	int response;
	//cout << "Please type which week file to open" << endl;
	//cin.get(userinputday,SIZE, '\n');
	//cin.ignore(100, '\n');
	do{
		cout << "Please type what you want to do. \nIf you want to add type 1.\nif you want to edit 2. \nPress 3 to copy.\n press 4 to display. \n press 5 to display the entire week. \n press 6 to remove a task." << endl;
		cin >> response;
		cin.ignore();
		switch (response)
		{
			case 1: cout << "add function" << endl;
				fivequestions();
				break;

			case 2: cout << "edit function" << endl;
				editfunction();
				break;

			case 3: cout << "copy function" << endl;
				copyfunction();
				break;

			case 4: cout << "display function" << endl;
				displayfunction();
				break;

			case 5: cout << "display week function: "<< endl;
				display_week_function();
				break;

			case 6: cout << "remove function" << endl;
				removefunction();
				break;

			default:
				cout << "No match found" << endl;
				break;
		}
	} 
	while(ask() == true);
	return 0;
}

void fivequestions()
{
	int i= 0;
	char task[SIZE];
	char timeofactivity[SIZE];
	char dayofactivity[SIZE];
	char duedate[SIZE];
	int newhours;


		cout << "type task?" << endl;
		cin.get(task, SIZE-1, '\n');
		cin.ignore(SIZE, '\n');

		cout << "type the amount of time it will take for the subject." << endl;
		cin.get(timeofactivity, SIZE -1, '\n');
		cin.ignore(SIZE, '\n');

		cout << "type day of activity?" << endl;
		cin.get(dayofactivity, SIZE-1, '\n');
		cin.ignore(SIZE, '\n');

		cout << "type due date? " << endl;
		cin.get(duedate, SIZE-1, '\n');
		cin.ignore(SIZE, '\n');

		cout << "type what time of day you plan on the subject in military time" << endl;
		cin >> newhours;
		cin.ignore();

		activity.add_activity(task, timeofactivity, dayofactivity, duedate, newhours);

}


void editfunction()
{
	char timetofind[SIZE];
	char daytofind[SIZE];
	char tasktoedit[SIZE];
	char userresponse[SIZE];
	cout << "what day do you want to edit?" << endl;
	cin.get(daytofind, SIZE-1, '\n');
	cin.ignore(100, '\n');

	cout << "what time do you want to edit?" << endl;
	cin.get(timetofind, SIZE - 1, '\n');
	cin.ignore(100, '\n');

	cout << "what task do you want to edit" << endl;
	cin.get(tasktoedit, SIZE - 1, '\n');
	cin.ignore(100, '\n');

    if(activity.edit_activity(timetofind, daytofind, tasktoedit) == 1)
    {
        cout << "Edit successful" << endl;
        main();
    }
    else
    {
        cout << "Edit unsuccessful" << endl;
        main();
    }


}


void copyfunction()
{
	char timetofind[SIZE];
	char daytofind[SIZE];
	char daytocopy[SIZE];
	
	cout << "what day do you want to copy?" << endl;
	cin.get(daytofind, SIZE - 1, '\n');
	cin.ignore(100, '\n');

	cout << "what time do you want to copy?" << endl;
	cin.get(timetofind, SIZE - 1, '\n');
	cin.ignore(100, '\n');

	cout << "where do you want to copy to?" << endl;
	cin.get(daytocopy, SIZE - 1, '\n');
	cin.ignore(100, '\n');

	if (activity.copy_activity(timetofind, daytofind, daytocopy) == 1)
	{
		cout << "Edit successful" << endl;
		main();
	}
	else
	{
		cout << "Edit unsuccessful" << endl;
		main();
	}
}


void displayfunction()
{
	char daytofind[SIZE];
	char tasktofind[SIZE];

	cout << "what day do you want to display?" << endl;
	cin.get(daytofind, SIZE - 1, '\n');
	cin.ignore(100, '\n');

	cout << "what time do you want to display?" << endl;
	cin.get(tasktofind, SIZE - 1, '\n');
	cin.ignore(100, '\n');

	if (activity.display_all_activity(tasktofind, daytofind) == 1)
	{
		cout << "Display successful" << endl;
		main();
	}
	else
	{
		cout << "Display unsuccessful" << endl;
		main();
	}
}

void removefunction()
{
	char timetofind[SIZE];
	char daytofind[SIZE];
	
	cout << "what day?" <<  endl;
	cin.get(daytofind, SIZE, '\n');
	cin.ignore(100, '\n');
	//search day userresponse

	cout << "what time?" << endl;
	cin.get(timetofind, SIZE, '\n');
	cin.ignore(100, '\n');

	//search time userresponse

	activity.remove_activity(timetofind, daytofind);
}


void display_week_function()
{
	cout << "This is the week: " << endl;
	activity.display_week();
	main();
}

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
	return false;
}
