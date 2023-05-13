#include<iostream>
#include<map>
#include<stdio.h>
using namespace std ;
typedef  long long ll ;
ll mod=1;
map < ll , ll > f1 ;
ll fibo(ll n)
{

    if(f1.count(n)){return f1[n];}
    ll k = n/2;
    if(n%2==0)
    {
        return f1[n]=((fibo(k)*fibo(k)+fibo(k-1)*fibo(k-1)))%mod;
    }
    else
    {
        return f1[n]=((fibo(k)*fibo(k+1)+fibo(k)*fibo(k-1)))%mod;
    }
}
int main()
{
    ll n,m;
    f1[0]=1;
    f1[1]=1;
    while(scanf("%llf %llf",&n,&m)!=EOF)
    {
        mod= 1 << m ;
        cout << fibo(n-1) << endl;
    }
    return 0;
}
