#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define pii                pair <int,int>

///%I64d   %Lf
///  ios::sync_with_stdio(0); cin.tie(0); 
/// ar.resize(n+10, vector<int>(m+10)); // 2d vector 
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e6+10,mod=1010,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,m ; 
ll ar[maxx+10] ;
bool ans = false ,dp[mod+5][mod+5][5] ; 
void calco(ll idx,ll sum,ll s)
{
   if(dp[idx][sum][s]){return;}
   if(idx>n)
   {
      if(sum==0 && s==1){ans=true;}
      return ;  
   }
   calco(idx+1,sum,s) ; 
   calco(idx+1,(sum+ar[idx])%m,1) ;
   dp[idx][sum][s] = true ; 
   return ; 
}
int main()
{
   debugMode();
   cin >> n >> m ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
   }
   if(n>m)
   {
      cout << "YES" << endl ; return 0 ; 
   }
   calco(1,0,0) ; 
   if(ans)
   {
      cout << "YES" << endl ;
   }
   else
   {
      cout << "NO" << endl ; 
   }
   return 0 ;
}