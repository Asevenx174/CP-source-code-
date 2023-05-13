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
   int x,y,z ; 
   cin >> x >> y >> z ; 
   if(min(x,y)>0)
   {
      if(y>x)
      {
         cout << x << endl ;
      }
      else if(z>y)
      {
         cout << "-1" << endl ;
      }
      else if(z>0)
      {
         cout << x << endl ;
      }
      else
      {
         int temp = x-(z*2) ;
         cout << temp << endl ; 
      }
   }
   else if(max(x,y)<0)
   {
      if(x>y)
      {
         x = -x ; 
         cout << x << endl ;
      }
      else if(z<y)
      {
         cout << "-1" << endl ;
      }
      else if(z<0)
      {
         x = -x ; 
         cout << x << endl ;
      }
      else
      {
         int temp = (-x)+(z*2) ;
         cout << temp << endl ; 
      }
   }
   else
   {
      x = max(x,-x) ; 
      cout << x << endl ;
   }
   return 0 ;
}