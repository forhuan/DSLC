#ifndef STACKLI_H_INCLUDED
#define STACKLI_H_INCLUDED

typedef int ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty( Stack S );
Stack CreateStack( void );
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( ElementType X, Stack S );
ElementType Top( Stack S );
void Pop( Stack S );

#endif // STACKLI_H_INCLUDED
