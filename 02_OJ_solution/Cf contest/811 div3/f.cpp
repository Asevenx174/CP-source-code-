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
const ll maxx = 2e5+10,mod=1e18+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,val ; 
std::vector< ll > pq ;
ll hr[maxx+10],pr[maxx+10],dp[maxx+10] ; 
ll calco(ll l)
{
   if(dp[l]!=-1){return dp[l];}
   if(l==n){ return 0 ; }
   if(l>n){return mod ;}
   ll r = l+1 ; 
   ll add = (hr[r]-hr[l])*(hr[r]-hr[l])+val+calco(r) ;
   ll ans = add ;   
   while(r+1<=n && val>= ( 2*(hr[r+1]-hr[r])*(hr[r]-hr[l]) ) ) 
   {
         r++ ; 
         add = (hr[r]-hr[l])*(hr[r]-hr[l])+val+calco(r) ;
         ans = min(ans,add) ;  
   } 
   return dp[l] = ans ; 
}
int main()
{
   debugMode();
   memset(dp,-1,sizeof(dp)) ; 
   ll sum = 0 ; 
   cin >> n >> val ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> hr[i+1] ; 
      sum+=hr[i+1] ; 
      pr[i+1] = sum ; 
      pq.push_back(sum) ; 
   }
   ll ans = calco(1) ;  
   cout << ans << endl ;
   return 0 ;
}