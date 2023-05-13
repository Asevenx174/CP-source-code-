void primefactor(int x,int a[]);
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n,a[10000];
    cin >> n ;
    primefactor(n,a);
    for(int i=0;a[i]!=-1;i++)
    {
        cout << a[i] << endl ;
    }
    return 0 ;
}
void primefactor(int x,int a[])
{
    int i,j=0,k;
    static int f=0;
    while(x%2==0)
    {
        x/=2;
        if(f==0)
        {
            a[j]=2;
            j++;
        }
        f=1;
    }
    k=sqrt(x);
    for(i=3; i<=k; i+=2)
    {
        if(x%i==0)
        {
            a[j]=i;
            x=x/i ;
            f=1;
            j++;
        }
    }
    if(x>2 && f==1)
    {
        a[j]=x;
        j++;
    }
    a[j]=-1;
}
