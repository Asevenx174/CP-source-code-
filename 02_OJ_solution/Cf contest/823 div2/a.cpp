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
const ll maxx = 100+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int f[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n,c ;
      cin >> n >> c ; 
      memset(f,0,sizeof(f)) ; 
      for (int i = 0; i < n ; ++i)
      {
         int x ;
         cin >> x ;
         f[x]++ ; 
      }
      std::vector < int > v ;
      for (int i = 0; i < maxx ; ++i)
      {
         if(f[i]>0)
         {
            v.push_back(f[i]) ; 
         }
      }
      int ans = 0 ; 
      for(auto x : v )
      {
         int add = min(x,c) ; 
         ans+=add ; 
      }
      cout << ans << endl ; 
   }
   return 0 ;
}