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
int main()
{
   debugMode();
   set < int > s ; 
   int n,k ;
   cin >> n >> k ; 
   for (int i = 0; i < k ; ++i)
   {
      int x ;
      cin >> x ;
      s.insert(x) ; 
   }
   int idx = 0 ; 
   int ans = 0 ; 
   while(n>0)
   {
      auto it = s.upper_bound(n) ; 
      it-- ; 
      int x = *it ; 
      if(idx%2==0){ans+=x;}
      n-=x ; 
      idx++ ; 
   }
   cout << ans << endl ;
   return 0 ;
}