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
int ar[10][10],br[10][10],n ; 
int digit(int x)
{
   int ans = 1 ; 
   while(x>9)
   {
      x = x/10 ; 
      ans++ ; 
   }
   return ans ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      ms(ar,0) ; 
      ms(br,0) ; 
      multiset < int > a,b ; 
      cin >> n ;
      for (int i = 0; i < n ; ++i)
      {
          int x ;
          cin >> x ;
          a.insert(x) ; 
      }
      for (int i = 0; i < n ; ++i)
      {
          int x ;
          cin >> x ;
          auto it = a.find(x) ; 
          if(it!=a.end())
          {
             a.erase(it) ; 
          }
          else
          {
             b.insert(x) ; 
          }
      }
      int ans = 0 ; 
      for(auto x : a )
      {
         if(x<10)
         {
            if(x==1)
            {
              ar[0][1]++ ; 
            }
            else
            {
              ar[1][x]++ ; 
            }
            continue ; 
         }
         int d = digit(x) ;
         ar[1][d]++ ; 
         ans++ ;
      }
      for(auto x : b )
      {
         if(x<10)
         {
            if(x==1)
            {
              br[0][1]++ ; 
            }
            else
            {
              br[1][x]++ ; 
            }
            continue ; 
         }
         int d = digit(x) ;
         br[1][d]++ ; 
         ans++ ;
      }
      for(int i=1;i<10;i++)
      {
         int y = min(ar[1][i],br[1][i]) ; 
         ar[1][i]-=y ;
         br[1][i]-=y ;
         ans+=ar[1][i] ; 
         ans+=br[1][i] ; 
      }
      cout << ans << endl ; 
   }
   return 0 ;
}