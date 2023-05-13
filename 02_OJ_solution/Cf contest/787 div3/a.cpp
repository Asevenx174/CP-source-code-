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
      int a,b,c,x,y ;
      cin >> a >> b >> c >> x >> y ;
      int p = min(x,a) ; 
      int q = min(y,b) ; 
      int need = x-p ; 
      int add = min(need,c) ; 
      p+=add ; 
      c-=add ;
      need = y-q ; 
      add = min(need,c) ; 
      q+=add ;
      if(p==x && q==y)
      {
         cout << "YES" << endl ;
      } 
      else
      {
         cout << "NO" << endl ;
      }
   }
   return 0 ;
}