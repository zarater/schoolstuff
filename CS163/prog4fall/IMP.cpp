#include "BST.h"
/*************************************************STRUCT INFO *******************************************/
//constructor
node:: node()
{

	keywords   = NULL;
	topic_names= NULL;
	websites   = NULL;
	summarys   = NULL;
	reviews    = NULL;
	//ratings    = 0;
}



//destructor
node::~node()
{
	if(keywords){ delete []keywords;}
	if(topic_names){delete []topic_names;}
	if(websites){ delete []websites;}
	if(summarys){ delete []summarys;}
	if(reviews) {delete  []reviews;}
	//if(ratings) {ratings= 0;}
}



int node::create(char keyword[], char topic_name[], char website[], char summary[], char review[], int rating)//add it to the struct object
{

	bool success = false;
	//if(topic_name&& website&& summary&& review&& rating){return success;}
	//{
	keywords = new char [strlen(keyword)+1];
	strcpy(keywords, keyword);

	topic_names = new char [strlen(topic_name)+1];
	strcpy(topic_names, topic_name);
	//cout <<"topic names" <<  topic_names << endl;

	websites= new char [strlen(website)+1];
	strcpy(websites, website);

	summarys = new char [strlen(summary)+1];
	strcpy(summarys, summary);

	reviews = new char [strlen(review)+1];
	strcpy(reviews, review);

	ratings = rating;	
	success = true;
	//}
	cout << "create out topic_names " << topic_names << endl;
	return success;//returns false if there isnt anything in the character arrays
}



int node::copy(node &to_add)//copies it to the object if it exists
{
	bool success = false;
	if(keywords){delete [] keywords;}
	if(topic_names){delete [] topic_names;}
	if(websites){delete [] websites;}
	if(summarys){delete [] summarys;}
	if(reviews){delete [] reviews;}

	//success will return false if any is null.

	if(to_add.topic_names&& to_add.websites&& to_add.summarys&& to_add.reviews && to_add.ratings)// if it does exist add them to the struct members and return success
	{
		keywords = new char [strlen(to_add.keywords)+1];
		strcpy(keywords, to_add.keywords);

		topic_names = new char [strlen(to_add.topic_names)+1];
		strcpy(topic_names, to_add.topic_names);

		websites= new char [strlen(to_add.websites)+1];
		strcpy(websites, to_add.websites);

		summarys = new char [strlen(to_add.summarys)+1];
		strcpy(summarys, to_add.summarys);

		reviews = new char [strlen(to_add.reviews)+1];
		strcpy(reviews, to_add.reviews);
		
		ratings = to_add.ratings;

		success = true;
	}
	return success;


}

bool node ::checkingf(char keyword[], node& checkn)//checks to find
{
	bool success = false;
	if(!keywords ||!keyword){return false;}
	if(!strcmp(keywords,keyword )==0){return false;}
	if(checkn.keywords && checkn.topic_names && checkn.websites&& checkn.summarys && checkn.reviews && checkn.ratings)
	{
		delete [] checkn.keywords;
		delete [] checkn.topic_names;
		delete [] checkn.websites;
		delete [] checkn.summarys;
		delete [] checkn.reviews;
		//checkn.ratings =0;
	}


	if(keywords && topic_names && websites&& summarys && reviews && ratings)
	{
		checkn.keywords= new char[strlen(keywords) +1];
		strcpy(checkn.keywords,keywords);

		checkn.topic_names = new char[strlen(topic_names) +1];
		strcpy(checkn.topic_names,topic_names);

		checkn.websites = new char [strlen(websites)+1];
		strcpy(checkn.websites, websites);

		checkn.summarys = new char[strlen(summarys)+1];
		strcpy(checkn.summarys, summarys);

		checkn.reviews = new char[strlen(reviews)+1];
		strcpy(checkn.reviews, reviews);

		checkn.ratings = ratings;
		success = true;
	}
	return success;// returns true if they do exist

}




/*************************************************CLASS BST *******************************************/
//constructor
bst::bst()
{
	
	//root = new root *[SIZE];
	root = NULL;
	MAX_A= SIZE;
	//number =0;
	//for(int i = 0; i < MAX_A; ++i)
	//{hash_root[i]= NULL;}

}


//destructor
bst::~bst()
{
	if(root){delete root;}
	if(MAX_A){MAX_A = 0;}
}

//insert function
int bst:: insert(char keyword[], node& to_add)
{
	return insert(keyword, to_add, root);
}
//strcmp a char array in order to 
int bst::insert(char keyword[], node& to_add, node*&root)
{
	int len = strlen(keyword);
	int compare;// will return the amount of whether string compare is a match or not. it will also have if its less then or greater then .
	if(root == NULL)
	{
		root = new node;
		root->copy(to_add);
		root -> left = root -> right =NULL;
		return 1;
	
	}

		for(int i = 0; i< len; ++i)
		{keyword[i]=toupper(keyword[i]);}

		compare =strcmp(keyword, to_add.keywords);
		
		if(compare< 0)
			{return insert(keyword, to_add, root -> left)+1;}
		return insert(keyword, to_add, root -> right) +1;
}



int bst :: retrieve(char keyword[], node& checkn)
{
	return retrieve(keyword, checkn, root);
}



//checks to find if it exists
int bst :: retrieve(char keyword[], node& checkn, node* root)
{
	

	bool success = false;
	node *current = root;
	if(!root){return 0;}
	if(current ->checkingf(keyword, checkn) == !success)
	{
		
		success = true;
		return success;

	}
	return retrieve(keyword, checkn, root->left)+ retrieve(keyword, checkn, root->right) ;
}



//displays all

int bst::display()
{
	
	displayall(root); 
	return 1;
}



int bst::displayall(node *root) //displays all by keyword
{
	if(root==NULL){return 0;}
	displayall(root->left);
	
		cout << "///////////////////////////////////" << endl;
		cout << root ->keywords<< endl;
		cout << root ->topic_names<< endl;
		cout << root ->websites<< endl;
		cout << root ->summarys<< endl;
		cout << root ->ratings<< endl;
		cout << root ->reviews << endl;
		cout << "///////////////////////////////////" << endl;
		cout << "///////////////////////////////////" << endl;
	displayall(root -> right);
	return 1;
}


			

int bst:: removeall(char topic_name[])//wrapper to topic name remove
{
	
	if(!root){return 0;}
	if(strcmp(topic_name, root->topic_names)!=0){return 0;}
	
 	removeall(topic_name, root);

	return 1;
}



int bst:: removeall(char topic_name[], node*& root)//removes per topic_name every instance
{



	if(!root){return 0;}
	if(strcmp(topic_name, root -> topic_names) == 0)
	{
		//leaf only needs to be deleted
		if(root -> left == NULL && root -> right == NULL)
		{
			root ->left= root -> right = NULL;
			delete root;
			root = NULL;
			return  removeall(topic_name, root);
		}

		//node with only one child left
		if(root -> left == NULL && root -> right != NULL)
		{
			node *temp = root;
			root = root -> right;
			delete temp;
			temp = NULL;
			return removeall(topic_name, root);
		}

		//internal node with only one child right
		if(root -> left != NULL && root -> right == NULL)
		{
			node * temp = root;
			root = root -> right;
			delete temp;
			temp = NULL;
			return removeall(topic_name, root);
		}
		//node with 2 children but the right child has no left children 
		if(root -> left != NULL &&  root -> right != NULL && root -> right -> left == NULL)
		{
			node *temp = root;
			root = root -> right;
			delete temp;
			temp = NULL;

			return removeall(topic_name, root);
		}
		// 2 children
		if(root -> left != NULL && root -> right != NULL && root -> right != NULL)
		{
			
			node*current = root -> right;
			while(current -> left)
			{
				if(current -> left -> left == NULL)
				{
					node *temp = current -> left;

					temp -> keywords = new char [strlen(root->keywords)];
					strcpy(temp -> keywords, root -> keywords);

					temp -> topic_names = new char [strlen(root->topic_names)];
					strcpy(temp -> topic_names, root -> topic_names);

					temp -> websites = new char [strlen(root -> websites)];
					strcpy(temp -> websites, root -> websites);

					temp -> summarys = new char[strlen(root -> summarys)];
					strcpy(temp -> summarys, root -> summarys);

					temp -> reviews = new char[strlen(root -> reviews)];
					strcpy(temp -> reviews, root -> reviews);
					temp -> ratings = root -> ratings;
					
					temp -> left = temp -> left -> right;
					delete temp;
					temp = NULL;
					return removeall(topic_name, root);
				}
			}
		}
	}
	
		cout << "outside remove" << endl;

	return removeall(topic_name, root-> left)+ removeall(topic_name, root -> right);
}




int bst :: remove(char keyword[])//remove keyword wrapper
{
	if(!root){return 0;}
	if(strcmp(keyword, root -> keywords) != 0){return 0;}
	 remove(keyword, root);
	return 1;
}




int bst:: remove(char keyword[], node *& root)// remove one website based on keyword
{
	if(!root){return 0;}
	if(strcmp(keyword, root -> keywords) == 0)
	{
		//leaf only needs to be deleted
		if(root -> left == NULL && root -> right == NULL)
		{
			delete root;
			root = NULL;
			return 1;
		}

		//node with only one child left
		if(root -> left == NULL && root -> right != NULL)
		{
			node *temp = root;
			root = root -> right;
			delete temp;
			temp = NULL;
			root = NULL;
			return 1;
		}


		//internal node with only one child right
		if(root -> left != NULL && root -> right == NULL)
		{
			node * temp = root;
			root = root -> right;
			delete temp;
			temp = NULL;
			return 1;
		}

		cout << "399" << endl;
		//node with 2 children but the right child has no left children 
		if(root -> left != NULL &&  root -> right != NULL && root -> right -> left == NULL)
		{
			node *temp = root;
			root = root -> right;
			delete temp;
			temp = NULL;

			return 1;
		}
		// 2 children
		if(root -> left != NULL && root -> right != NULL && root -> right != NULL)
		{
			node*current = root -> right;
			while(current -> left)
			{
				if(current -> left -> left == NULL)
				{
					node *temp = current -> left;

					temp -> keywords = new char [strlen(root->keywords)];
					strcpy(temp -> keywords, root -> keywords);

					temp -> topic_names = new char [strlen(root->topic_names)];
					strcpy(temp -> topic_names, root -> topic_names);

					temp -> websites = new char [strlen(root -> websites)];
					strcpy(temp -> websites, root -> websites);

					temp -> summarys = new char[strlen(root -> summarys)];
					strcpy(temp -> summarys, root -> summarys);

					temp -> reviews = new char[strlen(root -> reviews)];
					strcpy(temp -> reviews, root -> reviews);
					temp -> ratings = root -> ratings;
					
					temp -> left = temp -> left -> right;
					delete temp;
					temp = NULL;
					return 1;
				}
			}
		}
	}

	return remove(keyword, root-> left)+ remove(keyword, root -> right);
}



