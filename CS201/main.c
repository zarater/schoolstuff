#include <stdio.h>

void print_even(int i){printf("even: %d\n", i);}
void print_odd(int i){printf("odd: %d\n", i);}

int main()
{
	int argc;
	argc = 3;
	void(*fp)(int);

	fp = (argc%2)?  print_odd : print_even;// 0 is false so if 10 is even, then it will be 0 in argument argc%2. it is true though.
	fp(argc);
	return 0;
}
