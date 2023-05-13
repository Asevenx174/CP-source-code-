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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,s,xr[maxx+10],yr[maxx+10] ; 
ll calco(ll ex)
{
   for(int i=2;i<n;i++)
   {
      ll x = ar[i]-s+ex ; 
      ll y = ar[i]-x ; 
      xr[i] = x ; 
      yr[i] = y ; 
   }
   ll ans = 0 ; 
   for(int i=1;i<n;i++)
   {
      ll add = yr[i]*xr[i+1] ; 
      ans+=add ; 
   }
   return ans ; 
}
void solve()
{
   cin >> n >> s ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   xr[n] = ar[n] ; 
   yr[1] = ar[1] ; 
   ll l=0,r=s,ans=0 ; 
   while(l<=r)
   {
      ll mid = (l+r)/tt ; 
      ll val = calco(mid) ;
      if(val>ans)
      {
         ans = val ; 
      }
      else
      {
         
      }
   }
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