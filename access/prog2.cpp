/*
Name: Raul Zarate
Date: 5/3/2017
Class Number:CS162
Program: #2

Paragraph:
What I want from this program, as I write code, is to return to the user, "shorthand," of what user has typed. the shorthand from the user should be:
1. “and” Replace with: ‘+’
2. “the” Replace with: “t-”
3. Any word ending in “ing” Replace: end the word in “!g” instead.
4. Any word with “ish” Replace with: “!h”.
5. If a word is passed tense with “ed” at the end Replace with a space ‘t’.
6. if a word is for replace with /.
7. if a word is was, replace it with =.

After I have created English text to shorthand using these steps, I then want to create a second function to read shorthand from the user and turn it into english text.
For example, if the user wanted to type "+" and after being asked if user wanted the shorthand, then user will receive the sentence with a replacement text of, "and."
The steps I will follow are on the algorithm that I have turned in and further explain my method of pursuance to program assignment 2. I will create two functions that loop for each scenerio. 
each loop will convert text to the either shorthand or english. They will then continue adding to an array and move on to the next part of the sentence. after the arrays have been filled with text,
they will display results.

*/

#include <iostream>
#include <string.h>
#include <cctype>
#include <cstring>
using namespace std;


//Function Declaration
bool again();// Ask to continue.



void translatetoenglish(int counter1, int counter2, int len, int length, char new_word[], char userresponse[], char shorthandtotextuserresponse[], const int size);
//this turns text with shorthanded text to English text. Does not output but will have the solution for conversion. the input will be in the declared variable in main.



void translatetoshorthand(int counter1, int counter2, char sentence[], char newarray[], int length, int len, char userresponse[], const int size);
//this turns English text to shorthanded text. Does not output but will have the solution for conversion. the input will be in the declared variable in main.



int main()
{
	//declare variables
	const int size = 200;//has a consistence senctence size
	int counter1;// its a counter that will get initialized inside a loop
	int counter2 = 0;//a second counter for a loop to increase

	int len=0;//the length of words used with strlen
	int	length=0;//length of words used for strlen

	char userresponseyesno[size];//recieves a yes or no from the user. 
	char userresponse[size];//receives response from the user.

	char shorthandtotextuserresponse[size];//response from user with shorthanded text.
	char new_word[size];//an array for minipulation.
	char sentence[size];//receives a sentence from the user.
	char newarray[size];//an array for minipulation

	//ask to continue
	do
	{


		//ask user style of text.
		cout << "short hand text:\n 1.and Replace with: + \n 2.  “the” Replace with : t - \n 3. Any word ending in ing Replace : end the word in !g instead \n4. Any word with ish Replace with : !h \n 5. If a word is passed tense with ed at the end Replace with a space t \n 6. if a word is for replace with = \n 7. if a word is was, replace it with / ." << endl;
		cout << "do you want to translate to shorthand" << endl;
		cin.get(userresponseyesno, size - 1, '\n');
		cin.ignore(size, '\n');

		//cap userresponse to compare
		len = strlen(userresponseyesno);
		for (counter1 = 0; counter1 < len; ++counter1)// loops through user response
		{
			userresponseyesno[counter1] = toupper(userresponseyesno[counter1]);
		}

		if ((strcmp(userresponseyesno, "Y") == 0) || (strcmp(userresponseyesno, "YES") == 0))// if yes or y then moves to function to translate to shorthanded sentence.
		{
			translatetoshorthand(counter1, counter2, sentence, newarray, length, len, userresponse, size);
		}
		else if ((strcmp(userresponseyesno, "NO") == 0) || (strcmp(userresponseyesno, "N") == 0))// if no or n then moves to translate to english text.
		{
			translatetoenglish(counter1, counter2, len, length, new_word, userresponse, shorthandtotextuserresponse, size);
		}
		else
			cerr << "Please try again" << endl;//if response is not a correct form. this could be also handled by the while loop. I chose this to practice the output 
	} while (again() == true);//loops out only if true.




 	return 0;

}



bool again()
{
	//Declared Variable/ Local Variables.
	int i;//counters for the loop.
	int len;//len stops the for loop
	char userresponse[100];// input by the user

	//if yes and no question.
	cout << "Do you want to continue?" << endl;
	cin.get(userresponse, 100, '\n');
	cin.ignore(100, '\n');
	len = strlen(userresponse);

	// loop all characters inputted to capital.
	for (i = 0; i < len; ++i)
	{
		userresponse[i] = (toupper(userresponse[i]));
	}
	if ((strcmp(userresponse, "YES") == 0) || (strcmp(userresponse, "Y") == 0))
	{
		return true;
	}
	else if ((strcmp(userresponse, "NO") == 0) || (strcmp(userresponse, "N") == 0))
	{
		cout << "Thank you." << endl;
		return false;

	}
	else//tells the user to input a correct letter and will have to try agian if not. code will still work without this.
	{
		cerr << "Please type a Valid response and try again." << endl;
	
	}
}//all variables are in here for easier function calling







void translatetoshorthand(int counter1, int counter2, char sentence[], char newarray[], int length, int len, char userresponse[], const int size)
{
	
	cout << "Please type a sentence to convert to shorthanded text." << endl;
	cin.get(sentence, size - 1, '\n');
	cin.ignore(size, '\n');

	//local variable
	char untouchedsent[200];//third array that has all original and outputs the original text to user at the end.
	length = strlen(sentence);//initialize length
	strcpy(untouchedsent, sentence);//string copy to new to display code in case of unsatisfaction of change.

	//loops response of user until all letters are checked.
	for (counter1 = 0; counter1 <= length; ++counter1)
	{

		if (toupper(sentence[counter1]) == 'A' && toupper(sentence[counter1 + 1]) == 'N' && toupper(sentence[counter1 + 2]) == 'D')
		{
			newarray[counter2] = '+';
			counter2 += 1;

			newarray[counter2] = sentence[counter1 + 3];

			counter1 += 3;

		}//finds all responses with and and converts them.



		if (toupper(sentence[counter1]) == 'T' && toupper(sentence[counter1 + 1]) == 'H' && toupper(sentence[counter1 + 2]) == 'E')
		{
			if (isupper(sentence[counter1]))
			{
				newarray[counter2++] = 'T';
				newarray[counter2++] = '-';
				newarray[counter2] = sentence[counter1 + 3];

				counter1 += 3;
			}
			else
			{
				newarray[counter2++] = 't';
				newarray[counter2++] = '-';
				newarray[counter2] = sentence[counter1 + 3];

				counter1 += 3;
			}
		}//finds all responses with the and converts them whether caps or lower case.
	


		if (toupper(sentence[counter1]) == 'I' && toupper(sentence[counter1 + 1]) == 'N' && toupper(sentence[counter1 + 2]) == 'G')
		{

			newarray[counter2++] = '!';
			newarray[counter2++] = 'g';
			newarray[counter2++] = sentence[counter1 + 3];
			

			counter1 += 3;
		}//finds all ing and converts them to !g



		if (toupper(sentence[counter1]) == 'I' && toupper(sentence[counter1 + 1]) == 'S' && toupper(sentence[counter1 + 2]) == 'H')

		{

			newarray[counter2++] = '!';
			newarray[counter2++] = 'h';
			newarray[counter2] = sentence[counter1 + 3];

			counter1 += 3;


		}//finds all ish and converts the to !h



		if (toupper(sentence[counter1]) == 'E' && toupper(sentence[counter1 + 1]) == 'D')
		{

			newarray[counter2++] = ' ';
			newarray[counter2++] = 't';

			counter1 += 2;
		}//finds all ed and converts them if to  t.



		if (toupper(sentence[counter1]) == 'F' && toupper(sentence[counter1 + 1]) == 'O' && toupper(sentence[counter1 + 2]) == 'R')

		{

			newarray[counter2++] = '/';
			newarray[counter2] = sentence[counter1 + 3];

			counter1 += 3;

		}//finds all for and turns them to /


		if (toupper(sentence[counter1]) == 'W' && toupper(sentence[counter1 + 1]) == 'A' && toupper(sentence[counter1 + 2]) == 'S')

		{

			newarray[counter2++] = '=';
			newarray[counter2++] = sentence[counter1 + 3];
			counter1 += 3;

		}//finds all was and converts them to =


		else
		{

			newarray[counter2++] = sentence[counter1];//continues with the loop
		}
	}

	

	cout << "sentence with shorhand text:\n" << newarray << endl;
	cout << "change back to regular text?" << endl;
	cin.get(userresponse, size - 1, '\n');
	cin.ignore(size, '\n');

	len = strlen(userresponse);

	//loops userresponse for a yes or no to capitalize.
	for (counter1 = 0; counter1 < len; ++counter1)
	{
		userresponse[counter1] = toupper(userresponse[counter1]);
	}

	if ((strcmp(userresponse, "Y") == 0) || (strcmp(userresponse, "YES") == 0))
	{
		cout << "Regular text: \n" << untouchedsent << endl;

	}
	else if ((strcmp(userresponse, "NO") == 0) || (strcmp(userresponse, "N") == 0))
	{
		cout << "Thank you!" << endl;
	}
	else
		cerr << "Please try again" << endl;
}
//translates english text to shorthand presets. Does not output but will have the solution for conversion. the input will be in the declared variable in main. pass by value and arrays no pass by references.



void translatetoenglish(int counter1, int counter2, int len, int length, char new_word[], char userresponse[], char shorthandtotextuserresponse[], const int size)
{	

	//asks to convert type sentence.
	cout << "Please type a shorthanded text sentence to convert to english: \n";
	cin.get(shorthandtotextuserresponse, size - 1, '\n');
	cin.ignore(size, '\n');

	//local variables. strlen and string copy must be under the scope of the cin.get. so, local variables are moved down.
	char untouchedsent[200];
	len = strlen(shorthandtotextuserresponse);//variable that converts text into amount.
	length = strlen(userresponse);
	strcpy(untouchedsent, shorthandtotextuserresponse);


	for (counter1 = 0; counter1 <= len; ++counter1)
	{
		if (shorthandtotextuserresponse[counter1] == '+')//if + is used convert to and. each letter adds to the next array in the new word array and continues to the sentence in the shorthandtotextuserresponse. 
		{
			new_word[counter2++] = 'a';

			new_word[counter2++] = 'n';

			new_word[counter2++] = 'd';

		}

		else if (tolower(shorthandtotextuserresponse[counter1]) == 't' && shorthandtotextuserresponse[counter1 + 1] == '-')// checks if it t- or T-.
		{
			if (isupper(shorthandtotextuserresponse[counter1]))// if it is in caps convert to The
			{
				new_word[counter2++] = 'T';
			}
			else
			{
				new_word[counter2++] = 't';//if it is not, convert it into the.

			}

			new_word[counter2++] = 'h';

			new_word[counter2++] = 'e';
			counter1 += 1;//continue to the next letter
		}

		else if (shorthandtotextuserresponse[counter1] == '!' && shorthandtotextuserresponse[counter1 + 1] == 'g')//checks for !g
		{
			counter1 += 1;//adds on to original the loop 
			new_word[counter2++] = 'i';//checks for i in the loop and continues.

			new_word[counter2++] = 'n';//checks for n in the loop and continues.

			new_word[counter2++] = 'g';//checks for g in the loop and continues.

		}

		else if (shorthandtotextuserresponse[counter1] == '!' && shorthandtotextuserresponse[counter1 + 1] == 'h')//checks for !h
		{
			counter1 += 1;// movest the counter to next space in array.
			new_word[counter2++] = 'i';

			new_word[counter2++] = 's';

			new_word[counter2++] = 'h';

		}

		else if (shorthandtotextuserresponse[counter1] == ' ' && shorthandtotextuserresponse[counter1 + 1] == 't')// checks for ' ' t and converts them at the end of sentences
		{
			counter1 += 1;//moves counter to next space in array.
			new_word[counter2++] = 'e';

			new_word[counter2++] = 'd';
		}

		else if (shorthandtotextuserresponse[counter1] == '/')// converts / to for
		{


			new_word[counter2++] = 'f';

			new_word[counter2++] = 'o';

			new_word[counter2++] = 'r';

		}

		else if (shorthandtotextuserresponse[counter1] == '=')// converts to = if there is a was
		{

			new_word[counter2++] = 'w';

			new_word[counter2++] = 'a';

			new_word[counter2++] = 's';

		}
		else
		{

			new_word[counter2] = shorthandtotextuserresponse[counter1];//continues adding to the new word
			counter2 += 1;// continues space in the second counter

		}

	}

	cout << "The word with English text: \n" << new_word << endl;//echoes to the user


	cout << "change back to regular text?" << endl;
	cin.get(userresponse, size - 1, '\n');
	cin.ignore(size, '\n');


	//loops userresponse for a yes or no to capitalize.
	for (counter1 = 0; counter1 < length; ++counter1)
	{
		userresponse[counter1] = toupper(userresponse[counter1]);
	}

	if ((strcmp(userresponse, "Y") == 0) || (strcmp(userresponse, "YES") == 0))
	{
		cout << "Regular text: \n" << untouchedsent << endl;

	}
	else if ((strcmp(userresponse, "NO") == 0) || (strcmp(userresponse, "N") == 0))
	{
		cout << "Thank you!" << endl;
	}
	else
		cerr << "Please try again" << endl;




}
//translates shorthanded text to english text. Does not output but will have the solution for conversion. the input will be in the declared variable in main. pass by value and arrays no pass by references.


