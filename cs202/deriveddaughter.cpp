#include <iostream>
#include <cstring>
#include <cctype>
#include "basemother.h"
//#include "deriveddaughter.h"


using namespace std;

/*******************toy***************/
photo::photo(): udistance(0), uheight(0), ulength(0), uphoto(0), usnap(NULL)
{}
//photo::~photo(){}



int photo :: distance(int user)
{
	udistance = user;
	distance(udistance);
	return 1;
}


int photo :: size(int user1, int user2, int user3)
{
	uheight = user1;
	ulength = user2;
	uelevation = user3;
	size(uheight, ulength, uelevation);

	return 1;
}



int photo :: photodrone(char aphoto[])
{
	usnap = new char [strlen(aphoto)+1];//initializes`
	strcpy(usnap, aphoto);
	photo(usnap);

	return 1;
}





/*******************racing***************/
racing :: racing(): udistance(0), uheight(0), ulength(0), uelevation(0) 
{}



int racing :: distance(int user)
{
	udistance = user;
	distance(udistance);
	return 1;
}


int racing:: size(int user1, int user2, int user3)
{
	uheight = user1;
	ulength = user2;
	uelevation = user3;
	size(uheight, ulength, uelevation);

	return 1;
}





/*******************photo***************/

selfie::selfie(): udistance(0), uheight(0), ulength(0), uphoto(0), usnap(NULL)
{}
//photo::~photo(){}



int selfie :: distance(int user)
{
	udistance = user;
	distance(udistance);
	return 1;
}


int selfie :: size(int user1, int user2, int user3)
{
	uheight = user1;
	ulength = user2;
	uelevation = user3;
	size(uheight, ulength, uelevation);

	return 1;
}



int selfie :: photodrone(char aphoto[])
{
	usnap = new char [strlen(aphoto)+1];//initializes`
	strcpy(usnap, aphoto);
	photo(usnap);

	return 1;
}




