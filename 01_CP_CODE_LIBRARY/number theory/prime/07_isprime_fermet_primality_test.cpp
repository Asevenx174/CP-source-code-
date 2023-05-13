#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
// fermet say a^(p-1)=1 mod p  /// here = means congruence
// if it does not hold than p is not prime
// if does hold p probably prime
// why not sure ?
// there few number like p=511 , congruence does hold for some a
// p is a carmichel number
// but p is not prime , a is fooling us so its called fermet lair
// so we have to iterate for all a (2 to p-2)
// half them would be fermet lair and half of then called fermet witness
ll fastpow(ll n,ll k,ll mod)//log k
{
    ll ans = 1 ;
    while(k>0)
    {
        if(k&1)
        { ans = (ll)(ans*n)%mod; }
        k = (ll)k >> 1 ;
        n = (ll)(n*n)%mod;
    }
    return ans ;
}
bool isprime(ll p,ll iter)
{
    if(p<4){return p==2 || p== 3 ;}
    for(ll i=1;i<=iter;i++)
    {
        ll a = 2 + rand()%(p-3);
        if(fastpow(a,p-1,p)!=1 || __gcd(a,p)!=1)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ll n ;
    cin >> n ;
    if(isprime(n,10))
    {
        cout << "prime" << endl;
    }
    else
    {
        cout << "not prime" << endl;
    }
    return 0 ;
}
