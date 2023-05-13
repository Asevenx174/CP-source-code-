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
int co = 0 ;
bool com(ld a,ld b)
{
   double EPS=1e-9 ;
   ld d = ld(a-b) ;
   if(d>EPS){ return true ;}
   return false ;  
}
ld l,w,kk ; 
bool valid(ld i,ld j)
{
   ld x = l-i ;
   ld y = w-j ; 
   ld temp = x*x+y*y ; 
   temp = sqrt(temp) ; 
   if(com(temp,i))
   {
      return false ; 
   }
   kk = temp+i+j ; 
   return true ; 
}
ld calco(ld i)
{
   ld a=0.0,b=w,ans=l+w ; 
   while(a<=b)
   {
      co++ ; 
      ld m = (a+b)/2.0 ; 
      if(valid(i,m))
      {
         ans = kk ; 
         b = b-0.5 ; 
      }
      else
      {
         a = a+0.5 ;  
      }
   }
   return ans ; 
}

int main()
{
   debugMode();
   while(1)
   {
      int a,b ;
      cin >> a >> b ;
      if(a==0 && b==0){break;}
      l = a ; 
      w = b ; 
      ld ans = l+w ;  
      for(ld i=.01;i<=l;i+=.01)
      {
         ld temp = calco(i) ;
         if(com(ans,temp))
         {
            ans = temp ; 
         } 
      }
      printf("%.6Lf\n",ans) ; 
      cout << co << endl ;
   }
   return 0 ;
}