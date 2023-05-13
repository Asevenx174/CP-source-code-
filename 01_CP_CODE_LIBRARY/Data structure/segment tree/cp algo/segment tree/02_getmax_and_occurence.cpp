#include<bits/stdc++.h>
#define pb           push_back
#define mp           make_pair
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define PI 3.14159265 /// tan inverse = atan(value)*(180/PI)

#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>


using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}

pii t[4*maxx];
ll ar[maxx+10] ; 

pii combine( pii a, pii b)
{
    if (a.ff > b.ff ) { return a ; }
    if (b.ff > a.ff ) { return b ; }
    pii p = { a.ff,a.ss+b.ss } ; 
    return p ; 
}

void build(ll v, ll tl,ll tr)
{
    if (tl == tr) { t[v] = make_pair(ar[tl], 1) ; return ; }
    ll  tm = (tl + tr) / 2LL ;
    build( v*2, tl, tm);
    build( v*2+1, tm+1, tr);
    t[v] = combine(t[v*2], t[v*2+1]);
}

pii get_max(ll v,ll tl,ll tr,ll l,ll r) // get the max of of range , and its occurence 
{
    if (l > r) { return make_pair(-imax, 0) ; }
    if (l == tl && r == tr) { return t[v] ; }
    ll tm = (tl + tr) / 2LL ;
    pii lc =  get_max(v*2, tl, tm, l, min(r, tm)) ;  
    pii lr =  get_max(v*2+1, tm+1, tr, max(l, tm+1), r) ;
    return combine(lc,lr) ; 
}

void update(ll v,ll tl,ll tr,ll pos,ll new_val)
{
    if (tl == tr) {  t[v] = make_pair(new_val, 1) ; return ; }
    ll tm = (tl + tr) / 2LL ;
    if (pos <= tm)
    {
        update(v*2, tl, tm, pos, new_val) ;
    }
    else 
    {   update(v*2+1, tm+1, tr, pos, new_val) ;
        t[v] = combine(t[v*2], t[v*2+1]) ;
    }
}


int main()
{
   debugMode();

   return 0 ;
}