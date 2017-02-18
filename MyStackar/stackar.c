#include <stdio.h>
#include <stdlib.h>
#include "stackar.h"


#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )

#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )


struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};




Stack CreateStack( int MaxElements )
{
    Stack S;

    if( MaxElements < MinStackSize )
    {
        FatalError( "Stack size is too small!" );
    }

    S = malloc( sizeof( struct StackRecord ) );

    if( S == NULL )
    {
        FatalError( "Out of space!" );
    }

    S->Array = malloc( sizeof( ElementType ) * MaxElements );
    S->Capacity = MaxElements;
    MakeEmpty( S );
    return S;
}


void DisposeStack( Stack S )
{
    if( S != NULL )
    {
        free( S->Array );
        free( S );

    }
}


void MakeEmpty( Stack S )
{
    while( !IsEmpty( S ) )
    {
        Pop( S );
    }
}

int IsEmpty( Stack S )
{
    return S->TopOfStack == EmptyTOS;
}

int IsFull( Stack S )
{
    return S->TopOfStack == S->Capacity - 1;
}

void Push( ElementType X, Stack S )
{
    if( IsFull( S ) )
    {
        FatalError( "Stack is full !" );
    }
    else
    {
        S->Array[ ++S->TopOfStack ] = X;
    }
}

ElementType Top( Stack S )
{
    if( !IsEmpty( S ) )
    {
        return S->Array[ S->TopOfStack ];
    }

    FatalError( "Stack is Empty !" );
    return 0;
}


void Pop( Stack S )
{
    if( !IsEmpty( S ) )
    {
        S->TopOfStack--;
    }
}

ElementType TopAndPop( Stack S )
{
    if( !IsEmpty( S ) )
    {
        return S->Array[ S->TopOfStack-- ];
    }

    FatalError( "Stack is Empty !" );
    return 0;
}



