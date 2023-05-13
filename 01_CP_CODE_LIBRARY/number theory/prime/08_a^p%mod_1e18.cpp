#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<bitset>
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
int main()
{
    return 0;
}
