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

ll t[4*maxx];
ll ar[maxx+10] ;
bool marked[4*maxx] ;  

void push(ll v)
{
    if (marked[v])
    {
        t[v*2] = t[v*2+1] = t[v];
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}

void update(ll v,ll tl,ll tr,ll l,ll r,ll new_val)
{
    if (l > r) { return ; }
    if (l == tl && tr == r)
    {
        t[v] = new_val;
        marked[v] = true ; // UPDATE CHILD LATER
    }
    else
    {
        push(v); // updates v's child 
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

ll get(ll v,ll tl,ll tr,ll pos)
{
    if (tl == tr) { return t[v]; }
    push(v); // as we are goind deep ,lets updates its child if needed 
    ll tm = (tl + tr) / 2;
    if (pos <= tm) { return get(v*2, tl, tm, pos); }
    return get(v*2+1, tm+1, tr, pos);
}

int main()
{
   debugMode();

   return 0 ;
}