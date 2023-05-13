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
const ll maxx = 2e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll n,m,br[maxx+10],ar[maxx+10] ; 
std::vector < ll > v ;
ll calco(ll idx)
{
   map < ll ,ll > pq ; 
   //pq[0]++ ; 
   ll sum = 0 ;  
   ll ans = 0 ; 
   for (int i = 0; i < n ; ++i)
   {
      sum+=v[i] ;
      if(i>=idx)
      {
         ll sub = sum ; 
         ans+=pq[sub] ; 
         sub = sum-1 ; 
         ans+=pq[sub] ; 
         cout << i+1 << " " << pq[sum] << " " << pq[sum-1] << endl ;
      } 
      else { pq[sum]++ ; }  
   }
   return ans ; 
}
int main()
{
   debugMode();
   ll idx = 0 ; 
   cin >> n >> m ;
   for (int i = 0; i < n ; ++i)
   {
      ll x ;
      cin >> x ;
      ar[i+1] = x ; 
      if(x==m)
      {
         idx = i+1 ; 
      }
   }
   int sum = 0 ; 
   for(int i=idx+1;i<=n;i++)
   {
      if(ar[i]>m){sum++;}else{sum--;}
      br[i] = sum ; 
   }
   sum = 0 ; 
   for(int i=idx-1;i>0;i--)
   {
      if(ar[i]>m){sum++;}else{sum--;}
      br[i] = sum ; 
   }
   for (int i = 0; i < n ; ++i)
   {
     // cout << i+1 << " " << br[i+1] << endl ;
      v.push_back(br[i+1]);
   }
   ll ans = calco(idx-1) ; 
   reverse(v.begin(),v.end()) ; 
   //ll temp = calco(n-idx) ; 
   //ans+=temp ; 
   cout << ans << endl ;
   return 0 ;
}