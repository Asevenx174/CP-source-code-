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
   int q ;
   cin >> q ;
   while(q--)
   {
      int a ;
      cin >> a ;
      int f = 1 ; 
      int idx = 0 ; 
      int od=0,ev=0,sum=0;
      while(1)
      {
         int temp = 1 << idx ; 
         if(temp>a){break;}
         if( !(a&temp) )
         {
            f = 0 ; 
            sum+=temp ; 
         }
         idx++ ; 
      }
      if(f==0)
      {
         int ans = __gcd(a^sum,a&sum) ; 
         cout << ans << endl ; continue ;
      }
      idx = 0 ; 
      while(1)
      {
         int temp = 1 << idx ; 
         if(temp>a){break;}
         if(idx%2==0)
         {
            ev+=temp ; 
         }
         else
         {
            od+=temp ; 
         }
         idx++ ; 
      }
      int ans = 0 ; 
      if(ev>0 && ev<a)
      {
         int x = __gcd(a^ev,a&ev) ; 
         ans = max(ans,x) ; 
      }
      if(od>0 && od<a )
      {
         int x = __gcd(a^od,a&od) ; 
         ans = max(ans,x) ;
      }
      cout << ans << endl ;
   }
   return 0 ;
}