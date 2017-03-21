#include <iostream>
#include <malloc.h>
#include <stack>

using namespace std;

typedef char ElementType;
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *BTree;

struct TreeNode {
    ElementType Element;
    BTree Left;
    BTree Right;
};

BTree CreateTree()
{
    char c;
    BTree pTree;

    scanf("%c",&c);

    if(c==' ')
    {
        pTree=NULL;
    }
    else
    {
        pTree = (BTree)malloc(sizeof(struct TreeNode));
        pTree->Element=c;
        pTree->Left=CreateTree();
        pTree->Right=CreateTree();
    }

    return pTree;
}

//先序遍历 根 左 右
void pre_traverse(BTree pTree)
{
    if(pTree)
    {
        printf("%c ",pTree->Element);
        if(pTree->Left)
            pre_traverse(pTree->Left);
        if(pTree->Right)
            pre_traverse(pTree->Right);
    }
}

//中序遍历 左 根 右
void in_traverse(BTree pTree)
{
    if(pTree)
    {
        if(pTree->Left)
            in_traverse(pTree->Left);
        printf("%c ",pTree->Element);
        if(pTree->Right)
            in_traverse(pTree->Right);
    }
}

//后序遍历 左 右 根
void beh_traverse(BTree pTree)
{
    if(pTree)
    {
        if(pTree->Left)
            beh_traverse(pTree->Left);
        if(pTree->Right)
            beh_traverse(pTree->Right);
        printf("%c ",pTree->Element);
    }
}


//非递归实现
//先序遍历 根 左 右
void pre_traverse_n(BTree pTree)
{
    stack<BTree> s;
    BTree pCur=pTree;

    //直到当前节点pCur为NULL且栈空时，循环结束
    while( pCur || !s.empty())
    {
        //从根节点开始，输出当前节点，并将其入栈，
        //同时置其左孩子为当前节点，直至其没有左孩子，当前节点为NULL
        while(pCur)
        {
            printf("%c ",pCur->Element);
            s.push(pCur);
            pCur = pCur->Left;
        }

        //如果当前节点pCur为NULL且栈不空，则将栈顶节点出栈，
        //同时置其右孩子为当前节点,循环判断，直至pCur不为空
        if(!s.empty())
        {
            pCur = s.top();
            pCur = pCur->Right;
            s.pop();
        }
    }
}

//中序遍历  左 根 右
void in_traverse_n(BTree pTree)
{
    stack<BTree> s;
    BTree pCur=pTree;

    //直到当前节点pCur为NULL且栈空时，循环结束
    while(pCur || !s.empty())
    {
        while(pCur)
        {
            s.push(pCur);
            pCur = pCur->Left;
        }
        if(!s.empty())
        {
            pCur = s.top();
            printf("%c ",pCur->Element);
            s.pop();
            pCur = pCur->Right;
        }
    }
}


//后序遍历  左 右 根
void beh_traverse_n(BTree pTree)
{
    stack<BTree> s;
    BTree pCur=pTree;
    BTree pLastVisit=NULL;

    //先把pCur移动到左子树最下边
    while(pCur)
    {
        s.push(pCur);
        pCur = pCur->Left;
    }
    while(!s.empty())
    {
        //走到这里，pCur都是空，并已经遍历到左子树底端(看成扩充二叉树，则空，亦是某棵树的左孩子)
        pCur = s.top();
        s.pop();

        //一个根节点被访问的前提是：无右子树或右子树已被访问过
        if (pCur->Left == NULL || pCur->Right == pLastVisit)
        {
            printf("%c ",pCur->Element);
            pLastVisit = pCur;
        }
        else   //没被访问过
        {
            //根节点再次入栈
            s.push(pCur);
            //进入右子树，且可肯定右子树一定不为空
            pCur = pCur->Right;
            while (pCur)
            {
                s.push(pCur);
                pCur = pCur->Left;
            }
        }
    }
}

//根左右
void pre_traverse_3(BTree pTree)
{
    stack<BTree> s;
    BTree pCur=pTree;
    s.push(pTree);
    while(!s.empty())
    {
        pCur = s.top();
        s.pop();
        if(pCur)
        {
            printf("%c ",pCur->Element);
            s.push(pCur->Right);
            s.push(pCur->Left);
        }
    }
}

int main()
{
    /*测试数据:"abd  eh  i  cf  g  "*/
    BTree tree=CreateTree();
    cout << endl;
    pre_traverse(tree);
    cout << endl;
    in_traverse(tree);
    cout << endl;
    beh_traverse(tree);
    cout << endl;
    pre_traverse_n(tree);
    cout << endl;
    in_traverse_n(tree);
    cout << endl;
    beh_traverse_n(tree);
    cout << endl << "new:" << endl;
    pre_traverse_3(tree);
    cout << endl;

    return 0;
}
