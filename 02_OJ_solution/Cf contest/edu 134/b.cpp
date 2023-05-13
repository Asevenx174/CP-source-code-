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
int ar[maxx+10][maxx+10],n,m,d,sx,sy ; 
int used[maxx+10][maxx+10],lvl[maxx+10][maxx+10] ; 
int main()
{
   debugMode();
   int test,pos=maxx+10 ;
   cin >> test ;
   while(test--)
   {
      pos++ ;
      cin >> n >> m >> sx >> sy >> d ;  
      for(int i=1;i<=n;i++)
      {
         for(int j=1;j<=m;j++)
         {
            int temp = abs(i-sx)+abs(j-sy) ;
            if(temp<=d)
            {
               used[i][j] = pos ; 
            } 
         }
      }
      int a = 0 ; 
      int b = 0 ; 
      for(int i=2;i<=n;i++)
      {
         int add = used[i][1]==pos ? mod : 1 ; 
         a+=add ;
      }
      for(int i=2;i<=m;i++)
      {
         int add = used[n][i]==pos ? mod : 1 ; 
         a+=add ;
      }

      for(int i=2;i<=m;i++)
      {
         int add = used[1][i]==pos ? mod : 1 ; 
         b+=add ;
      }
      for(int i=2;i<=n;i++)
      {
         int add = used[i][m]==pos ? mod : 1 ; 
         b+=add ;
      }
      int temp = min(a,b) ; 
      if(temp>=mod){temp=-1;}
      cout << temp << endl ; 
   }
   return 0 ;
}