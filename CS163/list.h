#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

struct node
{
	int data;
	node *next;
};


/******************************
given functions in the .o file to practice random list*/

void build(node *&head);
void display(node* head);
void destroy(node *&head);

/*****************************/


/* prototype  code here */


    /*
    void display_all(node*head);
    void displayfirst(node *head);
    void displaylast(node* head);
    void displayfirsttwo(node* head);
    void displaylasttwo(node* head);
    void displayifnottwo(node* head);
    void countnode(node* head);
    void countnodeifvalueisnottwo(node* head);
    void displayfirstandlast(node* head);
    void displayfirstandlasttwo(node* head);
    void deletebehind(node* head);
    void everyother(node* head);
    int countem(node*head) // this could be used to find the node in the list by finding how many nodes with this function
    void deleteinmiddles(node* head);
    void even(node *head);
    void swap(node *head);
    */
 
    void display_all(node*head);
    int addlast(node *& head);
