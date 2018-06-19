#include "prog2fall.h"



info:: info()//constructor for the struct to allocate space.
{
group_name = NULL;
    num_ofpeople = 0;
    specialseat_requirement=NULL;
    coupons_emailandname = NULL;
}
node::node()//constructor for the struct to allocate space.
{
 data = NULL;

}

info::~info()//desconstructor to deallocate
{
	if(group_name)
	{delete [] group_name;}
	if(specialseat_requirement)
	{delete [] specialseat_requirement;}
	if(coupons_emailandname)
	{delete []coupons_emailandname;}
	

}

node::~node()//desconstructor to deallocate
{
	if (data)
	{delete [] data;}
}




/************************************************* CLASS MANAGER ******************************/
manager::manager()//constructor for the struct to allocate space.
{
    head = NULL; 
    MAX = 5;
    bottom = 0;
}

manager:: manager(int arraysize) //constructor will receive an argument to allocate space
{
	head = NULL;
	MAX = arraysize;//initializes max from the user
	bottom = 0;// bottom amount pointer

}

manager:: ~manager()//desconstructor to deallocate
{
	delete head;
}



int manager :: in_main(char user[], int user2, char user3[], char user4[])// receives input from the user and places it into a temp node for both que and stack function
{
	if (bottom == 5)
	{
		bottom = 0;
	}


	if(!head || bottom == 0)
	{
	    head = new node;
	    head -> data = new info[MAX];
    	}
    //info
    head  -> data[bottom].group_name = new char [strlen(user)+1];
    strcpy(head -> data[bottom].group_name ,user);

 //info2
     head -> data[bottom].num_ofpeople = user2;


    //info3
      head -> data[bottom].specialseat_requirement = new char [strlen(user3)+1];
    strcpy(head -> data[bottom].specialseat_requirement ,user3);

    //info4
       head -> data [bottom].coupons_emailandname = new char [strlen(user4)+1];
    strcpy(head -> data[bottom].coupons_emailandname ,user4);

	++bottom;
	    new_list(head);  //places the node in scope of the stack and que function.
    return 1;


   
}




int manager::new_list(node* temp)//sets the temp node in scope to classes stack and que
{
	node *current = temp;
	first_one.receive_pass1(current, bottom);
	second_one.receive_pass2(current);

    
    return 1;
}



int manager:: displayallm(int response)// manager display will receive response from the user and start the function of which to display
{
	if(response == 1){first_one.displayone();}//will display in stack
	else if(response ==2){second_one.display();}//will display in queue
    return 1;
}



int manager:: remove(int response)// asks which to remove
{
	
	if(response == 1){first_one.pop();} //will remove in stack

	else if(response ==2){second_one.display();}//will remove in queue
	return 1;
}



/**************************************************** CLASS ONE ********************************************/
stack:: stack()//allocates memory in default constructor
{
    
    head = NULL;
    new_node= NULL;
    max = 0;
    top_index = 0;
    
}





stack:: ~stack()//deallocates 
{
	delete head;
	delete new_node;
}



int stack:: receive_pass1(node * current, int bottom)//will recieve initialization to max and new_node.
{
	max = bottom;
	new_node = current;
	//head = new_node;
    //cout << "user" << head -> data -> group_name << endl;
	push(head, new_node);//pushes in stack
    return 1;

}



int stack :: push(node*& head, node *new_node)//adds a node
{
	node * temp = new_node;
	if(!head)
	{
	head = temp;
	head->next = NULL;
	}
	else
	{
	temp -> next = head;
	head = temp;
	}
	return 1;
}



int stack :: pop()//deletes a node from front
{
	node * temp = NULL;
	if(!head)
	{return 0;}
	peek();//checks to delete

	if(top_index== 0)
	{
	/*
	delete head->data[top_index].group_name;
	head -> data[top_index].num_ofpeople = 0;
	delete head -> data[top_index].specialseat_requirement;
	delete head -> data[top_index].coupons_emailandname;
	delete head;
	*/
	temp = head;
	head = head -> next;
	delete temp;
	top_index = max-1;
	}
	
	else
	{
	--top_index;
	/*
	temp = head;
	head = head -> next;
	delete temp ->data->group_name;
	temp  -> data ->num_ofpeople = 0;
	delete temp  -> data -> specialseat_requirement;
	delete temp  -> data -> coupons_emailandname;
	delete temp;
	*/
	}
	return 1;
}



int stack :: peek()//peeks at first
{
	if(!head) {return 0;}
	//cout << head -> data[0].
	else if(head)
	{
	cout << head -> data -> group_name <<endl;
	cout << head -> data -> num_ofpeople <<endl;
	cout << head -> data -> specialseat_requirement <<endl;
	cout << head -> data -> coupons_emailandname <<endl;
	}



	return 1;
}



int stack :: displayone()//displays all
{
    //node * head = head_actual;
    node *current = head;
    if(!head){ return 0;}

    while(current)
    {
    	cout << head -> data -> group_name <<endl;
	cout << head -> data -> num_ofpeople <<endl;
	cout << head -> data -> specialseat_requirement <<endl;
	cout << head -> data -> coupons_emailandname <<endl;
        current = current -> next;
    }
    return 1;
}


int stack:: file()
{
	ofstream ofile;
	int top = top_index;// sets top to top_index;

	if(!ofile)
	{return 0;}
	ofile.open("group_list.txt", ios::app);
	ofile << head  -> data[top].group_name<< "#" << head -> data[top].num_ofpeople << "#" << head -> data[top].specialseat_requirement << "#" << head -> data[top].coupons_emailandname << "#" << endl; 
	ofile.close();
	return 1;

}

/**************************************************** CLASS TWO ********************************************/
queue::queue()//constructor default allocates
{
    head = NULL;
    new_node = NULL;
}



queue::~queue()//destructor for deallocation
{
	delete head;
	delete new_node;
}


int queue :: receive_pass2( node *current)//receives to initialize in private
{
	head = current;
	enqueue(head, new_node);
    return 1;
}



int queue :: enqueue(node *& head, node * new_node)//adds to the queue
{
	node *temp = new_node;
	if(!head)
	{
	head = temp;
	head -> next = NULL;
	return 0;
	}


	while(head)
	{
		head -> next = temp;
		temp -> next = NULL;
		head = head -> next;
	}
	return 1;
}


int queue:: dequeue()//removes in the queue
{
	node *temp;
	if(!head){return 0;}
	peek();//peeks to see first
	temp = head;
	head = head -> next;
	delete temp;
	return 1;
}

		
int queue:: display()//displays node
{
    node *current = head;
    if(!head){return 0;}
    while(current != NULL)
    {
        cout << current ->data << "->";
        current = current -> next;
    }
    return 1;
}




int queue :: peek()//peeks at first
{
	if(!head) {return 0;}
	//cout << head -> data[0].
	else if(head)
	{
	cout << head -> data -> group_name <<endl;
	cout << head -> data -> num_ofpeople <<endl;
	cout << head -> data -> specialseat_requirement <<endl;
	cout << head -> data -> coupons_emailandname <<endl;
	}


	return 1;
}


/**************************************************** PROTOTYPE ********************************************/
int question(manager& m)//asks questions and sets them into an array and int
{
    do{

    char user[SIZE]; 
    int user2;
    char yesno[SIZE];
    char user3[SIZE];
    char user4[SIZE];
    
   cout << "please type in a group name" << endl;
   cin.get(user, SIZE, '\n');  
   cin.ignore(SIZE, '\n');

   cout << "please type in num of people" << endl;
   cin >> user2;  
   cin.ignore(SIZE, '\n');

cout << "does person need special seating? type y or n" << endl;
cin.get(yesno, SIZE, '\n');
cin.ignore(SIZE, '\n');

   if( strcmp(yesno,"y")==0)
   {   cout << "please type special seat requirement " << endl;
   cin.get(user3, SIZE, '\n');  
   cin.ignore(SIZE, '\n');
   }
/*
   else
   { strcpy(user3, 0);  return 0;}
*/

   cout << "please type email or name" << endl;
   cin.get(user4, SIZE, '\n');  
   cin.ignore(SIZE, '\n');





    m.in_main(user, user2, user3, user4);//places them into a manager class
    }while(ask() == true);

    return 1;
}



int displayall(manager &m)//displays all prompts
{
	char user[SIZE];
	int response;
    cout << "do you want to display all? type yes to continue" << endl;
    
    if(ask()== true)
    {
    	cout << "do you want to view stack? type y for yes or typ n for queue. Otherwise type any number to exit." << endl;
	cin.get(user,SIZE, '\n');
	cin.ignore(SIZE, '\n');
    	if(strcmp(user,"y")==0)
	{response = 1;}

	else if(strcmp(user, "n")==0)
	{response = 2;}
		if( response ==1 || response ==2)
		{ m.displayallm(response);}//diplays queue or stack

    }
    else
    { cout<< "sorry not a valid entry" << endl; return 0;}

    return 1;

}

int remove(manager &m)//removes after being prompted which action to take
{
	char user[SIZE];
	int response;
    cout << "do you want to remove group? type yes to continue" << endl;
    if(ask()== true)
    {
    	cout << "do you want to remove group in stack? type y for yes or typ n for queue. Otherwise, type any number to exit." << endl;
    	if(strcmp(user,"y")==0)
	{response = 1;} 

	else 
	{ response = 2;}

	m.remove(response);// removes in queue or stack
	}
    else if(ask()!=true)
    {return 0;}

    return 1;


	return 1;
}


bool ask()//asks for yes or no
{
    cout << "do you want to continue" << endl;
    char response[SIZE];
    cin.get(response,SIZE, '\n');
    cin.ignore(100, '\n');
    int len = strlen(response);
    for (int i = 0 ; i < len ; ++ i)
    {
        response[i] = toupper(response[i]);
    }
    if ((strcmp(response, "YES") == 0) || (strcmp(response, "Y") == 0))
    {return true;}
    return false;
}
