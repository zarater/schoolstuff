#include <iostream>

using namespace std;

double pi(int n);
int main()
{
    int to_100 = 100;
    int n;
    cout << "n" << endl;
    cin>> n;
   int piz = pi(n);
    cout << "pi"<< piz << endl;
    /* for{int i = 0; i < to_100; ++i }
    (
            if(number_arctan = pi())
    )
*/
return 0;
}


double pi( int n )
{
     double pi = 4.0 , decimal = 1.0;
     while( n > 2 )
    {
        decimal -= ( 1.0 / ( 2.0 * n + 1 ) );
        --n;
        decimal += ( 1.0 / ( 2.0 * n + 1 ) );
        --n;
    }
    if( n > 0 )
        decimal -= ( 1.0 / ( 2.0 * n + 1 ) );
    return( pi * decimal);
}