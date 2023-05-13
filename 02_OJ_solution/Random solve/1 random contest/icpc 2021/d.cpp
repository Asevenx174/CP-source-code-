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
bool com(ld a,ld b)
{
   double EPS=1e-9 ;
   ld d = ld(a-b) ;
   if(d>EPS){ return true ;}
   return false ;  
}
int main()
{
   //debugMode();
   while(1)
   {
      int a,b ;
      cin >> a >> b ; 
      if(a==0 && b==0){break;}
      ld l = a ; 
      ld w = b ; 
      ld ans = (ld)(l+w) ; 
      ld x,y ; 
      for(ld i=1.0;i<=l;i+=0.1)
      {
         for(ld j=0.0;j<=w;j+=0.1)
         {
            x = l-i ; 
            y = w-j ; 
            ld temp = x*x+y*y ; 
            ld rc = sqrt( (ld) temp ) ; 
            if(com(rc,ld(i))){continue;}
            ld sum = rc ; 
            sum+=ld(i) ; 
            sum+=ld(j) ; 
            if(com(ans,sum))
            {
               ans = sum ; 
            }
         }
      }
      //cout << x << " " << y << endl ; 
      printf("%.6Lf\n",ans) ; 
   }
   return 0 ;
}