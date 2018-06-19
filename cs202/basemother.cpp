//#include <iostream>
//#include <cctype>
//#include <cstring>
#include "basemother.h"
//#include "deriveddaughter.h"

using namespace std;

/**********************VERTEX CLASS ***********************/
vertex:: vertex()
{
	dronev = NULL;
	head = NULL;
}

vertex:: ~vertex()
{
	delete dronev;
	delete dronev;
}

/**********************NODE CLASS *************************/
node *& node :: gonext()//node * is the type if using the return type- do it in constructor
{
	//temp = next;// this is another way to do it

	
	return next;// initialize in constructor..
}



node :: node(): next(NULL), data(0), list(NULL)
{}


//node :: ~node(): next(NULL), data(0){}




int node :: setdata(int num)
{

	data = num;
	return 1;
}

/*
int node :: setnext(node * temp)
{
	next = temp;
	return 1;

}
*/
/*********************DRONE CLASS*************************/

drone:: drone(): length(0),  height(0), elevation(0), adistance(0), snap(NULL) // constructor
{}



//drone:: ~drone(): length(0), height(0), adistance(0), snap(NULL)//deconstructor



int drone :: distance(int user)
{
	adistance = user;
	return 1;
}



int drone :: size(int ulength, int uheight, int uelevation)
{
	length = ulength;
	height = uheight;
	elevation = uelevation;
	return 1; 
}



int drone :: photo(char aphoto[])
{
	snap = new char	[strlen(aphoto)+1];//initializes`

	const int yesno= 4;
	int len;
	int i = 0;
	char user[yesno];

	cin.get(user, yesno, '\n');
	for(i; i < len; ++i)
	{aphoto[i] = (toupper(aphoto[i]));}


	strcpy(snap, aphoto);	
	if(strcmp(snap,"YES")== 0)
		 {cout << "snapshot" << endl; }
	else
		{cout << "no shot" << endl;}
	return 1;
}



/**********/



const int SIZE = 100;
table :: table()
{
	list_size = SIZE;
	
} // constructor


//table :: ~table(){} // deconstructor



int insert_vertex(char current_vertex[], char to_attach[])
{

	return 1;
}



