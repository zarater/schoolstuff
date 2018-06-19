#include "prog2fall.h"



int main()
{
	int arraysize;//allocates for the constructor
   manager m(arraysize);//manager class that will make in scope other functions
   // constructor for stack


	cout << "what size for the LLL of array" << endl;
	cin >> arraysize;// sets the max size in constructor of stack
	cin.ignore(SIZE, '\n');


   question(m);// asks the questions to take action
   displayall(m);// will ask to display 
   remove(m);//will ask to remove
   return 0;
}
