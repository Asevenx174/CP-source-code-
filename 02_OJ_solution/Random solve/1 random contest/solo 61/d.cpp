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
const ll maxx = 110 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int xr[maxx+10],yr[maxx+10] ; 
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      int n,k ;
      cin >> n >> k ; 
      for (int i = 0; i < n ; ++i)
      {
         cin >> xr[i] >> yr[i] ; 
      }
      int ans = -1 ; 
      for (int i = 0; i < n ; ++i)
      {
         int f = 1 ; 
         for (int j = 0; j < n ; ++j)
         {
            int temp = abs(xr[i]-xr[j])+abs(yr[i]-yr[j]) ; 
            if(temp>k){f=0;}
         }
         if(f){ans=1;}
      }
      cout << ans << endl ; 
   }
   return 0 ;
}