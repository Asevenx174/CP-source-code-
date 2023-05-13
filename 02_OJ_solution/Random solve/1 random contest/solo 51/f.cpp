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
const ll maxx = 50+10,mod=1e18+5,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],br[maxx+10],n,m ; 
std::vector < ll > pa,pb,na,nb ;
ll calco(ll x)
{
   ll ans = -mod ; 
   for (int i = 0; i < m ; ++i)
   {
      ll temp = x*br[i] ; 
      ans = max(ans,temp) ; 
   }
   return ans ;
}
int main()
{
   debugMode();
   cin >> n >> m ;
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ;
      if(x>=0)
      {
         pa.push_back(x) ; 
      }
      else
      {
         na.push_back(x) ; 
      }
      ar[i] = x ; 
   }
   for (int i = 0; i < m ; ++i)
   {
      ll x ;
      cin >> x ;
      br[i] = x ;  
   }
   sort(pa.begin(),pa.end()) ;
   sort(na.begin(),na.end()) ; 
   ll ans = mod ; 
   if(pa.size()>1)
   {
      auto it = pa.begin() ; 
      auto lt = pa.rbegin() ; 
      ll temp ; 
      temp = calco(*it) ;
      ans = min(ans,temp) ; 
      temp = calco(*lt) ;   
      ans = min(ans,temp) ;
      it++ ; 
      lt++ ;
      temp = calco(*it) ;
      ans = min(ans,temp) ; 
      temp = calco(*lt) ;   
      ans = min(ans,temp) ;
   }
   if(pb.size()>1)
   {
      auto it = na.begin() ; 
      auto lt = na.rbegin() ;  
      ll temp ; 
      temp = calco(*it) ;
      ans = min(ans,temp) ; 
      temp = calco(*lt) ;   
      ans = min(ans,temp) ;
      it++ ; 
      lt++ ;
      temp = calco(*it) ;
      ans = min(ans,temp) ; 
      temp = calco(*lt) ;   
      ans = min(ans,temp) ;
   }
   cout << ans << endl ;
   return 0 ;
}