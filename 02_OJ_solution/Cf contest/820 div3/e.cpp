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
int n,xr[maxx+10],yr[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
         cin >> xr[i+1] ; 
      }
      for (int i = 0; i < n ; ++i)
      {
         cin >> yr[i+1] ; 
      }
      std::vector < int > v ;
      std:: multiset < int > p,q ;
      for (int i = 0; i < n ; ++i)
      {
         int x = yr[i+1]-xr[i+1] ; 
         if(x>=0)
         {
            v.push_back(x) ; 
            p.insert(x) ; 
         }
         else
         {
            q.insert(-x) ; 
         }
      } 
      int ans = 0 ; 
      sort(v.begin(),v.end()) ; 
      for(auto x : v)
      {
          auto kt = q.upper_bound(x) ; 
          if(kt!=q.begin())
          {
             kt-- ; 
             int y = *kt ; 
             p.erase(p.find(x)) ; 
             q.erase(q.find(y)) ; 
             ans++ ; 
          } 
      }
      int left = p.size() ; 
      ans+=(left/2) ; 
      cout << ans << endl ;
   }
   return 0 ;
}