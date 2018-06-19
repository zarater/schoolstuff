#include <iostream>
#include <cstring>
#include <cctype>

#include "basemother.h"
#include "deriveddaughter.h"
#include "graph.h"

using namespace std;

bool ask();
int main()
{
	photo photodrone;
	racing racingdrone;
	selfie selfiedrone;//these three will invoke the parent class.
	
	table graph;
	graph.insert_vertex(photo &photodrone, racing &racingdrone, selfie &selfiedrone);

	int motherdronetest();
	


	//node obj3;
	//obj3.setdata(num);//head -> data//not need now
	//obj3.setnext(temp);//head -> next//not needed now because i changed getnext()
	return 0;

}




bool ask()
{
	const int yesno= 4;
	int len;
	int i = 0;
	char user[yesno];

	cout <<"do you want to continue?" << endl;

	cin.get(user, yesno, '\n');
	for(i; i < len; ++i)
	{user[i] = (toupper(user[i]));}
	if((strcmp(user, "YES") ==0 ) || (strcmp(user, "Y") == 0)){return true;}
	else if((strcmp(user, "NO") ==0) || (strcmp(user, "N") == 0))
	{cout << "Thank you." << endl; return false;}
	return false;
}



int motherdronetest()
{
	photo adrone;
	char aphoto[100];
	cout << "do you want to take a photo?"<< endl;
	cin.get(aphoto, 100, '\n');
	adrone.photodrone(aphoto);
}
