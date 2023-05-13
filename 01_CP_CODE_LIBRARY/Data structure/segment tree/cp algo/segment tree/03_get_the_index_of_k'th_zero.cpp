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

ll find_kth(ll v,ll tl,ll tr,ll k)
{
    if (k > t[v]) { return -1 ; } 
    if (tl == tr) { return tl ; } // GOT THE K'TH INDEX
    ll tm = (tl + tr) / 2LL ;
    if (t[v*2] >= k) { return find_kth(v*2, tl, tm, k) ; }
    return find_kth(v*2+1, tm+1, tr, k - t[v*2]) ;
}


int main()
{
   debugMode();

   return 0 ;
}