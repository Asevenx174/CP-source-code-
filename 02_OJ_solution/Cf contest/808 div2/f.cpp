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
const ll maxx = 1010 ,mod=1e9+7,imax=2e9+10,qq=1,zz=0;

inline void debugMode() 
{
#ifndef ONLINE_JUDGE

freopen("input.txt", "r", stdin);

freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
}
int ar[maxx+5][maxx+5],br[maxx+5][maxx+5],n ; 
void shift(int i,int s)
{
   for(int j=1;j<=n;j++ )
   {
      if(s==1)
      {
         ar[i][j]=1-ar[i][j] ; 
      }
      else
      {
         ar[j][i]=1-ar[j][i] ; 
      }
   }
}
bool check(int i,int s)
{
   for(int j=1;j<=n;j++ )
   {
      if(s==1)
      {
         if(ar[i][j]!=br[i][j]){ return false ;}
      }
      else
      {
         if(ar[j][i]!=br[j][i]){ return false ;}
      }
   }
   return true ; 
}
bool change(int i,int s)
{
   for(int j=1;j<=n;j++ )
   {
      if(s==1)
      {
         if(ar[i][j]!=br[i][j]){ shift(j,1-s); }
      }
      else
      {
         if(ar[j][i]!=br[j][i]){ shift(j,1-s) ;}
      }
   }
   return true ; 
}
int main()
{
   debugMode();
   int test ;
   cin >> test ;
   while(test--)
   {
      cin >> n ; 
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ;
         int j = 0 ; 
         for(auto c : s )
         {
            int x = c=='1' ? 1 : 0 ; 
            ar[i+1][j+1] = x ; 
            j++ ; 
         }
      }
      for (int i = 0; i < n ; ++i)
      {
         string s ;
         cin >> s ;
         int j = 0 ; 
         for(auto c : s )
         {
            int x = c=='1' ? 1 : 0 ; 
            br[i+1][j+1] = x ; 
            j++ ; 
         }
      }
      for(int r=1;r<=n;r++)
      {
         if(!check(r,1))
         {
            shift(r,1);
            change(r,1);
         }
      }
      int f = 1 ; 
      for (int i = 0; i < n ; ++i)
      {
         if(!check(i+1,1))
         {
            f = 0 ; 
         }
      }
      if(f==1)
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