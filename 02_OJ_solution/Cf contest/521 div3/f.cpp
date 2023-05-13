#include<bits/stdc++.h>
#define pf printf
#define ff first
#define ss second
#define sef second.first
#define ses second.second
#define ms(a,b)            memset(a, b, sizeof(a))
#define lp(i,a,b) for (int i = a; i <= b; i++)
#define pii                pair <int,int>

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
ll n,ar[maxx+10] ; 
int main()
{
   debugMode();
   map < int ,int > pq ; 
   set < int > s ;  
   cin >> n ; 
   lp(i,1,n)
   {
      ll x ;
      cin >> x ;
      pq[x]++ ; 
      s.insert(x) ; 
   }
   std::vector < ll > v ; 
   for( auto x : s )
   {
      v.push_back(pq[x]) ; 
   }
   sort(v.begin(),v.end()) ;  
   ll ans = 0 ; 
   for( ll x = 1 ; x<=n ; x++ )
   {
      ll t = x ,sum = 0  ; 
      auto lt = lower_bound(v.begin(),v.end(),x) ;
      if(lt==v.end()){break;}   
      do
      {
         lt++ ; 
         sum+=t ; 
         t=t*2LL ; 
         auto it = lower_bound(lt,v.end(),t) ;
         if(it==v.end()){break;}
         lt = it ; 
      }
      while(1) ; 
      ans = max(ans,sum) ; 
   }
   cout << ans << endl ;
   return 0 ;
}