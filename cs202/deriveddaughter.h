//#ifndef DERIVEDDAUGHTER_H
//#define DERIVEDDAUGHTER_H
//#include "basemother.h"
//#include "graph.h"

class photo :public drone
{
	public:
	photo();
	//~photo();
	int distance(int);
	int size(int, int, int);
	int photodrone(char aphoto[]);

	protected:
	int udistance;
	int uheight;
	int ulength;
	int uphoto;
	int uelevation;
	char *usnap;
	
};



class racing : public drone
{
	public:
	racing();
	//~racing();
	int distance(int);
	int size(int, int, int);

	protected:
	int udistance;
	int uheight;
	int ulength;
	int uelevation;



};


class selfie :public drone
{
	public:
	selfie();
	//~selfie();
	int distance(int);
	int size(int, int, int);
	int photodrone(char aphoto[]);

	protected:
	int udistance;
	int uheight;
	int ulength;
	int uphoto;
	int uelevation;
	char *usnap;
	
};









//#endif //daughter
