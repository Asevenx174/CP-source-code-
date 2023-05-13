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
const ll maxx = 100+5,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll dp[maxx+5][maxx+15] ; 

ll nCr(ll n,ll r)
{
    if(dp[n][r]!=-1){ return dp[n][r];}
    if(n==r) return dp[n][r] = 1;
    if(r==0) return dp[n][r] = 1;
    if(r==1) return dp[n][r] = (ll)n;
    //if(dp[n][r]) return dp[n][r];
    return dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}
void precom()
{
   for (int i = 0; i < maxx ; ++i)
   {
      for (int j = 0; j < maxx ; ++j )
      {
         dp[i][j] = -1 ; 
      }
   }
   for (int i = 0; i < maxx ; ++i)
   {
      for (int j = 0; j < maxx ; ++j )
      {
         int temp = nCr(i,j) ; 
         dp[i][j] = temp ; 
      }
   }
}
int n ; 
int rev(int i)
{
   return (n-i+1) ; 
}
ll get(ll p,ll r)
{
   cout << p << " " << r << " " << dp[p][r] << endl ;
   ll ans = max(qq,dp[p][r]) ; 
   return ans ; 
}
ll calco(ll x,ll y,ll z,ll i,ll j,ll k)
{ 
   cout << x << " " << y << " " << z << " " << i << " " << j << " " << k << endl ;
   if(x<i || y<j || (k-j)>(z-y) || (j-i)>(y-x) ){return 0;}
   ll ans = get(x-qq,i-qq)%mod ; 
   ans = (ans*get(y-x-qq,j-i-qq))%mod ; 
   ans = (ans*get(z-y-qq,k-j-qq))%mod ;
   if(k<n)
   {
     // ans = (ans+qq)%mod ;
   }
   return ans ;  
}


void solve()
{
   int i,j,x,y ;
   cin >> n >> i >> j >> x >> y ; 
   if(x>y)
   {
      i = rev(i) ;
      j = rev(j) ; 
      swap(i,j) ; 
      swap(x,y) ;    
   }
   // cout << i << " " << j << endl ;
    //cout << x << " " << y << endl ;
   int z = n ; 
   ll ans = 0 ; 
   if(y==n)
   {
     // cout << x << " " << y << " " << z << " " << i << " " << j << " " << j << endl ;
      ans=calco(x,y,z,i,j,j) ; 
   }
   else
   {
      for(int k=j+1;k<=n;k++)
      {
         ans= (ans+calco(x,y,z,i,j,k))%mod ; 
      }
   }
   cout << ans << endl ; 
}
int main()
{
   debugMode();
   precom() ; 
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}