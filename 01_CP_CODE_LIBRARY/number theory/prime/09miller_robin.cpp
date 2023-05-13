#include<iostream>
#include<cstdint>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<queue>
#include<vector>
#include<utility>
#include<cstring>
#include<limits.h>
#define pb(a)             push_back(a)
#define mp(a,b)           make_pair(a,b)
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define loop(i,a)          for(int i=1;i<=a;i++)
#define pii                pair <int,int>
#define sl(a)              scanf("%I64d",&a)
#define sll(a,b)           scanf("%I64d %I64d",&a,&b)
#define si(a)              scanf("%d",&a)
#define sii(a,b)           scanf("%d %d",&a,&b)
#define EulerGamma 0.57721566490153286060651209;/// when n>1e6  nth harmonic num = log(x+.5)+EulerGamma;
///UINT_MAX 2^32
///ULLONG_MAX 2^64
using namespace std ;
typedef unsigned long long ll ;
ll mulmod(ll a,ll b,ll c)
{
    ll x = 0 , y = a%c ;
    while(b>0)
    {
        if(b%2) x = (x+y)%c ;
        y=(y*2)%c;
        b/=2;
    }
    return x%c ;
}
ll modulo(ll a,ll b,ll c)
{
    ll x = 1 , y = a%c ;
    while( b > 0 )
    {
        if(b%2) x = mulmod(x,y,c) ;
        y=mulmod(y,y,c);
        b/=2;
    }
    return x%c ;
}
bool check_composite(ll n,ll a,ll d,ll s)/// this function has 2 condition if one of them is true then its compo
{                         /// a^d = 1 mod n  /// a^(d*2^r) = 1 mod n // 0<=r<=s-1
    ll x = modulo(a, d, n);
    if (x == 1 || x == n - 1)
    {
        return false;
    }
    for (int r = 1; r < s; r++)/// x is = a^d % n // a^(d*2^r)=a^d * a^(2^r) = (a^d)^(2^(r)) // 0<=r<=s-1
    {
        x = (ll)(x*x)%n;
        if (x == n - 1)
        {
            return false ;
        }
    }
    return true;
}
bool miller(ll n)
{
    if(n<4){return n==3 || n==2 ;}
    if((n&1)==0){return false;}///even not prime
    ll d = n-1,s=0;
    while((d&1)==0)///d and s such that n-1=d*2^s
    {
        d>=1;
        s++;
    }
    for(ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37)///for a if cheak_compo function is true than n is composite
    {
        if(a==n){return true ; }
        ll a = 2 + rand() % (n - 3);
        if(check_composite(n,a,d,s))
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
  if(miller(n))
  {
      cout << "prime" << endl;
  }
  else
  {
      cout << "not prime" << endl;
  }
  return 0 ;
}
