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
   ll test ;
   cin >> test ;
   while(test--)
   {
      ll a,b,c,d ; 
      cin >> a >> b >> c >> d ;
      ll xr[10] ;  
      xr[1] = b*c ; 
      xr[2] = a*d ; 
      xr[3] = a*d ;
      xr[4] = b*c ; 
      if(a!=0)
      {
         ll g = __gcd(a,b) ; 
         a = a/g ; 
         b = b/g ; 
      }
      if(c!=0)
      {
         ll g = __gcd(c,d) ; 
         c = c/g ; 
         d = d/g ; 
      }
      ll ans = 2 ; 
      if( ( a==c && b==d ) || (a==0 && c==0) )
      {
         ans = 0 ; 
      }
      else
      {
         if(xr[2]!=0)
         {
            if(xr[1]%xr[2]==0){ans=1;}
         }
         if(xr[4]!=0)
         {
            if(xr[3]%xr[4]==0){ans=1;}
         }
         if(min(a,c)==0){ans=1;}
      }
      cout << ans << endl ;
   }
   return 0 ;
}