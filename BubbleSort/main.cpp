#include <iostream>

using namespace std;

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

int cnt=0;

/*
冒泡排序 基础版
1.0-n i-n
2.外层几次for,就有几个元素归位。
*/
void BubbleSort(int a[],int n)
{
    int i,j;
    int temp;

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[j]>a[i])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
                cnt++;
            }
        }
    }
}

/*
冒泡排序 优化版

如果有100个数的数组，只有前10个无序，而后90个都是有序的，那么只要第一趟遍历后，
最后发生交换的位置必定小于10，而且这个数之后的数据一定是有序的，而第二次遍历只要
遍历到这个位置就可以了，实验结果好像不如基础版本
*/
void BubbleSort2(int a[],int n)
{
    int i,j;
    int flag;
    int temp;

    flag=n;
    while(flag>0)
    {
        j=flag;
        flag=0;
        for(i=1;i<j;i++)
        {
            if(a[i-1]<a[i])
            {
                //swap(a[i-1],a[i])
                temp=a[i-1];
                a[i-1]=a[i];
                a[i]=temp;
                flag=i;
                cnt++;
            }
        }
    }

}



int data[]={1,2,4,5,6,4,3,2,7,8,9,0,1};

int main()
{
    int i,n;
    n=sizeof(data)/sizeof(int);
    cout << n << endl;
    BubbleSort2(data,n);
    cout << cnt << endl;
    dump(data,n);
    return 0;
}
