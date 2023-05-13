
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

ll t[4*maxx],lazy[4*maxx];
ll ar[maxx+10] ; 

void push(ll v)
{
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v]; // pass to left child 
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v]; // pass to right child 
    lazy[v] = 0; // done 
}

void update(ll v,ll tl,ll tr,ll l,ll r,ll addend)
{
    if (l > r) { return ; }
    if (l == tl && tr == r)
    {
        t[v] += addend;
        lazy[v] += addend;
    } 
    else 
    {
        push(v);
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

ll query(ll v,ll tl,ll tr,ll l,ll r) // get the max value of a range 
{
    if (l > r) { return -imax ; } 
    if (l <= tl && tr <= r) { return t[v]; } 
    push(v);
    ll tm = (tl + tr) / 2 ;
    ll lc = query(v*2, tl, tm, l, min(r, tm)) ; 
    ll rc = query(v*2+1, tm+1, tr, max(l, tm+1), r) ; 
    return max(lc,rc) ; 
}


int main()
{
   debugMode();

   return 0 ;
}