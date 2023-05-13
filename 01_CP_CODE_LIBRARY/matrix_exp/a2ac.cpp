#include<iostream>
#include<map>
#include<vector>
#include<stdio.h>
using namespace std ;
typedef long long ll;
map < ll , ll > v ;
ll mod=1;
ll fib(ll n)
{
    if(v.count(n)){return v[n];}
    ll k = n/2 ;
    if(n%2==0)
    {
        return v[n]=(fib(k)*fib(k)+fib(k-1)*fib(k-1))%mod;
    }
    else
    {
        return v[n]=((fib(k)*fib(k+1)+fib(k)*fib(k-1)))%mod;
    }
}
int main()
{
    ll m,n;
    while(cin >> n)
    {
        v[0]=1;
        v[1]=1;
        cin >> m ;
        mod = 1 << m ;
        if(n==0){cout << "0"<<endl;continue;}
        cout << fib(n-1) << endl;
        v.clear();
    }
    return 0;
}
