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
ll ar[maxx+10],br[maxx+10] ; 
int main()
{
   debugMode();
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll n,l,r,f=1 ;
      cin >> n >> l >> r ; 
      for( ll i=1;i<=n ;i++)
      {
         ll x = r/i ; 
         x = x*i ; 
         if(x<l){f=0;}
         br[i] = x ; 
      }
      if(f==0){ cout << "NO" << endl ; continue ; }
      cout <<  "YES" << endl ; 
      for (int i = 0; i < n ; ++i)
      {
         if(i>0){cout << " " ; }
         cout << br[i+1] ; 
      }
      cout << endl ;
   }
   return 0 ;
}