//#ifndef BASEMOTHER_H
//#define BASEMOTHER_H 


class vertex 
{
	public:
	vertex();
	~vertex();
	class table *a_graph;

	class drone *dronev;
	class node* head;
	
};



class node
{
	public:
	node();
	//~node();
	node *& gonext();//head -> next is similar
	//int setnext(node * temp);
	int setdata(int);

	private:
	int data;
	node * next;
	vertex *list;//adjacent list

};



//photo drone, racing drone, selfie drone
class drone
{
	public:
	drone();
	///~drone();
	int distance(int); // how fast it goes elevation	
	int size(int, int, int);//size of the plane
	int photo(char []);

	private:
	int adistance;
	int length;
	int height;
	int elevation;
	char *snap;
	
};

class table
{
	public:
	table();
	//~table();
	int insert_vertex(photo& photodrone, racing& racingdrone, selfie& selfiedrone);
	int find_location(char key_value[]);
	int insert_edge(char current_vertex[], char to_attach[]);
	//display_adjacent(char key_value[]);
	int displayall();

	protected:

	vertex* adjacent;
	int list_size;

};


//#endif //basemother.h
