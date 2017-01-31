#include <iostream>

using namespace std;

int data[101]={1,2,4,5,6,4,3,2,7,8,9,0,1};

void QuickSort(int a[],int left,int right)
{
    int i,j,t,temp;

    if(left>right)   //> >= ？
        return;

    temp=a[left];    //基准数
    i=left;
    j=right;

    while(i!=j)
    {
        //顺序很重要，先从右边开始找
        while(a[j]>=temp && i<j)
            j--;

        //再找左边的
        while(a[i]<=temp && i<j)
            i++;

        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }

    }
    //基数归位
    a[left]=a[i];
    a[i]=temp;

    QuickSort(a,left,i-1);//继续处理左边的
    QuickSort(a,i+1,right);//处理右边的

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
    dump(data,13);
    QuickSort(data,0,12);
    dump(data,13);
    cout << "Hello world!" << endl;
    return 0;
}
