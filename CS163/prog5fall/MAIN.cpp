#include "GRAPH.h"


int main()
{
	table operations;
	 info to_add;
	char user[SIZE];
	char task[SIZE];
	char second_task[SIZE];
	char to_look[SIZE];
	int len;

	   do{
	   cout << "task name please" << endl;
	   cin.get(task, SIZE, '\n');
	   cin.ignore(SIZE, '\n');


	   len = strlen(task);
	   if(len == 0){cout << "nothing program will exit. when re-entering the program, type a valid response"<< endl; return 0;}


	//pass to the member function to make key
	to_add.create(task);
	operations.insert_vertex(to_add);

	   cout << "do you want to continue adding? type y or n" << endl;
	   cin.get(user, SIZE, '\n');
	   cin.ignore(SIZE, '\n');
	   }while(strcmp(user, "y")==0);
//connect the tasks section
	do{
		cout << "enter a tasks that will follows to the other task." << endl;
		cin.get(task, 100); cin.ignore(100, '\n');
		cin.get(second_task, 100); cin.ignore(100, '\n');
		operations.insert_edge(task,second_task);
		operations.insert_edge(second_task, task);
	
	cout << "do you want to continue adding? type y or n" << endl;
	   cin.get(user, SIZE, '\n');
	   cin.ignore(SIZE, '\n');
	}while(strcmp(user, "y")==0);

	   cout << "do you want to display? type y or n" << endl;
	   cin.get(user, SIZE, '\n');
	   cin.ignore(SIZE, '\n');

	   if(strcmp(user, "y")==0)
	   	{
			operations.display_adjacent(to_look);
		}
	/*
	 */

	return 1;
}
