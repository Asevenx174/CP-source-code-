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
/// vector<vector<int>> vec( n , vector<int> (m));
using namespace std ;
typedef long long ll ;
typedef long double ld ; 
const int imin = 1e9+100;
const ll maxx =3e5+10,mod=1e9+7,imax=2e9+10,big=1e18+5,qq=1,zz=0,tt=2;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll dp[maxx+10],ar[maxx+10],cr[maxx+10],hr[maxx+10],n,k,cost[maxx+10],pre[maxx+10] ; 
//std::vector < int > v[maxx+10] ;
void solve()
{
   cin >> n >> k ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> ar[i+1] ; 
      pre[i+1] = 0 ; 
   }
   for (int i = 0; i < k; ++i)
   {
      cin >> cr[i+1] ; 
   }
   for (int i = 0; i < k; ++i)
   {
      cin >> hr[i+1] ; 
   }
   
   cost[1] = cr[ ar[1] ] ; 
   for(int i=2;i<n;i++)
   {
      ll add = (ar[i]==ar[i-1]) ? hr[ ar[i] ] : cr[ ar[i] ] ;  
      cost[i] = cost[i-1]+add ; 
   }

   dp[1] = cr[ ar[1] ] ; 
  // cout << dp[1] << endl ;
   pre[ ar[1] ] = 1 ; 
   for(int i=2;i<=n;i++)
   {
      dp[i] = dp[i-1]+(ar[i]==ar[i-1] ? hr[ ar[i] ] : cr[ ar[i] ]) ;  
      ll j = pre[ ar[i] ] ; 
      if(ar[i]==ar[j] && j>zz)
      {  
         ll val = dp[j+1]+max(zz,cost[i-1]-cost[j+1])+hr[ ar[i] ] ; 
         dp[i] = min(dp[i],val) ;  
      }
      pre[ ar[i] ] = i ; 
   }
   cout << dp[n] << endl ;
}
int main()
{
   debugMode();
   ios::sync_with_stdio(0); cin.tie(0);
   ll test = 1 ; 
   cin >> test ; 
   while(test--)
   {
      solve() ; 
   }
   return 0 ;
}