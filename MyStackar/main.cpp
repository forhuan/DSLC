#include <iostream>

extern "C"
{
    #include "stackar.h"
}


using namespace std;

int main()
{
    Stack S;
    S=CreateStack(30);
    for(int i=1;i<10;i++)
    {
        if(!IsFull(S))
            Push(i,S);
    }

    while(!IsEmpty(S))
    {
        cout << TopAndPop(S) << endl;
    }

    DisposeStack(S);
    cout << "Hello world!" << endl;
    return 0;
}
