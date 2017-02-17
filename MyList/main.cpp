#include <iostream>
#include <cstdlib>
#include <cstdio>

extern "C"
{
#include "list.h"
}
using namespace std;

int main()
{
    List L;
    Position P;

    L=Create();
    Insert(10,L,L);
    Insert(20,L,Find(10,L));
    Insert(30,L,Find(10,L));

    P=L;
    while( !IsLast( P , L ) )
    {
        P=Advance(P);
        cout << Retrieve(P) << " -> " ;
    }


    cout << endl;

    Delete( 20 , L );

    P=L;
    while( !IsLast( P , L ) )
    {
        P=Advance(P);
        cout << Retrieve(P) << " -> " ;
    }

    cout << endl;

    L = MakeEmpty(L);

    free(L);

    cout << "Hello world!" << endl;
    return 0;
}
