#include <stdio.h>
#include <stdlib.h>
#include "stackli.h"

#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

struct Node
{
    ElementType Element;
    PtrToNode Next;
};


int IsEmpty( Stack S )
{
    return S->Next == NULL;
}

Stack CreateStack( void )
{
    Stack S;

    S = malloc( sizeof( struct Node ));
    if ( S == NULL )
        FatalError( "Out of space!" );
    S->Next = NULL;
    //MakeEmpty(S);
    return S;
}

void MakeEmpty( Stack S )
{
    if(S == NULL)
        FatalError( "Must use CreateStack first" );
    while( !IsEmpty( S ) )
        Pop( S );
}


void Push( ElementType X, Stack S )
{
    PtrToNode TmpCell;

    TmpCell = malloc( sizeof( struct Node ));

    if(TmpCell == NULL)
        FatalError( "Out of space" );

    TmpCell->Element = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}


void Pop( Stack S )
{
    PtrToNode TmpCell;

    if(IsEmpty( S ))
        FatalError( "Empty stack" );
    else
    {
        TmpCell = S->Next;
        S->Next = TmpCell->Next;
        free(TmpCell);
    }
}

ElementType Top( Stack S )
{
    if( !IsEmpty( S ) )
        return S->Next->Element;

    FatalError( "Empty stack" );
    return 0;
}

void DisposeStack( Stack S )
{
    MakeEmpty( S );
    free( S );
}
