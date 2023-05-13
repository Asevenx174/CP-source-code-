#include<iostream>
using namespace std ;
int arr[4500],brr[700];
void gener()
{
    int n = 4000,y=0;
    arr[1]=1;
    for(int i=4;i<=n;i+=2){arr[i]=1;}
    for(int i=3;i*i<=n;i+=2)
    {
        if(arr[i]==0)
        {
            for(int j=i+i;j<=n;j+=i)
            {
                if(arr[j]==0){arr[j]=1;}
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==0){brr[y++]=i;}
    }
}
int euler_fun(int n)
{
    double ans=n;
    for(int p=2;p*p<=n;p++)
    {
        while(n%p==0)
        {
            n/=p;
            ans=ans*(1.0-(1.0/(double)p));
        }
    }
    if(n>1)
    {
        ans=ans*(1.0-(1.0/(double)n));
    }
    return (int)ans;
}
int main()
{
    gener();
    int n ;
    cin >> n ;
    cout << euler_fun(n) << endl;
    return 0 ;
}
