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
const ll maxx = 3010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],n,dp[maxx+10][maxx+10] ; 
std::vector < ll > k  ;
ll calco(int a,int b)
{
   if(dp[a][b]!=-1){return dp[a][b]; }
   if(b>n){return -mod;}
   if(b==n)
   {
      return 0 ; 
   }
   ll sum = -mod  ; 
   ll p = ar[b]-ar[a] ;  
   ll need = ar[b]+p ; 
   auto it = lower_bound(k.begin(),k.end(),need) ; 
   if(it!=k.end())
   {
      ll idx = it-k.begin()+1 ; 
      sum = max(sum,calco(b,idx)+1) ; 
   }
   sum = max(sum,calco(a,b+1)) ;
   return dp[a][b] = sum ;
}
int main()
{
   debugMode();
   for (int i = 0; i < maxx ; ++i)
   {
      for (int j = 0; j < maxx ; ++j)
      {
         dp[i][j] = -1 ; 
      }
   }
   ll sum = 0 ; 
   cin >> n ; 
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ; 
      sum+=x ; 
      ar[i+1] = sum ; 
      k.push_back(sum) ; 
   }
   ll ans = 0 ; 
   for(int i=1;i<=n;i++)
   {
      ll temp = calco(0,i)+1 ; 
      ans = max(ans,temp) ;
   }
   ans = n-ans ; 
   cout << ans << endl ;
   return 0 ;
}