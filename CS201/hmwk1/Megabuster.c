#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*does not compile for some reason. wasnt able to determine what was the issue while making the 2d array. however, i followed the RHS algorithm to traverse. 
i divided my code into multiple parts. the first struct was me trying to understand code and the local struct has a typedef struct which worked alot better.*/


// Structs will be located here
struct MegaBuster
{
	char* arrayX;
	char* arrayO;

};
//Functions will be located here
int mazebuster(FILE *mazetxt);

//Main will be located here
int main(int argc, char *argv[])
{

	//variables
		FILE *mazetxt = fopen(argv[1], "r");
		int (*ptrMazebuster)();//function pointer

	//User allocates variables here

	//read in FILEin
	if((mazetxt = fopen(argv[1], "r"))==NULL){printf("cant open\n");	
	return 1; //exit
	}
	//else ->
	mazebuster(mazetxt);
	//function pointer

	//read out FILEout
	fclose(mazetxt);
	return 0;
}

//Implementation will be located here
int mazebuster(FILE *mazetxt)
{
		struct MegaBuster demonsions;
	typedef struct Maze{ 
	int ix, iy, startx, starty, endx, endy;//first three lines of code
	char *ppRows; 
	}MAZE; 
	struct Maze maze; 
	
	//first three lines.
	int i, j, ret,x,n1,n2, counter, size, m,n, col, row;
	int inc = 1;//right or down
	int dec =-1;//left or up
    	int count = 0;
    	char line[256];
	char c;

	FILE *pf = mazetxt;
	for(i = 0; i <3; i++)
	{
		x=0;
	while(fscanf(pf,"%d %*c %d%*c",&n1,&n2 )&& i<= 3)
	{
		if(x == 0){  maze.ix= n1; maze.iy = n2;}//rows x and colsy
		if(x == 1){  maze.startx= n1; maze.starty = n2;}
		if(x == 2){  maze.endx= n1; maze.endy = n2;}
		x++;
		//printf("here it its: %d %d", n1, n2);
	}
	}
		printf("here it is: %d %d %d %d %d %d\n", maze.ix, maze.iy, maze.startx, maze.starty, maze.endx, maze.endy);


char cMaze[maze.ix][maze.iy]; 
//while (fgets(line, sizeof(line), mazetxt))
//{
	//count++;
	//if(count <= maze.iCols)
	//{
	//printf("%s", line);   
	//begin 2d implementation
		for ( j=0; j <= maze.iy; j++){//i = y
			for (  i = 0; i <= maze.ix; i++)//j = x
			{
			//printf(">%d ,%d, x%d, y%d<", i, j, maze.ix, maze.iy);
		
				c = fgetc(mazetxt);
				cMaze[i][j] = c;
			//	printf("%c", cMaze[i][j]);
			//	while(!((c=='X') || (c == '0')))
			//	{
				//c=fgetc(mazetxt);
				//}

			}
			}
				row = maze.startx;
				col = maze.starty;
				cMaze[row][col];

				//start maze traversal

					do{
						//printf("%d, %d | ", row, col);

						if(cMaze[row + inc][col] == '0'){
							row = row + inc;
							cMaze[row][col]='W';
						}else if (cMaze[row][col + inc] == '0' ) {
							col = col + inc;
							cMaze[row][col]='W';
						}else if (cMaze[row + dec][col] == '0') {
							row = row + dec;
							cMaze[row][col]='W';
						} else if (cMaze[row][col + dec] == '0') {
							col = col + dec;
							cMaze[row][col]='W';
						}//right, down, left, up
						if(col == maze.endx && row == maze.endy){break;}
					}while((row != maze.startx && col != maze.starty) || (row != maze.endx && col != maze.endy) );
					if (row != maze.endx && col != maze.endy) {
						printf("No path was found.");
					}else if (row == maze.endx && col == maze.endy) {
						printf("A path was found.");
					}else{
						printf("Error.");
					}

					//for (i=0; i < m; i++)
					//	for (j=0; j < n; j++)  
					//	{
					//		if (j == 0) printf("\n");                
					//		printf("%c  ", cMaze[i][j]);
					//	}
					//printf("\n");



if (cMaze[i][j] != 'X' || cMaze[i][j] != '0') 
{

	// at least one char is not X or 0 
	return 0;
}


	return 1;
}
