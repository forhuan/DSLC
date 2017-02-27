#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )



struct TreeNode {
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};



SearchTree MakeEmpty( SearchTree T )
{
    if( T != NULL )
    {
        MakeEmpty( T->Left );
        MakeEmpty( T->Right );
        free( T );
    }
    return NULL;
}

Position Find( ElementType X, SearchTree T )
{
    if( T == NULL )
    {
        return NULL;
    }
    else if( X < T->Element )
        return Find( X , T->Left );
    else if( X > T->Element )
        return Find( X , T->Right );
    else /* X == T->Element */
        return T;
}

Position FindMin( SearchTree T )
{
    if( T != NULL)
    {
        if( T->Left != NULL )
            return FindMax( T->Left );
        else /* T->Left == NULL */
            return T;
    }
    return NULL;
}

Position FindMax( SearchTree T )
{
    if( T != NULL)
    {
        if( T->Right != NULL )
            return FindMax( T->Right );
        else /* T->Right == NULL */
            return T;
    }
    return NULL;
}

SearchTree Insert( ElementType X, SearchTree T )
{
    if( T == NULL )
    {
        /*create and return an one-node tree */
        T = malloc( sizeof( struct TreeNode ));
        if( T == NULL )
        {
            FatalError( "Out of space ! " );
        }

        T->Element = X;
        T->Left = T->Right = NULL;
    }
    else if( X < T->Element )
    {
        T->Left = Insert( X , T );
    }
    else if( X > T->Element )
    {
        T->Right = Insert( X , T );
    }

    return T;
}

SearchTree Delete( ElementType X, SearchTree T )
{




}


ElementType Retrieve( Position P )
{
    return P->Element;
}
