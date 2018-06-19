#include "BST.h"

/*************************************************PROTOTYPES *******************************************/

//asks the user what to do
int questions(node& to_add, node& checkn, bst &bstfunc)
{
	char keyword[SIZE];
	char topic_name[SIZE];
	char website[SIZE];
	char summary[SIZE];
	char review[SIZE];
	int rating;
	char user[SIZE];
	int len;

	
	   do{
	   cout << "keyword please" << endl;
	   cin.get(keyword, SIZE, '\n');
	   cin.ignore(SIZE, '\n');

	   cout << "topic name please" << endl;
	   cin.get(topic_name, SIZE, '\n');
	   cin.ignore(SIZE, '\n');

	   cout << "website name please" << endl;
	   cin.get(website, SIZE, '\n');
	   cin.ignore(SIZE, '\n');

	   cout << "summary please" << endl;
	   cin.get(summary, SIZE, '\n');
	   cin.ignore(SIZE, '\n');

	   cout << "review rootrmation please" << endl;
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


	//pass to the member function to make key
	to_add.create(keyword,topic_name, website, summary, review, rating);
	bstfunc.insert(keyword, to_add);
	   cout << "do you want to continue adding? type y or n" << endl;
	   cin.get(user, SIZE, '\n');
	   cin.ignore(SIZE, '\n');
	   }while(strcmp(user, "y")==0);

	   cout << "do you want to look for all websites ?type y or n" << endl;
	   cin.get(user, SIZE, '\n');
	   cin.ignore(SIZE, '\n');

	   if(strcmp(user, "y")==0)
	   {
	ask_retrieve(bstfunc, checkn);
		}
	return 1;
}

int ask_retrieve(bst& bstfunc, node& checkn)//also asks user to display and remove
{
	char keyword[]="raulz";
	char user[2];
	char wordremove[] = "raul";
	do
	{

		cout << "type what a keyword for retrieve" << endl;
		cin.get(user, SIZE, '\n');
		cin.ignore(SIZE, '\n');

		bstfunc.retrieve(keyword, checkn);

		//display
		cout << "this is whats found" << endl;
		bstfunc.display();

		cout << "do you want to continue searching? type y or n" << endl;
		cin.get(user, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		

		
			
	}while(strcmp(user,"y")==0);

	cout <<" do you want to remove a website or websites? y or n" << endl;
		cin.get(user, SIZE, '\n');
		cin.ignore(SIZE, '\n');
		if(strcmp(user, "y")==0)
		{
		//remove function and asks user to remove
		cout <<" do you want to delete a website? y or n"<<endl;
		cin.get(user, SIZE, '\n');
		cin.ignore(SIZE, '\n');
			if(strcmp(user, "y")==0)
			{
				cout <<"please type a keyword to delete"<< endl;
				cin.get(keyword, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				bstfunc.remove(keyword);
			}
			else
			{
				cout <<"please type a topic to delete"<< endl;
				cin.get(wordremove, SIZE, '\n');
				cin.ignore(SIZE, '\n');
				bstfunc.display();
				bstfunc.removeall(wordremove);
			}

		}
	return 1;



}






