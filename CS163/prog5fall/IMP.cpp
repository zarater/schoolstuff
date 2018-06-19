#include "GRAPH.h"

/*************************************************STRUCT INFO *******************************************/

info::info()
{tasks = NULL;}

info:: ~info()
{
	if(tasks) {delete  []tasks;}
}



int info:: create(char task[])
{
	tasks = new char[strlen(task)];
	strcpy(tasks, task);
	return 1;
}



int info:: copy(info& to_add)
{
	if(to_add.tasks ==NULL){return 0;}
	
	to_add.tasks = new char[strlen(tasks)];
	strcpy(to_add.tasks, tasks);
	return 1;
}



int info::compare(char key_value[])
{
	if (strcmp(key_value, tasks)!= 0)
	{return 0;}
	return 1;
}


/*************************************************STRUCT  VERTEX*******************************************/
//constructor
//destructor



/*************************************************CLASS TABLE *******************************************/

//constructor
table::table()
{
	list_size = SIZE;
	for(int i = 0; i < SIZE; ++i)
	{
		adjacency_list[i].head = NULL;
		adjacency_list[i].a_info = NULL;

	}

}



//destructor
table::~table()
{
	if(adjacency_list->head){delete adjacency_list->head;}
	if(list_size!= 0){list_size = 0;}
}



        



//Store the vertex at this location.
int table::insert_vertex(info & to_add)
{
	for (int i=0; i< list_size; ++i)
        {
	if(adjacency_list[i].a_info== NULL)
		{
		adjacency_list[i].a_info = new info;
		adjacency_list[i].a_info-> copy(to_add);
		}
        }
	return 1;
}



//Attach an edge to a vertex
int table::insert_edge(char  current_vertex[], char to_attach[])
{
       //Attach this vertices edge to the specified vertex
       int i = find_location(current_vertex);
       int j = find_location(to_attach);
       node*temp = new node;
       temp -> adjacent =&adjacency_list[j];
       temp -> next = adjacency_list[i].head;
       adjacency_list[j].head = temp;

       //also,
       temp = new node;
       temp -> adjacent =&adjacency_list[i];
       temp -> next = adjacency_list[j].head;
       adjacency_list[j].head = temp;
	return 1;
}



//Display all vertices adjacent to the one specified
int table::display_adjacent(char key_value[])
{
    int i;
 while(i < list_size)
       {
            if(adjacency_list[i].a_info== NULL){return 0;}
            if(adjacency_list[i].a_info->compare(key_value))
            {
                node *current = adjacency_list[i].head;
                while(current)
                    if(current -> adjacent)
                        //current -> adjacent -> entry -> display();
			cout << current -> adjacent -> a_info -> tasks<< endl; 
                current = current -> next;
             }
       }
        return 1;
}



//Find a location in the graph
int table::find_location(char key_value[])
{
      //return the location of this particular key value 
       int i = 0;
        while(i < list_size)
       {
            if(adjacency_list[i].a_info== NULL){return 0;}
            if(adjacency_list[i].a_info->compare(key_value)){return i;}
            
       }
}



int table:: displayall()
{
return 1;

}







