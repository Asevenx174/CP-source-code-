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
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

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
   int test ;
   cin >> test ;
   while(test--)
   {
      string s ;
      cin >> s ;
      int n = s.size() ; 
      int l = 1 , r = n ; 
      int idx = 1 ; 
      for(auto c : s )
      {
         if(c=='0')
         {
            r = idx ; 
            break ; 
         }
         idx++ ; 
      }
      idx = n ; 
      reverse(s.begin(),s.end()) ; 
      for(auto c : s )
      {
         if(c=='1')
         {
            l = idx ; 
            break ; 
         }
         idx-- ; 
      }
      int ans = r-l+1 ; 
      cout << ans << endl ;
   }
   return 0 ;
}