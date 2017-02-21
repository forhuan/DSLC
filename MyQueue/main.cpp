#include <iostream>

using namespace std;

extern "C"
{
    #include "queue.h"
}

int main()
{
    Queue Q;
    Q=CreateQueue(30);
    for(int i=0;i<30;i++)
    {
        if(!IsFull(Q))
            Enqueue(i,Q);
    }

    for(int i=0;i<30;i++)
    {
        if(!IsEmpty(Q))
        {
            cout << FrontAndDequeue(Q) << " ";
        }

    }
    DisposeQueue(Q);
    cout <<endl;
    cout << "Hello world!" << endl;
    return 0;
}
