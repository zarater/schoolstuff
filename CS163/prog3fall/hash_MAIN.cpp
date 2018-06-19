:include "hash.h"


int main()
{
	hash hashyfunc;
	info to_add, checkn;
	//cout << topic_name<< website << summary << review << rating << endl;

	//in charge of prompting user
	int user;
	cout << "please type an action" << endl;
	cout << "add a website type 1, edit a website type 2, remove a website 3, diplay all 4"<<endl;
	cin >> user;
	cin.ignore(100, '\n');
	do{
		if(user==1)
		{questions(to_add, checkn, hashyfunc);}
		if(user ==2)
		{edit(hashyfunc);}
		if(user==3)
		{remove(hashyfunc);}
		if(user == 4)
		{display(hashyfunc);}
		else
		{user = 0;}


		cout << "please type an action" << endl;
		cout << "add a website type 1, edit a website type 2, remove a website 3, diplay all 4"<<endl;
		cin >> user;
		cin.ignore(100, '\n');
	}while(user !=0);
	/*
	 */

	return 1;
}
