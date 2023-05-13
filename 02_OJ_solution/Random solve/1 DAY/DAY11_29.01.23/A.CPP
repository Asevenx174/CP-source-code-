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

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 

using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,x ; 
ll andOperator(ll x, ll y)
{
    // Iterate over all bits of y, starting from the lsb, if it's equal to 1, flip it
    for(ll i=0;i<65LL;i++)
    {
        //repeat till x >= y, otherwise return the answer.
        ll mask = qq << i ; 
        if (y <= x) 
        {
            return y;
        }
        ll val = (y&mask) ; 
        if ( val ) 
        {
            y &= ~mask ; 
        }
    }
    return y;
}
void solve()
{
   cin >> n >> x ; 
   if( (n&x)!=x){ cout << "-1" << endl ; return ; }
   ll l=n,r=5e18,ans=-1 ; 
   while(l<=r)
   {
      ll m = (l+r)/tt ; 
      ll val = andOperator(n,m) ; 
      if(val<x)
      {
         r = m-qq ; 
      }
      else if(val>x)
      {
         l = m+qq ;  
      } 
      else
      {
         //cout << m << endl ;
         ans = m ; 
         r = m-qq ; 
      }
   }
   cout << ans << endl ;
}
int main()
{
   debugMode();
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}