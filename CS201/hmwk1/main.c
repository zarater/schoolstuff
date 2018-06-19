#include <stdio.h>
#include <string.h>

int firstThreeLines(maze[]);
int check(char maze[]);
int down();
int left();
int right();
int up();

int main()
{
	FILE *ptr_file;
	char buffer[100];
	char arrayA[100];

	ptr_file= fopen("maze2.txt", "r");
	if(!ptr_file){return 1;}
	
	while(fgets(buffer,100, ptr_file)!=NULL)//add null to each line? have to confirm later. something to watch...
		{
			firstThreeLines(buffer);
			//check(buffer);
		}

	fclose(ptr_file);
	
	printf("\nEND PROGRAM\n");
	return 0;
}


int firstThreeLines(char maze[])
{
	int line_L;

}
int check(char maze[])// check finds the first 0 values and moves to the next in that row.
{
		//printf("%s", buffer);//this is just to check if im reading. it also reprints maze
		//printf("%c\n",buffer[3]);//%d is ascii %s all character %c one character print

	int i, nextZero, len;
	len = strnlen(maze, 1000)+1;
	
	//printf("%d\n", len);
	for(i; i<len; i++)
	{
	//printf("\nTHIS IS AN X\n");
		//if(maze[i] ==88){printf("\nTHIS IS AN X\n");}	
	}
return len;
}


int down(){}
int left(){}
int right(){}
int up(){}
