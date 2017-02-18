#include <iostream>
extern "C"
{
    #include "stackli.h"
}

using namespace std;

int main()
{
    Stack S;
    S = CreateStack();

    Push(10,S);
    Push(20,S);
    Push(30,S);

    while(!IsEmpty(S))
    {
        cout << Top(S) << endl;
        Pop(S);
    }

    DisposeStack(S);

    cout << "Hello world!" << endl;
    return 0;
}
