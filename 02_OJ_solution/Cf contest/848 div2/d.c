#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std ;
typedef long long ll ;
typedef float ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;
const ld con = 30 ,vt=1 ; 
inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
ld calco(ld g,ld d)
{
   ld ids = 0 ; 
   if(d<g-vt)
   {
      // resistive region 
      ids = con*1.0*( (g-vt)*d- ((d*d)/2.0) ) ; 
   }
   else
   {
      // sarutaion 
      ids = (con/2.0)*(g-vt)*(g-vt) ; 
   }
   return ids ; 
}
int main()
{
   debugMode();
   ld grid[30][30] ; 
   for(int vgs=1;vgs<=5;vgs++)
   {
      for(int vds=0;vds<=20;vds++)
      {
         ld ids = calco(vgs,vds) ; 
         grid[vds][vgs] = ids ; 
         //printf(" %.0f",ids) ; 
      }
      //cout << '\n'  ;
   }
   for(int vds=0;vds<=20;vds++)
   {
       int idx = 1 ; 
       for(int vgs=1;vgs<=5;vgs++)
       {
          ld temp = grid[vds][idx++] ;   
          printf(" %.0f",temp) ; 
       }
       printf("\n") ; 
   }
   return 0 ;
}