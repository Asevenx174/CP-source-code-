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
      string s,t ;
      cin >> s >> t ;
      if(t=="a")
      {
         cout << "1" << endl ; continue ; 
      }
      int n = t.size() ; 
      if(n==1)
      {
         ll ans = 1 ; 
         ll len = s.size() ; 
         while(len--)
         {
            ans = ans*2LL ;
         }
         cout << ans << endl ;
      }
      else
      {
         int f = 0 ;
         for(auto c : t )
         {
            if(c=='a'){f=1;}
         }
         if(f==1){cout << "-1" << endl ; continue ; }
         ll ans = 1 ; 
         ll len = s.size() ; 
         while(len--)
         {
            ans = ans*2LL ;
         }
         cout << ans << endl ;
      }
   }
   return 0 ;
}