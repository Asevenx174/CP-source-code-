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
typedef long  double ld ; 
const int imin = 1e9+100;
const ll maxx = 1e5+10,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int n,xr[maxx+10],tr[maxx+10] ;
int res ;
int valid(int g,ld xo)
{
   //cout << g << endl ;
   for(int i=1;i<=n;i++)
   {
      ld sum = (ld)tr[i] ; 
      ld x = (ld)xr[i] ; 
      sum+=abs(x-xo) ; 
      int temp = int (ceil(sum) ) ; 
      if(temp>g)
      {
         if(xo>x){return 2;}
         return 3 ; 
      }
   }
   res = min(res,xo) ; 
   return 1 ; 
}
bool limit(int g)
{
   ld l=0,r=res ; 
   while(l<=r)
   {
      //cout << g << endl ;
      ld m = (l+r)/2.0 ; 
      int val = valid(g,m) ; 
      if(val==1)
      {
         return true ; 
      }
      else if(val==2)
      {
         r = m-1.0 ; 
      }
      else
      {
         l = m+1.0 ; 
      }
   }
   return false ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      res = 0 ; 
   cin >> n ;
   int l=0,r=mod ; 
   for (int i = 0; i < n ; ++i)
   {
      cin >> xr[i+1] ; 
      res = max(res,xr[i+1]) ; 
   }
   cout << res << endl ;
   for (int i = 0; i < n ; ++i)
   {
      cin >> tr[i+1] ; 
   }
   while(l<=r)
   {
      int m = (l+r)/2 ; 
      if(limit(m))
      {
         r = m-1 ; 
      }
      else
      {
         l = m+1 ; 
      }
   }
   cout << res << endl ;
   }
   return 0 ;
}