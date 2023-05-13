#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll maxx = 32005 , n = 1e9+5;
vector < ll > primes ;
void seive()/// 1 to root n er mdde shob prime ber krbe
{
    vector < bool > isprime(maxx,true);
    primes.push_back(2);
    for(ll i=3;i*i<=maxx;i+=2)
    {
        if(isprime[i]==true)
        {
            for(int j=i*i;j<=maxx;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
    for(ll i=3;i<=maxx;i+=2){if(isprime[i]==true){primes.push_back(i);}}
}
void segseive(ll l ,ll r)
{
    vector < bool > isprime(r-l+1,true) ; ///range er mdde k prime k prime na
    for(ll i = 0 ; primes[i]*primes[i]<=r ; i++)// 3 jemon 9,12,15 k kate
    {
        ll cp = primes[i] ; // current prime
        ll base = (l/cp)*cp;
        if(base<l){base+=cp;}
        for(ll j = base ; j<=r; j+=cp)//base blte range er mdde kotha theke shuru krbo
        {
            isprime[j-l]=false;
        }
        if(base==cp){isprime[base-l]=true;}// [3,25] ei range a ektu prb hoy
    }
    for(int i=0;i<r-l+1;i++)
    {
        if(isprime[i]==true && i+l!=1){cout << i+l << endl;}
    }
}
int main()
{
    seive();
    ll l,r;
    ll test ;
    cin >> test ;
    for(int i=1;i<=test;i++)
    {
        if(i!=1){cout << endl;}
        cin >> l >> r ;
        segseive(l,r);
    }
    return 0 ;
}
