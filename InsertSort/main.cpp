#include <iostream>

using namespace std;

int data[101]={1,2,4,5,6,4,3,2,7,8,9,0,1};

void InsertSort(int a[],int n)
{
    int i,j;
    int temp;
    for(i=1;i<n;i++)     //一张牌，有序
    {
        temp=a[i];
        j=i;
        while((j>0)&&(a[j-1] > temp))  //从有序的数列中找到一个位置
        {
            a[j]=a[j-1];      //当前的数比新数据要大，就依次向后挪动
            j--;
        }
        a[j]=temp;     //插入到合适的位置
    }
}

void dump(int a[],int n)
{
    int i;
    cout << endl;
    for(i=0;i<n;i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main()
{
    InsertSort(data,13);
    dump(data,13);
    return 0;
}
