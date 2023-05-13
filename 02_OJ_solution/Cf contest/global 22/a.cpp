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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ll ar[maxx+10],br[maxx+10],n ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ll sum = 0 ; 
      std::vector < ll > v[5] ;
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> ar[i+1] ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         cin >> br[i+1] ; 
         sum+=br[i+1] ; 
         v[ ar[i+1] ].push_back(br[i+1]) ; 
      } 
      if( v[0].empty() || v[1].empty() )
      {
         cout << sum << endl ; continue ; 
      }
      sort(v[0].begin(),v[0].end(),greater<ll>());
      sort(v[1].begin(),v[1].end(),greater<ll>());
      int p=0,q=1 ;
      if(v[0][0]>v[1][0])
      {
         swap(p,q) ; 
      }
      auto it = v[q].begin() ; 
      auto lt = v[p].begin() ; 
      int idx = n ; 
      while(idx>0)
      {
         if(it!=v[q].end())
         {
            br[idx] = *it ; 
            ar[idx--] = 1 ; 
            it++ ;
         }
         if(lt!=v[p].end())
         {
            br[idx] = *lt ; 
            ar[idx--] = 0 ; 
            lt++ ; 
         }
      }
      ll ans = br[1],res=0 ;
      if(1<n-1)
      {
         res = br[1] ; 
      } 
      for(int i=2;i<=n;i++)
      {
         ll add = ar[i]!=ar[i-1] ? 2LL*br[i] : br[i] ; 
         ans+=add  ; 
         if(i<n-1)
         {
            res+=add ; 
         }
      }
      swap(br[n],br[n-1]) ;
      swap(ar[n],ar[n-1]) ;
      ll add = ar[n]!=ar[n-1] ? 2LL*br[n] : br[n] ;
      res+=add ; 
      n-- ; 
      add = ar[n]!=ar[n-1] ? 2LL*br[n] : br[n] ;
      res+=add ; 
      ans = max(ans,res) ; 
      cout << ans << endl ; 
   }
   return 0 ;
}