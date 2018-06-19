#include <iostream>
#include <fstream>
#include <cstring>



using namespace std;

// const
const int SIZE = 100;
// struct
struct schedule // activity
{



	//variable members

	char *task;//what is the subject, math, etc.
	char *timeofactivity;//what time did you want it to be to start
	char *dayofactivity; // what days of the week did you want this activity
	char *duedate;//when is the due date for activity
	int hours;//military

};

struct node
{
    schedule weekly;
    node * next;
};


class day
{
	public:
		//constructor
		day();//default constructor

		//day(char *userinputday);
		//deconstructor
		~day();
		//member functions
		int add_activity(char *newtask, char * newtimeofactivity, char* newdayofactivity, char *newduedate, int newhours); // day add
		int edit_activity(char* timetofind, char *daytofind, char *tasktoedit);// day edit
		int copy_activity(char *timetofind, char* daytofind, char *daytocopy);//day activity
		int remove_activity(char *timetofind, char* daytofind);
		int display_all_activity(char * tasktofind, char * daytofind); // display activity
		int display_week(); // displays the entire week
		


	private:
		node* head;
		char *filename;
		char *userresponse;
		int searchtask(char *timetofind, char* daytofind, node*&headtemp);
		int traversefunction(node *&temp);
		int ofile(node*&headtemp);
		int ifile();

};





//prototypes
void fivequestions();
void editfunction();
void copyfunction();
void removefunction();
void displayfunction();
void display_week_function();

bool ask();

