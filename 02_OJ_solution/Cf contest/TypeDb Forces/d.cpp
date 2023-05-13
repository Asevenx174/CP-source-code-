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

bool used[maxx+10] ; 
void sp(ll idx)
{
    ll l2 = xr[idx] ; 
    ll r1 = yr[idx-1] ; 
    ll l3 = xr[idx+1] ; 
    ll r2 = yr[idx] ; 
    if(l3>=r1 && r2>=l2)
    {
       swap(xr[idx],yr[idx]) ; 
    }
    return ; 
}
ll dp[maxx][5] ; 
void solve()
{
  // memset(used,flase,sizeof(used)) ; 
   cin >> n >> s ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   xr[n] = ar[n] ; 
   yr[1] = ar[1] ; 
   //yr[n] = 0 ; 
   //xr[n+1] = 1  ;  
   ll l=0,r=s,ans=0 ; 
   for(int i=2;i<n;i++)
   {
      ll x,y ; 
      if(ar[i]<s)
      {
         x = 0 ; 
         y = ar[i]-x ; 
      }
      else
      {
         x = s ; 
         y = ar[i]-x ;  
      }
      xr[i] = x ; 
      yr[i] = y ; 
   } 
   dp[2][0] = xr[2]*yr[1] ; 
   dp[2][1] = yr[2]*yr[1] ;  
   for(int i=3;i<=n;i++)
   {
      dp[i][0] = min(dp[i-1][0]+xr[i]*yr[i-1],dp[i-1][1]+xr[i]*xr[i-1]) ;  
      dp[i][1] = min(dp[i-1][0]+yr[i]*yr[i-1],dp[i-1][1]+yr[i]*xr[i-1]) ;
   }
   cout << dp[n][0] << endl ;
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