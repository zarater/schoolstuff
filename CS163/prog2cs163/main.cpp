#include "list.h"

int main()
{
    int user= user_response();//determines what client will do.
    do{
        switch (user)
        {
            case 1:
            /*1. add new text*/
            insert();
            break;

            case 2:
            /*2. display all text*/
            display_all();
            break;

            case 3:
            /*3. replace all text*/
            remove_all();
            break;

            case 4:
            /*4. remove most recent characters*/
            edit();
            break;

            default:
             cout << "wrong choice" << endl;
            break;
        }
    }while(ask == 0);
	return 0;
}


    int insert()
    {
        char user[100];
        int len;
        int wordlength = 0;
        cout << "Please type a word less then five characters." << endl;
        do{
            if(wordlength_newword > 1){cout << "Please type a new word." << endl;}
            cin.get(user, SIZE, '\n');
            cin.ignore(100, '\n');

            len = strlen(user);
            if(len > 5){cout << "word is too big." return 0;}

            ofile(len, user);
            ifile();
            ++wordlength_newword;

        }while(ask()==true);
    }

    int ofile(int len, char user[])
    {
        file_out.open(filename, ios::app);
        if(!file_out){ cout << "no file exits yet" << endl; return 0;}
        else
            {
                for(int i; i< len; ++i;)
                {               
                   file_out << user[i] << ':' << endl;
                }

            } 
            file_out.clear();
            file_out.close();
            return 1;
    }
    int ifile()
    {
        char *letter = new char[SIZE];
        char buffer[SIZE];
        int letter_count= 0;
        ifstream file_in;
        file_in.open(filename);
        if(!file_in){cout << "No File" << endl; return 0;}
        while(file_in && !file_in.eof())
        {
                file_in.get(buffer, SIZE, ':');
				strcat(letter, buffer); 
				file_in.ignore(SIZE, ':');
                ++letter_count;
            m.my_letters->push(letter, letter_count);
        }
        file_in.clear();
        file_in.close();
    }


    int display_all()
    {
        int user;
        cout << "Please type what to display. prese 1 to display characters, press 2 to display words." << endl;
        cin >> user;
        cin.ignore(SIZE, '\n');

        if(user == 1){m.my_letters->display(); return 1;}
        if(user== 2){m.my_words->display(); return 1;}
        else
            return 1;
    }



    int remove_all()
    {
         int user;
        cout << "Please type what to display. prese 1 to display characters, press 2 to display words." << endl;
        cin >> user;
        cin.ignore(SIZE, '\n');

        if(user == 1){m.my_letters->pop(); return 1;}
        if(user== 2){m.my_words->dequeue(); return 1;}
        else
            return 1;
    }
    int edit(){}

    int user_response()
    {
        char user[SIZE]; 
        cout << "What would you like to do?"<< endl << endl;

        cout << "Type 'Add' to Add a text." << endl;//case 1
        cout << "Type 'Display' to Display all."<< endl;//case 2
        cout << "Type 'Remove' to Remove all." << endl;//case 3
        cout << "Type 'Edit' to edit." << endl;//case 4

        cout << "Otherwise, to exit the program press anything or enter." << endl;
        
        cin.get(user, SIZE, '\n');
        cin.ignore(100, '\n');
        int len = strlen(user);
        for (int i; i<len; ++i)
        { user[i] = (toupper(user[i])); }

        if (strcmp(user, "ADD")== 0){return 1;}
        if (strcmp(user, "DISPLAY")== 0){return 2;}
        if (strcmp(user, "REMOVE")== 0){return 3;}
        if (strcmp(user, "EDIT")== 0){return 4;}
        return 5;
    }



    bool ask()
    {
        const int yesno = 4;// expects a yes, no, YES, NO, Y, N, n, or y.
        int len;// will be initialized
        int i = 0;
        char userresponse[yesno];

        cout << "do you want to continue?" << endl;

        cin.get(userresponse, yesno, '\n');//asks user for a response
        cin.ignore(100, '\n');
        len = strlen(userresponse);// initializes len
        for (i; i < len; ++i)
        {userresponse[i] = (toupper(userresponse[i]));}//upper cases all 

        if ((strcmp(userresponse, "YES") == 0) || (strcmp(userresponse, "Y") == 0)){return true;}

        else if ((strcmp(userresponse, "NO") == 0) || (strcmp(userresponse, "N") == 0))	
        {cout << "Thank you." << endl;	return false;}

        return false;
    }
