#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//functions return a value


bool ask();// returns true or false
//int ask();


int main()
{

	do{
	int num;
	//prompt her
	cout << "type someting" << endl;
	cin>> num;

	}while(ask()==true);

	//average it here
return 0;
}


bool ask()
{
	int i = 0;
	char response[100];
	cout << "do you want to continue?" << endl;
	cin.get(response, 100,'\n');//resizes array with null at end
	
	int len = strlen(response);//counts size not including null at end
	for(i; i< len; ++i)
	{
		response[i] = toupper(response[i]);
			
	}
	if((strcmp(response,"YES") ==0)){return true;}
	else if((strcmp(response,"NO")==0)){return false;} 
	return false;//kinda like else. this covers if user types asshole arry: "fuck you"
}
