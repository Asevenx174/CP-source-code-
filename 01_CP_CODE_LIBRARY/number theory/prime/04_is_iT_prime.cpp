#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
bool isitprime(ll n)// root n comx
{
    if(n==2){return true;}
    if(n<2 || n%2==0){return false;}
    for(ll i=3;i*i<=n;i+=2)
    {
        if(n%i==0){return false;}
    }
    return true;
}
int main()
{
    ll n ;
    if(isitprime(n))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0 ;
}
