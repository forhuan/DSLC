#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
#define MinQueueSize ( 5 )

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;

};
/*
    [ ] [ ] [ ] [] [] [] []
    ¡ü      ¡ü
    Front    Rear
*/

int IsEmpty( Queue Q )
{
    return Q->Size == 0;
}


void MakeEmpty( Queue Q )
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}


int IsFull( Queue Q )
{
    return Q->Size == Q->Capacity;
}

static int Succ( int Value , Queue Q )
{
    if( ++Value == Q->Capacity )
    {
        Value = 0;
    }

    return Value;
}

void DisposeQueue( Queue Q )
{
    if( Q != NULL )
    {
        free( Q->Array );
        free( Q );
    }
}


Queue CreateQueue( int MaxElements )
{
    Queue Q;

    if( MaxElements < MinQueueSize )
    {
        FatalError( "Queue size is too small!" );
    }

    Q = malloc( sizeof( struct QueueRecord ) );

    if( Q == NULL )
    {
        FatalError( "Out of space !" );
    }

    Q->Array = malloc( sizeof( ElementType ) * MaxElements );

    if( Q->Array == NULL )
    {
        FatalError( "Out of space !" );
    }

    Q->Capacity = MaxElements;
    MakeEmpty( Q );

    return Q;
}



void Enqueue( ElementType X, Queue Q )
{
    if( IsFull( Q ) )
    {
        FatalError( "Queue is full !" );
    }

    Q->Size++;
    Q->Rear = Succ( Q->Rear , Q );
    Q->Array[ Q->Rear ] = X;

}


ElementType Front( Queue Q )
{
    if( !IsEmpty( Q ) )
    {
        return Q->Array[Q->Front];
    }

    FatalError( "Empty queue" );
    return 0;
}


void Dequeue( Queue Q )
{
    if( !IsEmpty( Q ) )
    {
        Q->Front = Succ( Q->Front , Q );
        Q->Size--;

    }

    FatalError( "Empty queue !" );
    return 0;

}


ElementType FrontAndDequeue( Queue Q )
{
    ElementType X = 0;
    if( !IsEmpty( Q ))
    {
        Q->Size--;
        X = Q->Array[Q->Front];
        Q->Front = Succ( Q->Front , Q );
    }
    else
    {
        FatalError( "Empty queue !" );
    }
    return X;

}



