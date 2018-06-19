#include "list.h"

//Place your name here in comments:
//
//
//
int main()
{
    //DO NOT DELETE ANY CODE! Comment it out if you change your mind
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    /*
    display_all(head);
    displayfirst(head);
    displaylast(head);
    displayfirsttwo(head);
    displaylasttwo(head);
    displayifnottwo(head);
    countnode(head);
    countnodeifvalueisnottwo(head);
    displayfirstandlast(head);
    displayfirstandlasttwo(head);
    deletebehind(head);
    everyother(head);
    countem(head);
    deleteinmiddles(head);
 //   even (head);
    swap(head);
    */
    addlast(head);

    display(head);
    //destroy(head);    
    return 0;
}


void display_all(node *head)
{
	node* current= head;

	if (!head)
	{
		return;
	}
	//cout << current -> data << endl;
	while(current)
	{
		cout << current -> data << endl;
		current = current -> next;
	}

}
int displayfirst(node * head)
{
    if (!head)
        return 0;
    cout << head ->data << endl;
    return head -> data;
}

int displaylast(node * head)
{
 node *current = head;
    if (!head)
        return 0;
    while (current-> next != NULL)
    {
        current = current -> next;

    }
   return  current->data;

}

void displayfirsttwo( node * head)
{
    node *current = head;
    if (!head)
            return ;
    int i = 0;
    while (current != NULL && i < 2)
    {
        cout<< current -> data<< endl;
        current=current->next;
        i+=1;
    }
    
    return;
}

void displaylasttwo(node * head)
{
    node *current = head;
    node * last = head;
    if (!head)
            return ;
    while (current->next ->next)
    {
        current = current -> next;
    }
    cout << current->next->data << endl;
    cout << current -> data << endl;
    return;

}
int displayifnottwo(node *head)
{
 node *current = head;
    if (!head)
        return 0;
    while (current-> next != NULL)
    {

        if (current->data!=2)
        {
            cout << current->data<< endl;
        }       
        current = current -> next;

    }
        return 0;     

}


int  countnode(node * head)
{ 
    int i;
    node *current = head;
    if (!head)
        return 0;
    while (current != NULL)
    {
        current = current -> next;
        ++i;

    }
    return i;

}


int countnodeifvalueisnottwo(node *head)
{
    int i;
    node *current = head;
    if (!head)
        return 0;
    while (current-> next != NULL)
    {
        if ( current->data !=2)
        {
            ++i;
        }
        current = current -> next;

    }
    return i;
}



void displayfirstandlast(node *head)
{
    node *current = head;

    if (!head)
            return;
    while (current->next ->next)
    {
        current = current -> next;
    }



cout << head->data << endl;
cout << current->data << endl;
}


//10
//
//

void displayfirstandlasttwo(node *head)
{
    node *current = head;

    if (!head)
            return;
    while (current->next ->next)
    {
        current = current -> next;
    }
    cout << head -> data << endl;
    cout << head -> next -> data << endl;
    cout << current->next->data << endl;
    cout << current -> data << endl;
    return;



}

void deletbehind(node *head)
{
/*
    node *temp = head;
    while(head)
    {
        delete [] head->data;
        head = head -> next; 
        delete temp;
        temp = head;
    */
    if (head)
    {
        return;
    }
    node *temp = head;
    while(head)
    {
        head = head -> next; 
        delete temp;
        temp = head;
    }
}


void everyother(node *head)
{
    int i=0;
    node *current = head;
    if (!head)
    {
        return;
    }
    while(current)
    { 
        if (i%2==0)
        {
            cout<< current->data << endl;
        }
        current=current->next;
        ++i;
       
    }

    
}


int countem(node*head)
{
	int i = 0;
	node*countem = head;
	while(countem)
	{
		countem = countem -> next;
		++i;
	}
	return i;
}
void deleteinmiddles(node* head)
{
	int j =0;
	int middle =0;
	
	node* previous = new node;
	node* current = head;
	node* temp = new node;

	//basecase
	if(!head)
	return;

	//condition
	//count how many i there are then divide by two


	middle = countem(head);
	cout << "number of nodes: " << middle << endl; // this could change if looking for other numbers to delete. such as second to last, third node, etc.
	middle = middle/2;//is  the middle
	
	cout << "middle number: " << middle << endl; // this could change if looking for other numbers to delete. such as second to last, third node, etc.
	//traversal
	
	//condition part
	//delete loop

	cout << "delete loop" << endl;
	while(current)
	{
		++j;
		if (middle == j && current -> next)
		{
			cout << "middle number: " << current -> data << "at place: " << j << " == " << middle << endl;
			cout << current->next->data << current ->next ->next->data << endl;
			//delete steps
			
			previous-> next = current -> next;
			delete current;
			/* this is the set up to delete node
				previous = current;
				previous -> next = current -> next;
				temp = current;
				delete current;
				current = current -> next;
			*/
			
		}
		//cout <<  current ->data << endl;
		previous = current;
		current = current -> next;
	}
	

	//troubleshoot
	cout << "all numbers after: " << endl;
 	display_all(head);
	

}



void swap(node *head)
{
	node *current = head;
	if (!head)
	return;
	//find a node
	//
	while(current)
	{
		
	}
}



 void even(node *head)
 {
	node *current = head;

	//base case
	if (!head)
	{
		return;
	}

	//condition
	//loop
	while(current)
	{
		if (current -> data % 2 ==0)
		{
			cout << current -> data << endl;
		}

		current = current -> next;
	}
	//trouble shoot

 }
 //void swapevens(node*head);
//void fizzbuzz(node *head)
int addlast(node *& head)
{
	int data = 9999;
	node * temp = new node;
	if(!head){ return 0;}
		if(head -> next==NULL)
		{
		cout << "head next : " << endl;
			temp -> next = head -> next;
			head -> next = temp;
		}

	return addlast(head -> next);
}
