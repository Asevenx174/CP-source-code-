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
int ar[maxx+10] ; 
int main()
{
   debugMode();
   string s ;
   cin >> s ;
   int idx = 1 ; 
   for(auto c : s )
   {
      int x = c=='1' ? 1 : 0 ; 
      ar[idx++] = x ; 
   }
   int ans = 0 ; 
   idx = 1 ; 
   int n = s.size() ; 
   while(idx<=n)
   {
      if(ar[idx]==1)
      {
         while(idx+1<=n && ar[idx+1]==1){idx++;}
         ans++ ; 
      }
      else
      {  
         while(idx+1<=n && ar[idx+1]==0){idx++;}
         if(idx<n){ans++;}
      } 
      idx++ ; 
   }
   cout << ans << endl ;
   return 0 ;
}