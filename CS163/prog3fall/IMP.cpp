#include "hash.h"
/*************************************************STRUCT INFO *******************************************/
//constructor
info:: info()
{
	topic_names= NULL;
	websites   = NULL;
	summarys   = NULL;
	reviews    = NULL;
	//ratings    = 0;
}

//destructor
info::~info()
{
	if(topic_names){delete []topic_names;}
	if(websites){ delete []websites;}
	if(summarys){ delete []summarys;}
	if(reviews) {delete  []reviews;}
	//if(ratings) {ratings= 0;}
}
int info::create(char topic_name[], char website[], char summary[], char review[], int rating)//add it to the struct object
{

	bool success = false;
	//if(topic_name&& website&& summary&& review&& rating){return success;}
	//{
	topic_names = new char [strlen(topic_name)+1];
	strcpy(topic_names, topic_name);
	//cout <<"topic names" <<  topic_names << endl;

	websites= new char [strlen(website)+1];
	strcpy(websites, website);

	summarys = new char [strlen(summary)+1];
	strcpy(summarys, summary);

	reviews = new char [strlen(review)+1];
	strcpy(reviews, review);

	ratings = rating;	
	success = true;
	//}
	return success;//returns false if there isnt anything in the character arrays
}


int info::copy(info &to_add)//copies it to the object if it exists
{
	bool success = false;
	if(topic_names){delete [] topic_names;}
	if(websites){delete [] websites;}
	if(summarys){delete [] summarys;}
	if(reviews){delete [] reviews;}

	//success will return false if any is null.

	if(to_add.topic_names&& to_add.websites&& to_add.summarys&& to_add.reviews && to_add.ratings)// if it does exist add them to the struct members and return success
	{
		topic_names = new char [strlen(to_add.topic_names)+1];
		strcpy(topic_names, to_add.topic_names);

		websites= new char [strlen(to_add.websites)+1];
		strcpy(websites, to_add.websites);

		summarys = new char [strlen(to_add.summarys)+1];
		strcpy(summarys, to_add.summarys);

		reviews = new char [strlen(to_add.reviews)+1];
		strcpy(reviews, to_add.reviews);
		ratings = to_add.ratings;

		success = true;
	}
	return success;


}

bool info ::checkingf(char user[], info& checkn)//checks to find
{
	bool success = false;
	if(!topic_names ||!user){return false;}
	if(!strcmp(topic_names, user)==0){return false;}
	if(checkn.topic_names && checkn.websites&& checkn.summarys && checkn.reviews && checkn.ratings)
	{
		delete [] checkn.topic_names;
		delete [] checkn.websites;
		delete [] checkn.summarys;
		delete [] checkn.reviews;
		//checkn.ratings =0;
	}
	if(topic_names && websites&& summarys && reviews && ratings)
	{
		checkn.topic_names = new char[strlen(topic_names) +1];
		strcpy(checkn.topic_names,topic_names);

		checkn.websites = new char [strlen(websites)+1];
		strcpy(checkn.websites, websites);

		checkn.summarys = new char[strlen(summarys)+1];
		strcpy(checkn.summarys, summarys);

		checkn.reviews = new char[strlen(reviews)+1];
		strcpy(checkn.reviews, reviews);

		checkn.ratings = ratings;
		success = true;
	}
	return success;// returns true if they do exist

}



/*************************************************STRUCT NODE *******************************************/

//constructor
/*
   node:: node()
   {
   data = NULL;
   }
   node::~node()
   {
   if(data){delete data;}
   }
 */

/*************************************************CLASS HASH *******************************************/
//constructor
hash::hash()
{
	hash_info = new node *[SIZE];
	MAX_A= SIZE;
	for(int i = 0; i < MAX_A; ++i)
	{hash_info[i]= NULL;}

}


//destructor
hash::~hash()
{
	if(hash_info){delete hash_info;}
	if(MAX_A){MAX_A = 0;}
}


//finds ascii value and inputs it into the table
int hash :: hash_function(char topic_name[])
{
	int count;
	int topicname_len= strlen(topic_name);
	for(int i=0; i< topicname_len; ++i)
	{
		count = count +topic_name[i];
	}
	return count%MAX_A;
}




// inserts a into the hash table
int hash::insert(char topic_name[], info& to_add)
{
	node* temp = new node;
	int index = hash_function(topic_name);
	cout << index << endl << endl; 
	if(!temp -> data.copy(to_add))
	{
		delete temp;
		return 0;

	}
	temp -> next = hash_info[index];
	hash_info[index] = temp;

	return 1;

}



//checks to find if it exists
int hash:: retrieve(char user[], info& checkn)
{

	bool success = false;
	int index = hash_function(user);
	node *current = hash_info[index];
	while(current && !success)
	{
		success = current -> data.checkingf(user, checkn);

		current = current-> next;

	}
	return success;
}



//displays 
int hash::display(char user[])
{
	if(*hash_info==NULL){return 0;}
	int index = hash_function(user);
	if(hash_info[index])
	{
		cout << "////////////////////////////////...." << endl;
		cout << "place where located" << index << endl;
		cout << "////////////////////////////////...." << endl;
		cout << hash_info[index] -> data.topic_names<< endl;
		cout << hash_info[index] -> data.websites<< endl;
		cout << hash_info[index] -> data.summarys<< endl;
		cout << hash_info[index] -> data.ratings<< endl;
		cout << hash_info[index] -> data.reviews << endl;
		cout << "////////////////////////////////...." << endl;
		//cout << "number of websites stored" << number << endl;
		cout << "////////////////////////////////...." << endl;
	}
	return 1;

}



//displays all
int hash::displayall()
{
	if(*hash_info==NULL){return 0;}
	int number;
	for(int index = 0; index < MAX_A ; ++index)
	{
		number = count(index);
		cout << "///////////////////////////////////" << endl;
		cout << "index" << index << endl;
		cout << "///////////////////////////////////" << endl;
		cout << hash_info[index] -> data.topic_names<< endl;
		cout << hash_info[index] -> data.websites<< endl;
		cout << hash_info[index] -> data.summarys<< endl;
		cout << hash_info[index] -> data.ratings<< endl;
		cout << hash_info[index] -> data.reviews << endl;
		cout << "///////////////////////////////////" << endl;
		cout << "number of items" << number << endl;
		cout << "///////////////////////////////////" << endl;


	}
	return 1;
}



//counts how many
int hash:: count(int index)
{
	if(*hash_info==NULL){return 0;}
	int counts = 0;
	if(hash_info[index] -> data.topic_names = NULL)
		return counts;

	else
	{
		++counts;
		node*current = hash_info[index];
		while(current -> next != NULL)
		{
			++counts;
			current = current -> next;
		}
	}
	return counts;
}




//edits ratings and reviows
int hash::edit(char user[], char newreviews[], int newratings)
{
	if(*hash_info==NULL){return 0;}
	int i = hash_function(user);
	node *current = hash_info[i];


	while(current != 0)
	{
		if(strcmp(current->data.topic_names, user)==0)
		{
				
			if ( current->data.reviews) delete current->data.reviews;

			current->data.reviews = new char[strlen(newreviews) +1];
			strcpy(current->data.reviews, newreviews);
			cout << current->data.reviews << endl;
			current->data.ratings= newratings;
			
			
		}
		current = current -> next;
	}
	return 1;
}




int hash :: remove()//removes 1 star ratings.
{

	int i = 0;
			node * current = hash_info[i];
			node * previous = new node;
	if(!hash_info[i]){return 0;}
	for(i; i < MAX_A; ++i)
	{
		if(hash_info[i]-> data.ratings == 1)
		{
			if(current-> next == NULL)
			{
				delete current;
				current = NULL;
			}
			else if(current ->next != NULL)
			{
				previous = current;
				current = current -> next;
				delete previous;
				previous = NULL;
			}
			else if(current -> next -> next!=NULL)
			{
				previous = current;
				previous -> next= current -> next -> next;
				delete current;
				current = current -> next;
				current = previous;
			}
		}
			previous = current;
			current = current -> next;
	}
return 1;
}


/*************************************************PROTOTYPES *******************************************/

//asks the user what to do
int questions(info& to_add, info& checkn, hash &hashyfunc)
{
	char topic_name[SIZE];
	char website[SIZE];
	char summary[SIZE];
	char review[SIZE];
	int rating;
	char user[SIZE];
	int len;

	   do{
	   cout << "topic name please" << endl;
	   cin.get(topic_name, SIZE, '\n');
	   cin.ignore(SIZE, '\n');

	   cout << "website name please" << endl;
	   cin.get(website, SIZE, '\n');
	   cin.ignore(SIZE, '\n');

	   cout << "summary please" << endl;
	   cin.get(summary, SIZE, '\n');
	   cin.ignore(SIZE, '\n');

	   cout << "review information please" << endl;
	   cin.get(review, SIZE, '\n');

		cout << "rating please" << endl;
	   cin >>rating;
	   cin.ignore(SIZE, '\n');


	   strcpy(user, topic_name);
	   len = strlen(user);
	   if(len == 0){cout << "nothing program will exit. when re-entering the program, type a valid response"<< endl; return 0;}

	   strcpy(user, website);
	   len = strlen(user);
	   if(len == 0){cout << "nothing program will exit. when re-entering the program, type a valid response"<< endl; return 0;}

	   strcpy(user,summary);
	   len = strlen(user);
	   if(len == 0){cout << "nothing program will exit. when re-entering the program, type a valid response"<< endl; return 0;}

	   strcpy(user,review);
	   len = strlen(user);
	   if(len == 0){cout << "nothing program will exit. when re-entering the program, type a valid response"<< endl; return 0;}

	   if(rating == 0){cout << "nothing program will exit. when re-entering the program, type a valid response"<< endl; return 0;}






         ofstream ofile;

         if(!ofile)
         {return 0;}
         ofile.open("websites.txt", ios::app);
         ofile << topic_name << "#" << website << "#" << summary << "#" << review << "#" << rating <<  endl;
         ofile.close();
	 //ofile.clear();

	ifstream ifile;
	if(!ifile){return 0;}

         ifstream file_in;
         char buffer[200];
         file_in.open("website.txt"); //change later with strcat function
         if(!file_in)
         {
                 return 0;
         }
         else
         {
                 if(file_in)
                 {

                         while(file_in && !file_in.eof() )
                         {
                                 file_in.get(topic_name, SIZE, '#');
                                 file_in.ignore(SIZE, '#');

                                 file_in.get(website, SIZE, '#');
                                 file_in.ignore(SIZE, '#');

                                 file_in.get(summary, SIZE, '#');
                                 file_in.ignore(SIZE, '#');

                                 file_in.get(review, SIZE, '#');
                                 file_in.ignore(SIZE, '#');

                                 file_in >> rating;
                                 file_in.ignore(SIZE, '\n');
                         }
                         file_in.clear();
                         file_in.close();
                         return 1;
                 }
         }
 


	
	//pass to the member function to make key
	to_add.create(topic_name, website, summary, review, rating);
	hashyfunc.insert(topic_name, to_add);

	   cout << "do you want to continue adding? type y or n" << endl;
	   cin.get(user, SIZE, '\n');
	   cin.ignore(SIZE, '\n');
	   }while(strcmp(user, "y")==0);

	   cout << "do you want to look for a website ?type y or n" << endl;
	   cin.get(user, SIZE, '\n');
	   cin.ignore(SIZE, '\n');

	   if(strcmp(user, "y")==0)
	   {
	ask_retrieve(hashyfunc, checkn);
	}
	return 1;
}

int ask_retrieve(hash& hashyfunc, info& checkn)
{
	char user[16]="data structures";
	do
	{

		cout << "type what to look for" << endl;
		//cin.get(user, SIZE, '\n');
		//cin.ignore(SIZE, '\n');

		hashyfunc.retrieve(user, checkn);

		//display
		cout << "this is whats found" << endl;
		hashyfunc.display(user);

		cout << "do you want to continue searching? type y or n" << endl;
		cin.get(user, SIZE, '\n');
		cin.ignore(SIZE, '\n');

	}while(strcmp(user,"y")==0);
	return 1;



}



int edit(hash& hashyfunc)
{	
	char user[16]="data structures";
	char newreviews[] = "whatup!!!!!!!!!!!!!";
	int newratings = 99999;
	do
	{

		cout << "type what to look for" << endl;
		//cin.get(user, SIZE, '\n');
		//cin.ignore(SIZE, '\n');
		cout << "type new review" << endl;
		//cin.get(user, SIZE, '\n');
		//cin.ignore(SIZE, '\n');
		cout << "type new rating" << endl;
		//cin.get(user, SIZE, '\n');
		//cin.ignore(SIZE, '\n');


		//hashyfunc.retrieve(user, checkn);

		//display
		cout << "this is whats found" << endl;
		hashyfunc.display(user);

		//edit adt
		hashyfunc.edit(user, newreviews, newratings);
		cout << "new edited info" << endl;

		//display
		hashyfunc.display(user);
		cout << "do you want to edit? y or n" << endl;
		cin.get(user, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		//edit adt
	}while(strcmp(user,"y")==0);
	return 1;
}



int remove(hash& hashyfunc)
{
	
	hashyfunc.remove();
	return 1;
}


int display(hash& hashyfunc)
{
	hashyfunc.displayall(); 
	return 1;
}





