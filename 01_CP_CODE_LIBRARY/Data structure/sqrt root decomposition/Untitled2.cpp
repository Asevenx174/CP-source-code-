#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std ;
int arr[100005],b[1000];
void ini(int x)
{
    for(int i=0;i<=x;i++){b[i]=-1;}
}
void update(int idx,int v,int sz)
{
    int k = idx/sz;
    b[k]=max(b[k],v);
}
int query(int l,int r,int sz)
{
    int small=1000000005,big=-1;
    int m1=-1,m2=-2,m3=-1;
    int left=l/sz;
    int right=r/sz;
    for(int i=l;i<(left+1)*sz;i++)
    {
      small=min(arr[i],small);
      big=max(big,arr[i]);
    }
    m1=big-small;
    for(int i=left+1;i<right;i++){m2=max(m2,b[i]);}
    small=1000000005,big=-1;
    for(int i=right*sz;i<=r;i++)
    {small=min(arr[i],small);
    big=max(big,arr[i]);}
    m3=big-small;
    m1=m1>m2 ? m1 : m2 ;
    m2=m1>m3 ? m1: m3 ;
    return m2;
}
int main()
{
    int n,d,bnum,small=100000005,big=-1,i;
    scanf("%d %d",&n,&d);
    bnum = sqrt(n);
    ini(bnum);
    for( i=0;i<n;i++)
    {
        int x ;
        cin >> x ;
        arr[i]=x;
        small=min(small,x);
        big=max(big,x);
        if((i+1)%d==0)
        {
            update(i,big-small,d);
            small=100000005,big=-1;
        }
    }
    update(i-1,big-small,d);
    int l=0,r=n-1;
    printf("%d\n",query(l,r,bnum));
    return 0;
}
